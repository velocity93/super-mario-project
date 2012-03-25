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
#include "Animation.hpp"

#define ITEM_EXIT_BLOCK_TIME			650

namespace Collisions
{
	class Item;
	class Pipe;
	class Perso;
	class BlockOccurrence;
	class ItemOccurrence : public EntityMovable
    {
	
	public:
		typedef enum State
		{
			NORMAL,
			GET_OUT_FROM_BLOC
		} State;

		ItemOccurrence(Item* item,
			const string& textureName, 
			const Vector2f& position, 
			const Vector2f& speed, 
			State state, 
			Side side, 
			map<ItemOccurrence::State, int>& nbSpritesByState,
			map<ItemOccurrence::State, int>& frameDelayByState);

		State getState();
		bool getIsActive();
		Item* getModel();
		void setState(State state);

		void onCollision(Collisionable* c, vector<bool>& infos);

		void updateGraphicData(RenderWindow& app);
		void updatePhysicData(RenderWindow& app);
		void render(RenderWindow& app);

        virtual ~ItemOccurrence();
		
    private:
		Animation<State> _animation;
		State _state;		
		PausableClock _blockExitTime;
		Item* _item;

		/* Collisions resolutions */
		void onCollision(Perso*);
		void onCollision(Pipe* p, vector<bool>& infos);
		void onCollision(BlockOccurrence* block, vector<bool>& infos);
    };
} // namespace

#endif // HPP_ITEMOCCURRENCE
