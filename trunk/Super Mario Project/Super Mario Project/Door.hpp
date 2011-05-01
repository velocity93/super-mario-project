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

namespace Collisions
{
	class Door : public Collisionable
    {
		
    public:
		enum State
		{
			OPEN,
			CLOSED
		};


		/* Constructors */
		Door(string textureName) : Collisionable(textureName), _indexDestination(-1), _state(CLOSED), _levelDestination("") { }
		Door(string textureName, Coord<float> position, int indexDestination, string levelDestination, State state) 
			: Collisionable(textureName, position), _indexDestination(indexDestination), _levelDestination(levelDestination), _state(state) { }

		/* getters and setters */
		int getIndexDestination();
		string getLevelDestination();
		State getState();
		void setIndexDestination(int indexDestination);
		void setLevelDestination(string levelDestination);
		void setState(State state);

		/* Methods */
		void update(float time);
		void render(RenderWindow& app);

        virtual ~Door();
		
    private:
		int _indexDestination;
		string _levelDestination;
		State _state;
    };
} // namespace

#endif // HPP_DOOR
