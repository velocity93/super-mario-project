////////////////////////////////////////////////////////////////////////
// MonsterOccurrence.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ResourceManager.hpp"
#include "CollisionManager.hpp"
#include "Block.hpp"
#include "MonsterOccurrence.hpp"
#include "Monster.hpp"
#include "Pipe.hpp"
#include "Perso.hpp"

using namespace SuperMarioProject;

namespace Collisions
{
	MonsterOccurrence::MonsterOccurrence(
		Monster* monster,
		const string& textureName, 
		const Vector2f& position,
		const Vector2f& speed,
		MonsterOccurrence::State state,
		MonsterOccurrence::Side side,
		map<MonsterOccurrence::State, int>& nbSpritesByState,
		map<MonsterOccurrence::State, int>& frameDelayByState)
			: EntityMovable(textureName, position, speed, side), _initialPosition(position), _state(state)
	{
		_monster = monster;

		// Animation
		_animation.setMapFrameDelay(frameDelayByState);
		_animation.setMapNbSprites(nbSpritesByState);
		_animation.setCurrentState(state);

		// Hitbox Definition
		_deltaX = _monster->getBottomLeft();
		updatePositions(position.x, position.y);
		_hitboxSize.x = _texture->getImage()->GetWidth() / _animation.getNbSpritesMax() - 2 * _deltaX;
		_hitboxSize.y = _texture->getImage()->GetHeight() / M_NB_STATES;
	}

	MonsterOccurrence::State MonsterOccurrence::getState()
	{
		return _state;
	}

	void MonsterOccurrence::setState(State state)
	{
		_state = state;
		_animation.setCurrentState(state);
	}

	Monster* MonsterOccurrence::getModel()
	{
		return _monster;
	}

	void MonsterOccurrence::onCollision(Collisionable* c, vector<bool>& infos)
	{
		/* Collision vs Block */
		BlockOccurrence* block = dynamic_cast<BlockOccurrence*>(c);
		if(block != NULL)
		{
			return onCollision(block, infos);
		}

		/* Collision vs Perso */
		Perso* perso = dynamic_cast<Perso*>(c);
		if(perso != NULL)
		{
			return onCollision(perso, infos);
		}

		/* Collision vs Projectile */
		ProjectileOccurrence* projectileOccurrence = dynamic_cast<ProjectileOccurrence*>(c);
		if(projectileOccurrence != NULL)
		{
			return onCollision(projectileOccurrence);
		}

		/* Collision vs Pipe */
		Pipe* pipe = dynamic_cast<Pipe*>(c);
		if(pipe != NULL)
		{
			return onCollision(pipe, infos);
		}
	}

	void MonsterOccurrence::onCollision(BlockOccurrence* block, vector<bool>& infos)
	{
		if(infos[CollisionManager::FROM_LEFT] && (block->getActualModel()->getPhysic() & BlocksConstants::RIGHT_WALL))
		{
			updatePositions(block->getHitboxPosition().x + block->getHitboxSize().x, _hitboxPosition.y);
			_speed.x *= -1;
			_side = RIGHT_SIDE;
		}

		if(infos[CollisionManager::FROM_TOP] && (block->getActualModel()->getPhysic() & BlocksConstants::ROOF))
		{
			updatePositions(_hitboxPosition.x, block->getHitboxPosition().y - _hitboxSize.y);
			_speed.y = 0;
		}

		if(infos[CollisionManager::FROM_RIGHT] && (block->getActualModel()->getPhysic() & BlocksConstants::LEFT_WALL))
		{
			updatePositions(block->getHitboxPosition().x - _hitboxSize.x, _hitboxPosition.y);
			_speed.x *= -1;
			_side = LEFT_SIDE;
		}

		if(infos[CollisionManager::FROM_BOTTOM] && (block->getActualModel()->getPhysic() & BlocksConstants::GROUND))
		{
			updatePositions(_hitboxPosition.x, block->getHitboxPosition().y + block->getHitboxSize().y);
		}
	}

	void MonsterOccurrence::onCollision(Pipe* pipe, vector<bool>& infos)
	{
		if(infos[CollisionManager::FROM_BOTTOM])
		{
			updatePositions(_position.x, pipe->getHitboxPosition().y + pipe->getHitboxSize().y);
		}

		if(infos[CollisionManager::FROM_TOP])
		{
			updatePositions(_position.x, pipe->getHitboxPosition().y - _hitboxSize.y);
		}

		if(infos[CollisionManager::FROM_LEFT])
		{
			updatePositions(pipe->getHitboxPosition().x + pipe->getHitboxSize().x, _position.y);
		}

		if(infos[CollisionManager::FROM_RIGHT])
		{
			updatePositions(pipe->getHitboxPosition().x - pipe->getHitboxSize().x, _position.y);
		}
	}
	
	void MonsterOccurrence::onCollision(ProjectileOccurrence* projectileOccurrence)
	{
		if(projectileOccurrence->getSender() == ProjectileOccurrence::GENTILE)
		{
			/* Launch Dead animation, but for the moment.... */
			setState(M_DEAD);
			_monster->removeMonsterOccurrence(this);
		}
	}
	
	void MonsterOccurrence::onCollision(Perso* , vector<bool>& infos)
	{
		if(infos[CollisionManager::FROM_TOP] && _monster->canBeJumpedOn())
		{
			if(_monster->canBeKilledByJump())
				setState(M_DEAD);
			else
				setState(M_RETRACTED);
		}
	}

	void MonsterOccurrence::updatePhysicData(float time, RenderWindow& app)
	{
		setActivity(app);

		if(_isActive)
		{
			gravity(_speed, time);

			/* Update physic position */
			/* Save actual position in previous prosition */
			_previousHitboxPosition = _hitboxPosition;
			_previousPosition = _position;

			/* Compute new position */
			updatePositions(_hitboxPosition.x + time * _speed.x, _hitboxPosition.y + time * _speed.y);

			/* If it falls in hole */
			if(_hitboxPosition.y < 0)
				updatePositions(_hitboxPosition.x, 0);

			if(_hitboxPosition.y + _hitboxSize.y < 0)
				_monster->removeMonsterOccurrence(this);
		}
	}

	void MonsterOccurrence::updateGraphicData(RenderWindow&)
	{
		if(_isActive)
			_animation.update();
	}

	void MonsterOccurrence::render(RenderWindow& app)
	{
		if(_isActive)
		{
			/* Update animation data */
			int delta = 0;
			if(_state != M_WALK)
			{
				delta = !_monster->canBeKilledByJump() + !_monster->canBeKilledByFire();
			}
			_animation.render(_texture, app, _position, _side == LEFT_SIDE, delta);
		}
	}

	void MonsterOccurrence::setActivity(RenderWindow& app)
	{
		const View& view = app.GetDefaultView();

		if(_hitboxPosition.x > view.GetCenter().x + view.GetHalfSize().x
			|| _hitboxPosition.x + _hitboxSize.x < view.GetCenter().x - view.GetHalfSize().x
			|| _hitboxPosition.y > view.GetCenter().y + view.GetHalfSize().y
			|| _hitboxPosition.y + _hitboxSize.y < view.GetCenter().y - view.GetHalfSize().y)
		{
			
			if(this->_initialPosition.x < view.GetCenter().x - view.GetHalfSize().x
			|| this->_initialPosition.x + _hitboxSize.x < view.GetCenter().x + view.GetHalfSize().x
			|| this->_initialPosition.y > view.GetCenter().y + view.GetHalfSize().y
			|| this->_initialPosition.y + _hitboxSize.y < view.GetCenter().y - view.GetHalfSize().y)
			{
				/* If view pass monster's initial position, we put monster as the beginning of the level */
				_position = _previousPosition = _initialPosition;
				setState(M_WALK);
				_speed.x = -MonsterConstants::MONSTER_SPEED_X;
				_side = LEFT_SIDE;
			}

			_isActive = false;
		}
		else
			_isActive = true;

	}

    MonsterOccurrence::~MonsterOccurrence()
    {		
    }
} // namespace
