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

namespace smp
{
	// forward declaration
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
			GET_OUT_FROM_BLOC,
			TAKEN,
			NB_STATES
		} State;

		ItemOccurrence(Item* item,
			const std::string& textureName, 
			const sf::Vector2f& position, 
			const sf::Vector2f& speed, 
			State state, 
			Side side, 
			std::map<ItemOccurrence::State, int>& nbSpritesByState,
			std::map<ItemOccurrence::State, int>& frameDelayByState);

		State getState();
		bool getIsActive();
		Item* getModel();
		void setState(State state);

		void onCollision(Collisionable* c, int collision_type);

		void updateGraphicData(sf::RenderWindow& app);
		void updatePhysicData(float time, sf::RenderWindow& app);
		void render(sf::RenderWindow& app);

        virtual ~ItemOccurrence();
		
    private:
		Animation<State> _animation;
		State _state;		
		PausableClock _blockExitTime;
		Item* _item;

		/* Collisions resolutions */
		void onCollision(Perso*);
		void onCollision(Pipe* p, int collision_type);
		void onCollision(BlockOccurrence* block, int collision_type);
    };
} // namespace

#endif // HPP_ITEMOCCURRENCE
