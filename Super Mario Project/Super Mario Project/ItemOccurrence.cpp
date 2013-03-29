////////////////////////////////////////////////////////////////////////
// ItemOccurrence.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ResourceManager.hpp"
#include "CollisionManager.hpp"
#include "Perso.hpp"
#include "Block.hpp"
#include "Item.hpp"
#include "ItemOccurrence.hpp"
#include "Pipe.hpp"

using namespace std;
using sf::Vector2f;
using sf::RenderWindow;

namespace smp
{
	ItemOccurrence::ItemOccurrence(
		Item* item,
		const string& textureName, 
		const Vector2f& position, 
		const Vector2f& speed, 
		State state, 
		Side side,
		map<ItemOccurrence::State, int>& nbSpritesByState,
		map<ItemOccurrence::State, int>& frameDelayByState) : 
		EntityMovable(textureName, position, speed, side), 
			_state(state), 
			_blockExitTime(PausableClock(true)),
			_animation(NB_STATES)
	{
		_item = item;

		/* Initialize animation class */
		_animation.setMapNbSprites(nbSpritesByState);
		_animation.setMapFrameDelay(frameDelayByState);
		_animation.setCurrentState(_state);

		_position = _hitboxPosition = position;
		_speed = _item->getInitialSpeed();
		_hitboxSize.x = _texture->getSize().x / _animation.getNbSpritesMax();
		_hitboxSize.y = _texture->getSize().y;
	}

	Item* ItemOccurrence::getModel()
	{
		return _item;
	}

	ItemOccurrence::State ItemOccurrence::getState()
	{
		return _state;
	}

	void ItemOccurrence::setState(State state)
	{
		_state = state;
		_animation.setCurrentState(state);
	}

	void ItemOccurrence::onCollision(Collisionable* c, int collision_type)
	{
		/* Collision vs BlockOccurrence */
		BlockOccurrence* block = dynamic_cast<BlockOccurrence*>(c);
		if(block != NULL)
		{
			return onCollision(block, collision_type);
		}

		/* Collision vs Pipe */
		Pipe* pipe = dynamic_cast<Pipe*>(c);
		if(pipe != NULL)
		{
			return onCollision(pipe, collision_type);
		}

		/* Collision vs Perso */
		Perso* perso = dynamic_cast<Perso*>(c);
		if(perso != NULL)
		{
			setState(TAKEN);
		}
	}

	void ItemOccurrence::onCollision(BlockOccurrence* block, int collision_type)
	{
		CollisionManager::Type type = static_cast<CollisionManager::Type>(collision_type);

		if(type == CollisionManager::FROM_LEFT && (block->getActualModel()->getPhysic() & BlocksConstants::RIGHT_WALL))
		{
			updatePositions(block->getHitboxPosition().x + block->getHitboxSize().x, _hitboxPosition.y);
			_speed.x *= -1;
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
		}

		if(type == CollisionManager::FROM_BOTTOM && (block->getActualModel()->getPhysic() & BlocksConstants::GROUND))
		{
			updatePositions(_hitboxPosition.x, block->getHitboxPosition().y - _hitboxSize.y);
		}
	}
	
	void ItemOccurrence::onCollision(Pipe* pipe, int collision_type)
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
	
	void ItemOccurrence::updatePhysicData(float time, RenderWindow& app)
	{
		setActivity(app);

		if(_isActive)
		{
			if(_state == NORMAL)
			{
				/* Submissions */
				if(this->_item->getSubmission() & PhysicConstants::GRAVITY_SUBMISSION)
					gravity(_speed, time);

				/* Update physic position */
				/* Save actual position in previous position */
				_previousHitboxPosition = _hitboxPosition;
				_previousPosition = _position;

				/* Compute new position */
				updatePositions(_hitboxPosition.x + time * _speed.x, _hitboxPosition.y + time * _speed.y);

				/* If it falls in hole */
				/*if(_hitboxPosition.y + _hitboxSize.y < 0)
					_item->removeItemOccurrence(this);*/
				if(_hitboxPosition.y < 0)
					_hitboxPosition.y = 0;
			}
			else
			{
				if(_blockExitTime.GetElapsedTime() > ITEM_EXIT_BLOCK_TIME)
				{
					if(_item->getType() == Item::COIN)
					{
						setState(TAKEN);
					}
					else
					{
						_state = NORMAL;
						_speed.x = _item->getInitialSpeed().x;
						_speed.y = _item->getInitialSpeed().y;
					}
					_blockExitTime.Reset(true);
				}
			}
		}

	}

	void ItemOccurrence::updateGraphicData(RenderWindow&)
	{
		/* Update animation */
		if(_isActive)
			_animation.update();

	}

	void ItemOccurrence::render(RenderWindow& app)
	{
		if(_isActive)
			_animation.render(_texture, app, _hitboxPosition, _side == LEFT_SIDE);
	}

	ItemOccurrence::~ItemOccurrence()
	{
		//_texture->release();
	}
} // namespace
