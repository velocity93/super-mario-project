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
#include "Item.hpp"

namespace Collisions
{
	class ItemOccurrence : public EntityMovable
    {
	
	public:
		enum State
		{
			NORMAL,
			GET_OUT_FROM_BLOC
		};

   
		ItemOccurrence() : EntityMovable(), _state(NORMAL), _isActive(true) { }
		ItemOccurrence(Coord<float> position, State state, bool isActive)
			: EntityMovable(position), _state(state), _isActive(isActive) { }

		State getState();
		bool getIsActive();
		void setState(State state);
		void setIsActive(bool isActive);

		void update(float time);
		void render(RenderWindow& app);

        virtual ~ItemOccurrence();
		
    private:
		State _state;
		bool _isActive;
		Item* _item;
    };
} // namespace

#endif // HPP_ITEMOCCURRENCE