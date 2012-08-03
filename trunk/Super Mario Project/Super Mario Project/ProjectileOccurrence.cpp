////////////////////////////////////////////////////////////////////////
// ProjectileOccurrence.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ResourceManager.hpp"
#include "CollisionManager.hpp"
#include "ProjectileOccurrence.hpp"
#include "Projectile.hpp"

using namespace SuperMarioProject;

namespace Collisions
{
	ProjectileOccurrence::ProjectileOccurrence(
		Projectile* projectile,
		const string& textureName, 
		const Vector2f& position, 
		const Vector2f& speed, 
		State state,
		Side side,
		map<ProjectileOccurrence::State, int>& nbSpritesByState,
		map<ProjectileOccurrence::State, int>& frameDelayByState) :
		EntityMovable(textureName, position, speed, side), 
			_sender(GENTILE),
			_state(state),
			_lifeTime(PausableClock()),
			_appearanceTime(PausableClock())
	{
		_projectile = projectile;

		/* Initialize animation class */
		_animation.setMapNbSprites(nbSpritesByState);
		_animation.setMapFrameDelay(frameDelayByState);
		_animation.setCurrentState(state);

		/* Hitbox */
		_deltaX = _projectile->getBottomLeft();
		
		_hitboxSize.y = _projectile->getTop();
		_hitboxSize.x = _texture->getSize().x / _animation.getNbSpritesMax() - 2 * _deltaX;
		updatePositions(position.x,  position.y + _texture->getSize().y / nbSpritesByState.size() - _hitboxSize.y);
	}

	ProjectileOccurrence::State ProjectileOccurrence::getState()
	{
		return _state;
	}

	ProjectileOccurrence::Sender ProjectileOccurrence::getSender()
	{
		return _sender;
	}

	void ProjectileOccurrence::setState(State state)
	{
		_state = state;
		_animation.setCurrentState(state);
	}

	void ProjectileOccurrence::onCollision(Collisionable* c, int collision_type)
	{
		/* Collision vs BlockOccurrence */
		BlockOccurrence* block = dynamic_cast<BlockOccurrence*>(c);
		if(block != NULL)
		{
			return onCollision(block, collision_type);
		}

		/* Otherwise */
		_projectile->removeProjectileOccurrence(this);
	}

	void ProjectileOccurrence::onCollision(BlockOccurrence* block, int collision_type)
	{
		CollisionManager::Type type = static_cast<CollisionManager::Type>(collision_type);

		if(type == CollisionManager::FROM_LEFT && (block->getActualModel()->getPhysic() & BlocksConstants::RIGHT_WALL))
		{
			_hitboxPosition.x = block->getHitboxPosition().x + block->getHitboxSize().x;
			_speed.x *= -1;
		}

		if(type == CollisionManager::FROM_RIGHT && (block->getActualModel()->getPhysic() & BlocksConstants::LEFT_WALL))
		{
			_hitboxPosition.x = block->getHitboxPosition().x - _hitboxSize.x;
			_speed.x *= -1;
		}

		if(type == CollisionManager::FROM_BOTTOM && (block->getActualModel()->getPhysic() & BlocksConstants::GROUND))
		{
			_hitboxPosition.y = block->getHitboxPosition().y + block->getHitboxSize().y;
			_speed.y *= -1;
		}

		if(type == CollisionManager::FROM_TOP && (block->getActualModel()->getPhysic() & BlocksConstants::ROOF))
		{
			_hitboxPosition.y = block->getHitboxPosition().y - _hitboxSize.y;
			_speed.y *= -1;
		}
	}

	void ProjectileOccurrence::updatePhysicData(float time, RenderWindow& app)
	{
		setActivity(app);

		if(_isActive)
		{
			if(_lifeTime.GetElapsedTime() > 0)
			{
				/* Submissions */
				if(_projectile->getSubmission() & PhysicConstants::GRAVITY_SUBMISSION)
					gravity(_speed, time);

				/* Update physic position */
				/* Save actual position in previous position */
				_previousPosition = _position;

				/* Compute new position */
				updatePositions(_hitboxPosition.x + time * _speed.x, _hitboxPosition.y + time * _speed.y);

				/* If it falls in hole */
				/*if(_hitboxPosition.y + _hitboxSize.y < 0)
					_projectile->removeProjectileOccurrence(this);*/
				if(_hitboxPosition.y < 0)
					_hitboxPosition.y = 0;
			}
			else
			{
				//_projectile->removeProjectileOccurrence(this);
			}
		}
	}

	void ProjectileOccurrence::updateGraphicData(RenderWindow&)
	{
		/* Update animation */
		if(_isActive)
			_animation.update();
	}

	void ProjectileOccurrence::render(RenderWindow& app)
	{
		if(_isActive)
			_animation.render(_texture, app, _position, _side == LEFT_SIDE);
	}

	ProjectileOccurrence::~ProjectileOccurrence()
	{
	}
} // namespace
