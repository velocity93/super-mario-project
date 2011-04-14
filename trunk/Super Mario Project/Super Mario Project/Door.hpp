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
	enum IO_state
	{
		OPEN,
		CLOSED
	};

	class Door : Collisionable
    {
    public:
		Door() : Collisionable(), indexDoorDestination(-1), state(CLOSED), levelDestination("") { }
		Door(Coord<float> Position, int IndexDoorDestination, string LevelDestination, IO_state State) 
			: Collisionable(Position), indexDoorDestination(IndexDoorDestination), levelDestination(LevelDestination), state(State) { }

		int GetIndexDoorDestination()
		{
			return indexDoorDestination;
		}

		string GetLevelDestination()
		{
			return levelDestination;
		}

		IO_state GetState()
		{
			return state;
		}

		void SetIndexDoorDestination(int IndexDoorDestination)
		{
			indexDoorDestination = IndexDoorDestination;
		}

		void SetLevelDestination(string LevelDestination)
		{
			levelDestination = LevelDestination;
		}

		void SetState(IO_state State)
		{
			state = State;
		}

		void Update(float time);
		void Render();

        ~Door();
		
    private:
		int indexDoorDestination;
		string levelDestination;
		IO_state state;
    };
} // namespace

#endif // HPP_DOOR
