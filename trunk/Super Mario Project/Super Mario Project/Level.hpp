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

#include <string>

using namespace Collisions;
using namespace Rendering;

namespace SuperMarioProject
{
    class Level
    {
    public:
        Level() : _name(""), _musicTitle(""), _size(Vector2f()), _spawn(Vector2f()),
			_checkpoints(vector<Checkpoint*>()), _projectiles(vector<Projectile*>()),
			_monsters(vector<Monster*>()), _pipes(vector<Pipe*>()), _foregrounds(vector<Foreground*>()),
			_finishes(vector<Finish*>()), _backgrounds(vector<Background*>())
		{ }

		/* Level Name */
		string getName();

		/* Size of level */
		Vector2f getSize();

		/* Size of each block */
		Vector2f getBlockSize();

		/* All objects */
		vector<Object*> getObjects();

		/* All Checkpoints */
		vector<Checkpoint*> getCheckpoints();

		/* All Projectiles */
		vector<Projectile*> getProjectiles();

		/* All monsters */
		vector<Monster*> getMonsters();

		/* All pipes */
		vector<Pipe*> getPipes();

		/* All items */
		vector<Item*> getItems();

		/* All blocks */
		vector<Blocks*> getBlocks();

		/* All backgrounds */
		vector<Background*> getBackgrounds();

		/* All foregrounds */
		vector<Foreground*> getForegrounds();

		/* All finishes */
		vector<Finish*> getFinishes();

		/* Set spawn coord */
		void setSpawn(int x, int y);

		/* Set Level name */
		void setName(string name);

		/* Load Level */
		void loadLevel(string fileName);

		/* Update data */
		void update(RenderWindow& app);
		
		/* Render all objects */
		void render(RenderWindow& app);

        virtual ~Level();
		
    private:
		string _name;
		string _musicTitle;
		Vector2f _size;
		Vector2f _spawn;
		Vector2f _blockSize;
		vector<Checkpoint*> _checkpoints;
		vector<Background*> _backgrounds;
		vector<Foreground*> _foregrounds;
		vector<Finish*> _finishes;
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
