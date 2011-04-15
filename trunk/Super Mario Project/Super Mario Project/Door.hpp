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
		Door() : Collisionable(), _indexDoorDestination(-1), _state(CLOSED), _levelDestination("") { }
		Door(Coord<float> position, int indexDoorDestination, string levelDestination, State state) 
			: Collisionable(position), _indexDoorDestination(indexDoorDestination), _levelDestination(levelDestination), _state(state) { }

		/* getters and setters */
		int getIndexDoorDestination();
		string getLevelDestination();
		State getState();
		void setIndexDoorDestination(int indexDoorDestination);
		void setLevelDestination(string levelDestination);
		void setState(State state);

		/* Methods */
		void update(float time);
		void render();

        ~Door();
		
    private:
		int _indexDoorDestination;
		string _levelDestination;
		State _state;
    };
} // namespace

#endif // HPP_DOOR
