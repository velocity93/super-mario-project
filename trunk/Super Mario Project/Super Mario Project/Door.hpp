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
	class Door : Collisionable
    {
    public:
        Door();
		int GetIndexDoorDestination()
		{
			return indexDoorDestination;
		}

		string GetLevelDestination()
		{
			return levelDestination;
		}

		void SetIndexDoorDestination(int IndexDoorDestination)
		{
			indexDoorDestination = IndexDoorDestination;
		}

		void SetLevelDestination(string LevelDestination)
		{
			levelDestination = LevelDestination;
		}

		void Update();
		void Render();

        ~Door();
		
    private:
		int indexDoorDestination;
		string levelDestination;
    };
} // namespace

#endif // HPP_DOOR
