////////////////////////////////////////////////////////////////////////
// MonsterOccurrence.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "MonsterOccurrence.hpp"

namespace Collisions
{
	MonsterOccurrence::State MonsterOccurrence::getState()
	{
		return _state;
	}

	void MonsterOccurrence::setState(State state)
	{
		_state = state;
	}


	void MonsterOccurrence::update(RenderWindow& app)
	{
		/* Update physic position */
		/* Save actual position in previous prosition */
		this->setPreviousPosition(this->getPosition());

		/* Compute new position */
		this->setPosition(this->getPosition().getX() + this->getSpeed().x * app.GetFrameTime(), 
			this->getPosition().getY() + this->getSpeed().y * app.GetFrameTime());
	}

	void MonsterOccurrence::render(RenderWindow& app)
	{
		this->setSide(Side::LEFT_SIDE);
	}

    MonsterOccurrence::~MonsterOccurrence()
    {		
    }
} // namespace
