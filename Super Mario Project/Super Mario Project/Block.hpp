////////////////////////////////////////////////////////////////////////
// Block.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_BLOCKS
#define HPP_BLOCKS

#define EMPTY							0x200000
#define COIN_DISTRIBUTOR				0x400000
#define BREAKABLE                       0x800000
#define CLIMBING						0x1000000 /* Beans, ... */
#define DEAD_BLOCK						0x2000000 /* Lava, acid, poison, ....*/

#include "BlockOccurrence.hpp"

namespace Collisions
{
	class Tileset;
	class Block
    {
    public:
		Block(Tileset* tileset, int physicIndex, int type) : _tileset(tileset), _physicIndex(physicIndex), _type(type) { }

		Tileset* getTileset();
		const int getPhysicIndex();
		const int getType();

		BlockOccurrence* addNewBlockOccurrence(Block* alternativeBlock, Vector2f& position = Vector2f(0,0), Vector2f& speed = Vector2f(0,0), 
			BlockOccurrence::State state = BlockOccurrence::State::UNMOVABLE,
			BlockOccurrence::Side side = BlockOccurrence::Side::RIGHT_SIDE);

		void removeBlockOccurrence(const BlockOccurrence* block);

		void update(RenderWindow& app);
		void render(RenderWindow& app);

		void serialize(ofstream& file, string& tabs);

        virtual ~Block();
		
    private:
		vector<BlockOccurrence*> _blockOccurrences;
		Tileset* _tileset;
		Vector2i _size;
		Vector2i _coordSprite;
		int _physicIndex;
		int _type;
		
    };
} // namespace

#endif // HPP_BLOCKS
