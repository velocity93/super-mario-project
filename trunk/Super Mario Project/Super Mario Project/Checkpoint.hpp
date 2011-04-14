////////////////////////////////////////////////////////////////////////
// Checkpoint.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_CHECKPOINT
#define HPP_CHECKPOINT

#include "Collisionable.hpp"

namespace Collisions
{
	enum Checkpoint_state
	{
		PASSED,
		NOT_PASSED
	};

	class Checkpoint : Collisionable
    {
    public:
		Checkpoint() : Collisionable(), state(NOT_PASSED) { }
		Checkpoint(Coord<float> Position, Checkpoint_state State) : Collisionable(Position), state(State) { }

		void Update(float time);
		void Render();
        ~Checkpoint();
		
    private:
		Checkpoint_state state;
    };
} // namespace

#endif // HPP_CHECKPOINT
