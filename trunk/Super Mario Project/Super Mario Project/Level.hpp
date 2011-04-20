////////////////////////////////////////////////////////////////////////
// Level.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_LEVEL
#define HPP_LEVEL

#include "Coord.hpp"
#include "Checkpoint.hpp"
#include "Background.hpp"
#include "Foreground.hpp"
#include "ParticleGenerator.hpp"
#include "Projectile.hpp"
#include "Blocks.hpp"
#include "BlockOccurrence.hpp"
#include "Monster.hpp"
#include "Item.hpp"
#include "Finish.hpp"
#include "Pipe.hpp"
#include "Object.hpp"

#include <string>

using namespace Collisions;
using namespace Rendering;

namespace SuperMarioProject
{
    class Level
    {
    public:
        Level() : _levelName(""), _musicTitle(""), _size(Coord<int>()), _spawn(Coord<int>())
			/*_checkpoints(vector<Checkpoint>()), _backgrounds(vector<Background>()), 
			_finishes(vector<Finish>()), _projectiles(vector<Projectiles>()) */
		{ }

		Coord<int> getSize();
		Coord<int> getBlockSize();

		void update(float time);
		void render(RenderWindow& app);

        virtual ~Level();
		
    private:
		string _levelName;
		string _musicTitle;
		Coord<int> _size;
		Coord<int> _spawn;
		Coord<int> _blockSize;
		/*vector<Checkpoint> _checkpoints;
		vector<Background> _backgrounds:
		vector<Finish> _finishes;
		vector<Projectile> _projectiles;
		vector<Monster> _monsters;
		vector<Pipe> _pipes;
		vector<Item> _items;
		vector<Object> _objects;
		vector<Blocks> _blocks;
		vector<vector<BlockOccurrence>> _blocksOccurrences;*/
    };
} // namespace

#endif // HPP_LEVEL
