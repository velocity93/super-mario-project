////////////////////////////////////////////////////////////////////////
// Checkpoint.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Checkpoint.hpp"

namespace Collisions
{
	Checkpoint::State Checkpoint::getState()
	{
		return _state;
	}
	
	void Checkpoint::setState(State state)
	{
		_state = state;
	}

    void Checkpoint::update(float time)
    {

    }

	void Checkpoint::render(RenderWindow& app, Screen& screen)
    {

    }


    Checkpoint::~Checkpoint()
    {
    }
} // namespace
