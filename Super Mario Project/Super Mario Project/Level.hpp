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
#include "Item.hpp"
#include "Monster.hpp"
#include "Projectile.hpp"
#include "Finish.hpp"
#include "Pipe.hpp"
#include "Tileset.hpp"
#include "BlockOccurrence.hpp"

#include <string>

using namespace Collisions;
using namespace Rendering;

namespace SuperMarioProject
{
    class Level
    {
    public:
		Level() : _name("") { }

		/* Level Name */
		string& getName();

		/* Level Music title */
		string& getMusicTitle();

		/* Level Spawn */
		Vector2i& getSpawn();

		/* Size of level */
		Vector2i& getSize();

		/* All objects */
		vector<Object*>& getObjects();

		/* All Checkpoints */
		vector<Checkpoint*>& getCheckpoints();

		/* All Projectiles */
		vector<Projectile*>& getProjectiles();

		/* All monsters */
		vector<Monster*>& getMonsters();

		/* All pipes */
		vector<Pipe*>& getPipes();

		/* All items */
		vector<Item*>& getItems();

		/* All backgrounds */
		vector<Background*>& getBackgrounds();

		/* All foregrounds */
		vector<Foreground*>& getForegrounds();

		/* All finishes */
		vector<Finish*>& getFinishes();

		/* All Tilesets */
		vector<Tileset*>& getTilesets();

		/* All Blocks occurrences */
		vector<BlockOccurrence*>& getBlocksOccurrences();

		/* Get index of specific monster */
		int getMonsterIndex(Monster* monster);

		/* Set spawn coord */
		void setSpawnX(int x);

		/* Set spawn coord */
		void setSpawnY(int y);

		/* Set Level name */
		void setName(string name);

		/* Set Level width */
		void setWidth(int width);

		/* Set Level height */
		void setHeight(int height);

		/* Set level music */
		void setMusicTitle(string title);

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

		/* Add Block Occurence */
		void addBlockOccurrence(BlockOccurrence* block);

		/* Load Level */
		void loadLevel(string& fileName);

		/* Save Level */
		void saveLevel(string& fileName);

		/* Update data */
		void updatePhysicData(RenderWindow& app);
		void updateGraphicData(RenderWindow& app);
		
		/* Render all objects */
		void render(RenderWindow& app);

        virtual ~Level();
		
    private:
		string _name;
		string _musicTitle;
		Vector2i _size;
		Vector2i _spawn;
		vector<Checkpoint*> _checkpoints;
		vector<Background*> _backgrounds;
		vector<Foreground*> _foregrounds;
		vector<Finish*> _finishes;
		vector<Projectile*> _projectiles;
		vector<Monster*> _monsters;
		vector<Pipe*> _pipes;
		vector<Item*> _items;
		vector<Object*> _objects;
		vector<Tileset*> _tilesets;

		//Utile étant donné qu'on a une position dans la classe Block ?
		vector<BlockOccurrence*> _blocksOccurrences; 
    };
} // namespace

#endif // HPP_LEVEL
