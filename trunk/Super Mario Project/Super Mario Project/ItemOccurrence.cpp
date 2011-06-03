////////////////////////////////////////////////////////////////////////
// ItemOccurrence.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ItemOccurrence.hpp"

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
		/* Update physic position */
		/* Save actual position in previous prosition */
		_previousPosition = _position;

		/* Compute new position */
		this->setPosition(_position.getX() + _speed.x * app.GetFrameTime(), 
			_position.getY() + _speed.y * app.GetFrameTime());

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
