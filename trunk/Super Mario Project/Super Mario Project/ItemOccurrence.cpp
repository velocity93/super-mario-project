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

	void ItemOccurrence::update(float time)
	{
		/* Update physic position */
		/* Save actual position in previous prosition */
		this->getPreviousPosition().set(this->getPosition());

		/* Compute new position */
		this->getPosition().set(this->getPosition().getX() + this->getSpeed().getX() * time, this->getPosition().getY() + this->getSpeed().getY() * time);

		/* Update graphics data */
		// TODO

	}

	void ItemOccurrence::render(RenderWindow& app)
	{
		Sprite sprite(getTexture()->getImage());
		app.Draw(sprite);
	}

	ItemOccurrence::~ItemOccurrence()
	{
	}
} // namespace
