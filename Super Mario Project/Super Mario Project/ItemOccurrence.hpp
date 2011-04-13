////////////////////////////////////////////////////////////////////////
// ItemOccurrence.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_ITEMOCCURRENCE
#define HPP_ITEMOCCURRENCE

#include "EntityMovable.hpp"

namespace Collisions
{
	enum Item_state
	{
		NORMAL,
		GET_OUT_FROM_BLOC
	};

    class ItemOccurrence : EntityMovable
    {
    public:
		ItemOccurrence() : EntityMovable(), state(NORMAL), isActive(true) { }
		ItemOccurrence(Coord<float> Position, Item_state State, bool IsActive)
			: EntityMovable(Position), state(State), isActive(IsActive) { }

		Item_state GetState()
		{
			return state;
		}

		bool GetIsActive()
		{
			return isActive;
		}

		void SetState(Item_state State)
		{
			state = State;
		}

		void SetIsActive(bool IsActive)
		{
			isActive = IsActive;
		}

		void Update();
		void Render();
        ~ItemOccurrence();
		
    private:
		Item_state state;
		bool isActive;
    };
} // namespace

#endif // HPP_ITEMOCCURRENCE
