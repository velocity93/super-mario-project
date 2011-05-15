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
#include "Blocks.hpp"
#include "BlockOccurrence.hpp"
#include "Monster.hpp"
#include "Item.hpp"
#include "Projectile.hpp"
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
        Level() : _levelName(""), _musicTitle(""), _size(Coord<int>()), _spawn(Coord<int>()),
			_checkpoints(vector<Checkpoint*>()), _projectiles(vector<Projectile*>()),
			_monsters(vector<Monster*>()), _pipes(vector<Pipe*>())
			//_finishes(vector<Finish*>()), _backgrounds(vector<Background*>()), 
		{ }

		Coord<int> getSize();
		Coord<int> getBlockSize();
		vector<Object*> getObjects();

		void update(float time);
		void render(RenderWindow& app, Screen& screen);

        virtual ~Level();
		
    private:
		string _levelName;
		string _musicTitle;
		Coord<int> _size;
		Coord<int> _spawn;
		Coord<int> _blockSize;
		vector<Checkpoint*> _checkpoints;
		//vector<Background*> _backgrounds:
		//vector<Finish*> _finishes;
		vector<Projectile*> _projectiles;
		vector<Monster*> _monsters;
		vector<Pipe*> _pipes;
		vector<Item*> _items;
		vector<Object*> _objects;
		vector<Blocks*> _blocks;
		vector<vector<BlockOccurrence*>> _blocksOccurrences;
    };
} // namespace

#endif // HPP_LEVEL
