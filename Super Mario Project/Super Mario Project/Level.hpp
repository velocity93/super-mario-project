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

#include <SFML/System.hpp>
#include <string>
#include <vector>

// forward declaration
namespace sf { class RenderWindow; }

namespace smp
{
	// forward declaration
	class QuadTree;
	class Checkpoint;
	class Background;
	class Foreground;
	class Monster;
	class Pipe;
	class Item;
	class BlockOccurrence;
	class Object;
	class Tileset;
	class Finish;
	class Projectile;

    class Level
    {
    public:
		Level() : _name("") { }

		/* Level Name */
		const std::string& getName();

		/* Level Music title */
		const std::string& getMusicTitle();

		/* Level Spawn */
		sf::Vector2f& getSpawn();

		/* Size of level */
		sf::Vector2i& getSize();

		/* All objects */
		std::vector<Object*>& getObjects();

		/* All Checkpoints */
		std::vector<Checkpoint*>& getCheckpoints();

		/* All Projectiles */
		std::vector<Projectile*>& getProjectiles();

		/* All monsters */
		std::vector<Monster*>& getMonsters();

		/* All pipes */
		std::vector<Pipe*>& getPipes();

		/* All items */
		std::vector<Item*>& getItems();

		/* All backgrounds */
		std::vector<Background*>& getBackgrounds();

		/* All foregrounds */
		std::vector<Foreground*>& getForegrounds();

		/* All finishes */
		std::vector<Finish*>& getFinishes();

		/* All Tilesets */
		std::vector<Tileset*>& getTilesets();

		/* All Blocks occurrences */
		std::vector<BlockOccurrence*>& getBlocksOccurrences();

		/* Set spawn coord */
		void setSpawnX(float x);

		/* Set spawn coord */
		void setSpawnY(float y);

		/* Set Level name */
		void setName(const std::string &name);

		/* Set Level width */
		void setWidth(int width);

		/* Set Level height */
		void setHeight(int height);

		/* Set level music */
		void setMusicTitle(const std::string &title);

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
		void loadLevel(const std::string& fileName);

		/* Save Level */
		void saveLevel(const std::string& fileName);

		/* Update Graphic and physic data */
		void update(float time, QuadTree* tree, sf::RenderWindow& app);
		
		/* Render all objects */
		void render(sf::RenderWindow& app);

        virtual ~Level();
		
    private:
		std::string _name;
		std::string _musicTitle;
		sf::Vector2i _size;
		sf::Vector2f _spawn;
		std::vector<Checkpoint*> _checkpoints;
		std::vector<Background*> _backgrounds;
		std::vector<Foreground*> _foregrounds;
		std::vector<Finish*> _finishes;
		std::vector<Projectile*> _projectiles;
		std::vector<Monster*> _monsters;
		std::vector<Pipe*> _pipes;
		std::vector<Item*> _items;
		std::vector<Object*> _objects;
		std::vector<Tileset*> _tilesets;

		//Utile étant donné qu'on a une position dans la classe Block ?
		std::vector<BlockOccurrence*> _blocksOccurrences; 
    };
} // namespace

#endif // HPP_LEVEL
