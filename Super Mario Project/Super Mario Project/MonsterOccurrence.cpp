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
			: EntityMovable(textureName, position, speed, side), _initialPosition(position), _state(state), _animation(NB_STATES)
	{
		_monster = monster;

		// Animation
		_animation.setMapFrameDelay(frameDelayByState);
		_animation.setMapNbSprites(nbSpritesByState);
		_animation.setCurrentState(state);

		// Hitbox Definition
		_deltaX = _monster->getBottomLeft();
		updatePositions(position.x, position.y);
		_hitboxSize.x = _texture->getSize().x / _animation.getNbSpritesMax() - 2 * _deltaX;
		_hitboxSize.y = _texture->getSize().y / _animation.getNbStates();
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

	void MonsterOccurrence::onCollision(Collisionable* c, int collision_type)
	{
		/* Collision vs Block */
		BlockOccurrence* block = dynamic_cast<BlockOccurrence*>(c);
		if(block != NULL)
		{
			return onCollision(block, collision_type);
		}

		/* Collision vs Perso */
		Perso* perso = dynamic_cast<Perso*>(c);
		if(perso != NULL)
		{
			return onCollision(perso, collision_type);
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
			return onCollision(pipe, collision_type);
		}
	}

	void MonsterOccurrence::onCollision(BlockOccurrence* block, int collision_type)
	{
		CollisionManager::Type type = static_cast<CollisionManager::Type>(collision_type);

		if(type == CollisionManager::FROM_LEFT && (block->getActualModel()->getPhysic() & BlocksConstants::RIGHT_WALL))
		{
			updatePositions(block->getHitboxPosition().x + block->getHitboxSize().x, _hitboxPosition.y);
			_speed.x *= -1;
			_side = RIGHT_SIDE;
		}

		if(type == CollisionManager::FROM_TOP && (block->getActualModel()->getPhysic() & BlocksConstants::ROOF))
		{
			updatePositions(_hitboxPosition.x, block->getHitboxPosition().y - _hitboxSize.y);
			_speed.y = 0;
		}

		if(type == CollisionManager::FROM_RIGHT && (block->getActualModel()->getPhysic() & BlocksConstants::LEFT_WALL))
		{
			updatePositions(block->getHitboxPosition().x - _hitboxSize.x, _hitboxPosition.y);
			_speed.x *= -1;
			_side = LEFT_SIDE;
		}

		if(type == CollisionManager::FROM_BOTTOM && (block->getActualModel()->getPhysic() & BlocksConstants::GROUND))
		{
			updatePositions(_hitboxPosition.x, block->getHitboxPosition().y - _hitboxSize.y);
			_speed.y = 0;
		}
	}

	void MonsterOccurrence::onCollision(Pipe* pipe, int collision_type)
	{
		CollisionManager::Type type = static_cast<CollisionManager::Type>(collision_type);

		if(type == CollisionManager::FROM_BOTTOM)
		{
			updatePositions(_position.x, pipe->getHitboxPosition().y + pipe->getHitboxSize().y);
		}

		if(type == CollisionManager::FROM_TOP)
		{
			updatePositions(_position.x, pipe->getHitboxPosition().y - _hitboxSize.y);
		}

		if(type == CollisionManager::FROM_LEFT)
		{
			updatePositions(pipe->getHitboxPosition().x + pipe->getHitboxSize().x, _position.y);
		}

		if(type == CollisionManager::FROM_RIGHT)
		{
			updatePositions(pipe->getHitboxPosition().x - pipe->getHitboxSize().x, _position.y);
		}
	}
	
	void MonsterOccurrence::onCollision(ProjectileOccurrence* projectileOccurrence)
	{
		if(projectileOccurrence->getSender() == ProjectileOccurrence::GENTILE)
		{
			/* Launch Dead animation, but for the moment.... */
			setState(DEAD);
		}
	}
	
	void MonsterOccurrence::onCollision(Perso*, int collision_type)
	{
		CollisionManager::Type type = static_cast<CollisionManager::Type>(collision_type);

		if(type == CollisionManager::FROM_BOTTOM && _monster->canBeJumpedOn())
		{
			if(_monster->canBeKilledByJump())
				setState(DEAD_BY_JUMP_ON);
			else
				setState(RETRACTED);
			_speed.x = 0;
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
			/*if(_hitboxPosition.y + _hitboxSize.y < 0)
				setState(DEAD);*/
			/* Test */
			if(_hitboxPosition.y + _hitboxSize.y > 1024)
				updatePositions(_hitboxPosition.x, 1024 - _hitboxSize.y);
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
			if(_state != WALK)
			{
				delta = !_monster->canBeKilledByJump() + !_monster->canBeKilledByFire();
			}
			_animation.render(_texture, app, _position, _side == LEFT_SIDE, delta);
		}
	}

	void MonsterOccurrence::setActivity(RenderWindow& app)
	{
		Collisionable::setActivity(app);
		
		const View& view = app.getView();

		if(!_isActive)
		{
			if(this->_initialPosition.x < view.getSize().x - view.getSize().x / 2
			|| this->_initialPosition.x + _hitboxSize.x < view.getSize().x + view.getSize().x / 2
			|| this->_initialPosition.y > view.getSize().y + view.getSize().y / 2
			|| this->_initialPosition.y + _hitboxSize.y < view.getSize().y - view.getSize().y / 2)
			{
				/* If view pass monster's initial position, we put monster as the beginning of the level */
				_position = _previousPosition = _initialPosition;
				setState(WALK);
				_speed.x = -MonsterConstants::MONSTER_SPEED_X;
				_side = LEFT_SIDE;
			}
		}

	}

    MonsterOccurrence::~MonsterOccurrence()
    {		
    }
} // namespace
