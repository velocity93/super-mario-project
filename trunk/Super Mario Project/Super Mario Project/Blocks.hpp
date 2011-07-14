////////////////////////////////////////////////////////////////////////
// Blocks.hpp
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

#include "Resource.hpp"
#include "BlockOccurrence.hpp"

namespace Collisions
{
	class Blocks : public SuperMarioProject::Resource
    {
    public:
        Blocks(const string& textureName);

		void addNewBlockOccurrence(int physicIndex, Vector2f& position = Vector2f(0,0), Vector2f& speed = Vector2f(0,0), 
			BlockOccurrence::State state = BlockOccurrence::State::UNMOVABLE,
			BlockOccurrence::Side side = BlockOccurrence::Side::RIGHT_SIDE);

		void removeBlockOccurrence(const BlockOccurrence* block);

		int getPhysic(int index);

		void update(RenderWindow& app);
		void render(RenderWindow& app);

        virtual ~Blocks();
		
    private:
		Vector2i _nbSprites;
		int _vAnim;
		vector<int> _physics;
		vector<BlockOccurrence*> _blockOccurrences;
		
		void loadBlockConfiguration(const string& textureName);
		
    };
} // namespace

#endif // HPP_BLOCKS
