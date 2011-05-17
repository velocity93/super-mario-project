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
		this->setPreviousPosition(this->getPosition());

		/* Compute new position */
		this->setPosition(this->getPosition().getX() + this->getSpeed().x * app.GetFrameTime(), 
			this->getPosition().getY() + this->getSpeed().y * app.GetFrameTime());

		/* Update graphics data */
		// TODO

	}

	void ItemOccurrence::render(RenderWindow& app)
	{
		app.Draw(this->getTexture()->getSprite());
	}

	ItemOccurrence::~ItemOccurrence()
	{
	}
} // namespace
