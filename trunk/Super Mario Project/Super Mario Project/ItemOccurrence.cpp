////////////////////////////////////////////////////////////////////////
// ItemOccurrence.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ItemOccurrence.hpp"
#include "Item.hpp"

namespace Collisions
{
	ItemOccurrence::State ItemOccurrence::getState()
	{
		return _state;
	}

	bool ItemOccurrence::getIsActive()
	{
		return _isActive;
	}

	void ItemOccurrence::setState(State state)
	{
		_state = state;
	}

	void ItemOccurrence::setIsActive(bool isActive)
	{
		_isActive = isActive;
	}

	void ItemOccurrence::update(RenderWindow& app)
	{
		/* If it falls in hole */
		if(_hitboxPosition.y + _hitboxSize.y < 0)
			_item->removeItemOccurrence(this);

		/* Submissions */
		if(this->_item->getSubmission() & GRAVITY_SUBMISSION)
			gravity(_speed, app.GetFrameTime());

		/* Update physic position */
		/* Save actual position in previous prosition */
		_previousPosition = _position;

		/* Compute new position */
		this->setPosition(_position.x + _speed.x * app.GetFrameTime(), 
			_position.y + _speed.y * app.GetFrameTime());

	}

	void ItemOccurrence::render(RenderWindow& app)
	{
		Sprite sprite = _texture->getSprite();
		app.Draw(sprite);
	}

	ItemOccurrence::~ItemOccurrence()
	{
	}
} // namespace
