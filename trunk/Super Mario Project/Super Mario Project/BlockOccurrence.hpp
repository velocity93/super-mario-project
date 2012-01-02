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

namespace Collisions
{
	class Block;
	class Perso;
	class Item;
	class BlockOccurrence : public EntityMovable
    {
    public:
		enum State {
			UNMOVABLE,
			PUSHED_TO_LEFT,
			PUSHED_TO_RIGHT,
			PUSHED_TO_TOP,
		};

		BlockOccurrence(
			const string& textureName, 
			Vector2f& position, 
			Vector2f& speed, 
			State state, 
			Side side,
			int physicIndex,
			Block* actual,
			Block* alternative);

		void updateGraphicData(RenderWindow& app);
		void updatePhysicData(RenderWindow& app);
		void render(RenderWindow& app);
		void setActivity(RenderWindow& app);

        virtual ~BlockOccurrence();
		
    private:
		Animation<State> _animation;
		int _physicIndex;
		Vector2i _coordSprite;
		Vector2i _size;
		State _state;
		Block* _actualBlock;
		Block* _alternativeBlock;
		Perso* _perso;
		Item* _itemContained;
    };
} // namespace

#endif // HPP_BLOCKOCCURRENCE
