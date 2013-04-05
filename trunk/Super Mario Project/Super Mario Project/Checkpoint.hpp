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

namespace smp
{
	class Checkpoint : public Collisionable
	{
	
	public:
		typedef enum State
		{
			NOT_PASSED,
			PASSED,
			NB_STATES
		} State;

		Checkpoint(const std::string& textureName);
		Checkpoint(const std::string& textureName, sf::Vector2f& position, State state);

		State getState();
		void setState(const State &state);
		Animation<State>& getAnimation();

		void updateGraphicData(sf::RenderWindow& app);
		void render(sf::RenderWindow& app);
		void serialize(std::ofstream& file, const std::string& tabs);

        virtual ~Checkpoint();
		
    private:
		State _state;
		Animation<State> _animation;

		void loadCfgCheckpoint();
    };
} // namespace

#endif // HPP_CHECKPOINT
