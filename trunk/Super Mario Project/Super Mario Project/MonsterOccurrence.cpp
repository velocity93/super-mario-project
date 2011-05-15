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


	void MonsterOccurrence::update(float time)
	{
		/* Update physic position */
		/* Save actual position in previous prosition */
		this->getPreviousPosition().set(this->getPosition());

		/* Compute new position */
		this->getPosition().set(this->getPosition().getX() + this->getSpeed().getX() * time, this->getPosition().getY() + this->getSpeed().getY() * time);
	}

	void MonsterOccurrence::render(RenderWindow& app, Screen& screen)
	{
		this->setSide(Side::LEFT_SIDE);
	}

    MonsterOccurrence::~MonsterOccurrence()
    {		
    }
} // namespace
