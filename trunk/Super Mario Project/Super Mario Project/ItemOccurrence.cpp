////////////////////////////////////////////////////////////////////////
// ItemOccurrence.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ResourceManager.hpp"
#include "ItemOccurrence.hpp"
#include "Item.hpp"

using namespace SuperMarioProject;

namespace Collisions
{
	ItemOccurrence::ItemOccurrence(
		Item* item,
		const string& textureName, 
		Vector2f& position, 
		Vector2f& speed, 
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

	ItemOccurrence::State ItemOccurrence::getState()
	{
		return _state;
	}

	void ItemOccurrence::setState(State state)
	{
		_state = state;
		_animation.setCurrentState(state);
	}

	void ItemOccurrence::setActivity(RenderWindow& app)
	{
		View view = app.GetView();

		if(_hitboxPosition.x > view.GetCenter().x + view.GetHalfSize().x
			|| _hitboxPosition.x + _hitboxSize.x < view.GetCenter().x - view.GetHalfSize().x
			|| _hitboxPosition.y > view.GetCenter().y + view.GetHalfSize().y
			|| _hitboxPosition.y + _hitboxSize.y < view.GetCenter().y + view.GetHalfSize().y)
			_isActive = false;
		else
			_isActive = true;

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
				if(this->_item->getSubmission() & GRAVITY_SUBMISSION)
					gravity(_speed, app.GetFrameTime());

				/* Update physic position */
				/* Save actual position in previous position */
				_previousPosition = _position;

				/* Compute new position */
				_position.x = _position.x + _speed.x * app.GetFrameTime(); 
				_position.y = _position.y + _speed.y * app.GetFrameTime();
			}
			else
			{
				if(_blockExitTime.GetElapsedTime() > ITEM_EXIT_BLOCK_TIME)
				{
					if(_item->getType() == Item::Type::COIN)
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
			_animation.render(_texture, app, _position, _side == Side::LEFT_SIDE);
	}

	ItemOccurrence::~ItemOccurrence()
	{
	}
} // namespace
