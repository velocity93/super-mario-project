////////////////////////////////////////////////////////////////////////
// Door.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_DOOR
#define HPP_DOOR

#include "Collisionable.hpp"
#include "Animation.hpp"

namespace smp
{
	class Door : public Collisionable
    {
    public:
		typedef enum 
		{
			OPEN,
			CLOSED,
			NB_STATES
		} State;

		/* Constructors */
		Door(const std::string& textureName);
		Door(const std::string& textureName, sf::Vector2f position, int indexDestination, const std::string& levelDestination, State state);
		/* getters and setters */
		int getIndexDestination();
		std::string& getLevelDestination();
		State getState();
		void setIndexDestination(int indexDestination);
		void setLevelDestination(const std::string& levelDestination);
		void setState(State state);

		/* Methods */
		void updateGraphicData(sf::RenderWindow& app);
		void render(sf::RenderWindow& app);

        virtual ~Door();
		
    private:
		Animation<State> _animation;
		int _indexDestination;
		std::string _levelDestination;
		State _state;

		void loadDoor(const std::string& textureName);
    };
} // namespace

#endif // HPP_DOOR
