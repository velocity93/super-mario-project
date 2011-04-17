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
	class Checkpoint : Collisionable
	{
		enum State
		{
			PASSED,
			NOT_PASSED
		};

    public:
		Checkpoint() : Collisionable(), _state(NOT_PASSED) { }
		Checkpoint(Coord<float> position, State state) : Collisionable(position), _state(state) { }

		State getState();
		void setState(State state);

		void update(float time);
		void render();

        virtual ~Checkpoint();
		
    private:
		State _state;
    };
} // namespace

#endif // HPP_CHECKPOINT
