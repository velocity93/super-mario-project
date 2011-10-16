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
#include "Block.hpp"
#include "BlockOccurrence.hpp"
#include "MonsterTypes.hpp"
#include "Item.hpp"
#include "Projectile.hpp"
#include "Finish.hpp"
#include "Pipe.hpp"
#include "Tileset.hpp"

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
		vector<Block*> getBlock();

		/* All backgrounds */
		vector<Background*> getBackgrounds();

		/* All foregrounds */
		vector<Foreground*> getForegrounds();

		/* All finishes */
		vector<Finish*> getFinishes();

		/* All Tilesets */
		vector<Tileset*> getTilesets();

		/* Set spawn coord */
		void setSpawn(int x, int y);

		/* Set block size */
		void setBlockSize(int x, int y);

		/* Set Level name */
		void setName(string name);

		/* Set Level size */
		void setSize(int x, int y);

		/* Set level music */
		void setMusicTitle(string title);

		/* Set Nb Checkpoints */
		void setNbCheckpoints(int nbCheckpoints);

		/* Add Checkpoint */
		void addCheckpoint(Checkpoint* checkpoint);

		/* Add Background */
		void addBackground(Background* background);

		/* Add Foreground */
		void addForeground(Foreground* foreground);

		/* Add Object */
		void addObject(Object* object);

		/* Add Finish */
		void addFinish(Finish* finish);

		/* Add Projectile */
		void addProjectile(Projectile* projectile);

		/* Add Item */
		void addItem(Item* item);

		/* Add Monster */
		void addMonster(Monster* monster);

		/* Add Pipe */
		void addPipe(Pipe* pipe);

		/* Add Tileset */
		void addTileset(Tileset* tileset);

		/* Add Block */
		void addBlock(Block* blocks);

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
		vector<Block*> _blocks;
		vector<Tileset*> _tilesets;

		//Utile étant donné qu'on a une position dans la classe Block ?
		//vector<vector<BlockOccurrence*>> _blocksOccurrences; 
    };
} // namespace

#endif // HPP_LEVEL
