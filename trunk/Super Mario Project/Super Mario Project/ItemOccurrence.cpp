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
#include <typeinfo.h>

namespace Collisions
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
			_blockExitTime(PausableClock(true))
	{
		_item = item;

		/* Initialize animation class */
		_animation.setMapNbSprites(nbSpritesByState);
		_animation.setMapFrameDelay(frameDelayByState);
		_animation.setCurrentState(_state);

		_position = _hitboxPosition = position;
		_speed = _item->getInitialSpeed();
		_hitboxSize.x = _texture->getImage()->GetWidth() / _animation.getNbSpritesMax();
		_hitboxSize.y = _texture->getImage()->GetHeight();
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

	void ItemOccurrence::onCollision(Collisionable* c, vector<bool>& infos)
	{
		/* Collision vs BlockOccurrence */
		BlockOccurrence* block = dynamic_cast<BlockOccurrence*>(c);
		if(block != NULL)
		{
			return onCollision(block, infos);
		}

		/* Collision vs BlockOccurrence */
		Pipe* pipe = dynamic_cast<Pipe*>(c);
		if(pipe != NULL)
		{
			return onCollision(pipe, infos);
		}

		/* Collision vs Perso */
		Perso* perso = dynamic_cast<Perso*>(c);
		if(perso != NULL)
		{
			return onCollision(perso);
		}
	}

	void ItemOccurrence::onCollision(Perso*)
	{
		_item->removeItemOccurrence(this);
	}

	void ItemOccurrence::onCollision(BlockOccurrence* block, vector<bool>& infos)
	{
		if(infos[CollisionManager::FROM_BOTTOM] && (block->getActualModel()->getType() & BlocksConstants::GROUND))
		{
			updatePositions(_position.x, block->getHitboxPosition().y + block->getHitboxSize().y);
		}

		if(infos[CollisionManager::FROM_TOP] && (block->getActualModel()->getType() & BlocksConstants::ROOF))
		{
			updatePositions(_position.x, block->getHitboxPosition().y - _hitboxSize.y);
		}

		if(infos[CollisionManager::FROM_LEFT] && (block->getActualModel()->getType() & BlocksConstants::RIGHT_WALL))
		{
			updatePositions(block->getHitboxPosition().x + block->getHitboxSize().x, _position.y);
		}

		if(infos[CollisionManager::FROM_RIGHT] && (block->getActualModel()->getType() & BlocksConstants::LEFT_WALL))
		{
			updatePositions(block->getHitboxPosition().x - _hitboxSize.x, _position.y);
		}
	}
	
	void ItemOccurrence::onCollision(Pipe* pipe, vector<bool>& infos)
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
	
	void ItemOccurrence::updatePhysicData(RenderWindow& app)
	{
		setActivity(app);

		if(_isActive)
		{
			if(_state == NORMAL)
			{
				/* If it falls in hole */
				if(_hitboxPosition.y + _hitboxSize.y < 0)
					_item->removeItemOccurrence(this);

				/* Submissions */
				if(this->_item->getSubmission() & PhysicConstants::GRAVITY_SUBMISSION)
					gravity(_speed, app.GetFrameTime());

				/* Update physic position */
				/* Save actual position in previous position */
				_previousHitboxPosition = _hitboxPosition;
				_previousPosition = _position;

				/* Compute new position */
				_hitboxPosition.x = _hitboxPosition.x + _speed.x * app.GetFrameTime(); 
				_hitboxPosition.y = _hitboxPosition.y + _speed.y * app.GetFrameTime();
			}
			else
			{
				if(_blockExitTime.GetElapsedTime() > ITEM_EXIT_BLOCK_TIME)
				{
					if(_item->getType() == Item::COIN)
					{
						_item->removeItemOccurrence(this);
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
	}
} // namespace
