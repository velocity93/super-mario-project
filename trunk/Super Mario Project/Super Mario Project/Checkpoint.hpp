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
#include "Animation.hpp"

namespace Collisions
{
	class Checkpoint : public Collisionable
	{
	
	public:
		enum State
		{
			NOT_PASSED,
			PASSED
		};

		Checkpoint(const string& textureName);
		Checkpoint(const string& textureName, Vector2f& position, State state);

		State getState();
		void setState(const State &state);

		void update(RenderWindow& app);
		void render(RenderWindow& app);
		void setActivity(RenderWindow& app);
		void serialize(ofstream& file, const string& tabs);

        virtual ~Checkpoint();
		
    private:
		State _state;
		Animation<State> _animation;

		void loadCfgCheckpoint();
    };
} // namespace

#endif // HPP_CHECKPOINT
