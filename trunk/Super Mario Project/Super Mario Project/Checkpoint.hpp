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
	class Checkpoint : public Collisionable
	{
	
	public:
		enum State
		{
			PASSED,
			NOT_PASSED
		};

		Checkpoint(string textureName) : Collisionable(textureName), _state(NOT_PASSED) { }
		Checkpoint(string textureName, Coord<float> position, State state) : Collisionable(textureName, position), _state(state) { }

		State getState();
		void setState(State state);

		void update(float time);
		void render(RenderWindow& app);

        virtual ~Checkpoint();
		
    private:
		State _state;
    };
} // namespace

#endif // HPP_CHECKPOINT
