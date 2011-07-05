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

		ItemOccurrence(const string& textureName, 
			Vector2f& position, 
			Vector2f& speed, 
			State state, 
			Side side, 
			const map<ItemOccurrence::State, int>& nbSpritesByState,
			const map<ItemOccurrence::State, int>& vAnimByState);

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
