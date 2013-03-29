////////////////////////////////////////////////////////////////////////
// BlockOccurrence.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_BLOCKOCCURRENCE
#define HPP_BLOCKOCCURRENCE

#include "EntityMovable.hpp"
#include "Animation.hpp"

namespace smp
{
	// forward declaration
	class Block;
	class Perso;
	class Item;
	
	class BlockOccurrence : public EntityMovable
    {
    public:
		typedef enum State {
			UNMOVABLE,
			PUSHED_TO_LEFT,
			PUSHED_TO_RIGHT,
			PUSHED_TO_TOP,
			NB_STATES
		} State;

		BlockOccurrence(
			const std::string& textureName, 
			const sf::Vector2f& position, 
			const sf::Vector2f& speed, 
			State state, 
			Side side,
			int physicIndex,
			Block* actual,
			Block* alternative);

		Block* getActualModel();
		
		void updateGraphicData(sf::RenderWindow& app);
		void updatePhysicData(float time, sf::RenderWindow& app);
		void render(sf::RenderWindow& app);

		void onCollision(Collisionable* c, int collision_type);

        virtual ~BlockOccurrence();
		
    private:
		Animation<State> _animation;
		sf::Vector2i _coordSprite;
		sf::Vector2i _size;
		State _state;
		Block* _actualBlock;
		Block* _alternativeBlock;
		Perso* _perso;
		Item* _itemContained;

		/* Collisions resolutions */
		void onCollision(Perso* perso, int collision_type);
    };
} // namespace

#endif // HPP_BLOCKOCCURRENCE
