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
	class Item;
	class ItemOccurrence : public EntityMovable
    {
	
	public:
		enum State
		{
			NORMAL,
			GET_OUT_FROM_BLOC
		};

   
		ItemOccurrence(const string& textureName, Item* item) :  EntityMovable(textureName), _state(NORMAL), _isActive(true), _blockExitTime(0), _item(item) { }
		ItemOccurrence(const string& textureName, Item* item, Vector2f position, State state)
			: EntityMovable(textureName, position), _state(state), _isActive(true), _blockExitTime(0), _item(item) { }

		State getState();
		bool getIsActive();
		void setState(State state);
		void setIsActive(bool isActive);

		void update(RenderWindow& app);
		void render(RenderWindow& app);

        virtual ~ItemOccurrence();
		
    private:
		State _state;
		bool _isActive;
		int _blockExitTime;
		Item* _item;
    };
} // namespace

#endif // HPP_ITEMOCCURRENCE
