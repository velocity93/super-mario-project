////////////////////////////////////////////////////////////////////////
// XMLParser.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "XMLParser.hpp"
#include "World.hpp"
#include "Level.hpp"
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/parserInternals.h>

namespace SuperMarioProject
{
	void level_tag(World* world, const char ** attrs)
	{
		world->addLevelName(attrs[1]);
	}

	void level_tag(Level * level, const char **attrs)
	{
		/* Name and size */
		level->setName(attrs[1]);
		level->setSize(atoi(attrs[3]), atoi(strchr(attrs[3], ':') + 1));

		/* Music */
		level->setMusicTitle(attrs[5]);
	}

	void spawn_tag(Level * level, const char **attrs)
	{
		level->setSpawn(atoi(attrs[1]), atoi(strchr(attrs[1], ':') + 1));
	}

	void checkpoint_tag(Level * level, const char **attrs)
	{
		Vector2f position(atoi(attrs[3]), atoi(strchr(attrs[3], ':') + 1));
		level->addCheckpoint(new Checkpoint(attrs[1], position, Checkpoint::State::NOT_PASSED));
	}

	void background_tag(Level * level, const char **attrs)
	{
		Vector2f position(atoi(attrs[3]), atoi(strchr(attrs[3], ':') + 1));
		level->addBackground(new Background(attrs[1], position));
	}

	void foreground_tag(Level * level, const char **attrs)
	{
		level->addForeground(new Foreground(attrs[1]));
	}

	void object_tag(Level * level, const char **attrs)
	{
		Vector2f position(atoi(attrs[3]), atoi(strchr(attrs[3], ':') + 1));
		level->addObject(new Object(attrs[1], position));
	}

	void finish_tag(Level * level, const char **attrs)
	{
		Vector2f position(atoi(attrs[3]), atoi(strchr(attrs[3], ':') + 1));
		level->addFinish(new Finish(attrs[1], position));
	}

	void projectile_tag(Level * level, const char **attrs)
	{
		level->addProjectile(new Projectile(attrs[1]));
	}

	int id_item = 0;
	void item_tag(Level * level, const char **attrs)
	{
		level->addItem(new Item(attrs[1], (Item::Type)atoi(attrs[3])));
		id_item++;
	}

	void occ_item_tag(Level * level, const char **attrs)
	{
		Vector2f position(atoi(attrs[1]), atoi(strchr(attrs[1], ':') + 1));
		level->getItems()[id_item - 1]->addNewItemOccurrence(position);
	}

	int id_monster = 0;
	void monster_tag(Level * level, const char **attrs)
	{
		level->addMonster(new Monster(attrs[1]));
		id_monster++;
	}

	void occ_monster_tag(Level * level, const char **attrs)
	{
		Vector2f position(atoi(attrs[1]), atoi(strchr(attrs[1], ':') + 1));
		level->getMonsters()[id_monster - 1]->addNewMonsterOccurrence(position);
	}

	void pipe_tag(Level * level, const char **attrs)
	{
		Vector2f position(atoi(attrs[3]), atoi(strchr(attrs[3], ':') + 1));
		level->addPipe(new Pipe(
			attrs[1],
			position,
			atoi(attrs[5]),
			attrs[7],
			(Door::State)atoi(attrs[9]),
			atoi(attrs[11]),
			(Pipe::Direction)atoi(attrs[13]),
			level->getMonsters()[atoi(attrs[15])]));
	}

	int id_tileset = 0;
	// <tileset img="nomTexture.png" size="x:y">
	void tileset_tag(Level * level, const char **attrs)
	{
		Tileset* tileset = new Tileset(attrs[1]);
		level->addTileset(tileset);
		level->setBlockSize(atoi(attrs[3]), atoi(strchr(attrs[3], ':') + 1));
		id_tileset++;
	}

	// <block physIndex="" />
	void blocks_tag(Level * level, const char **attrs)
	{
		Block* block = new Block(level->getTilesets()[id_tileset - 1], atoi(attrs[1]));
		level->addBlock(block);
	}

	//<occ_block actualModel="" alternativeModel="" pos="x:y"/>
	void occ_blocks_tag(Level* level, const char** attrs)
	{
		Vector2f position(atoi(attrs[5]), atoi(strchr(attrs[5], ':') + 1));
		Block* model = level->getBlock()[atoi(attrs[1])];
		model->addNewBlockOccurrence(level->getBlock()[atoi(attrs[3])], position);
	}

	void error(void * ctx, const char * msg, ...)
	{
		cout << "error parsing XML :" << msg << endl;
	}

	void start_level_element(void *user_data, const xmlChar *name, const xmlChar **attrs) 
	{
		static const xmlChar *elements[] = {
			BAD_CAST"level", 
			BAD_CAST"spawn", 
			BAD_CAST"checkpoint", 
			BAD_CAST"background",
			BAD_CAST"foreground",
			BAD_CAST"object",
			BAD_CAST"finish",
			BAD_CAST"projectile",
			BAD_CAST"item",
			BAD_CAST"occ_item",
			BAD_CAST"monster", 
			BAD_CAST"occ_monster",			
			BAD_CAST"pipe",
			BAD_CAST"tileset",
			BAD_CAST"blocks", 
			BAD_CAST"occ_blocks"
		};
		static const balise_func functions[] = {
			level_tag,
			spawn_tag,
			checkpoint_tag,
			background_tag,
			foreground_tag,
			object_tag,
			finish_tag,			
			projectile_tag,
			item_tag,
			occ_item_tag,
			monster_tag,
			occ_monster_tag,
			pipe_tag,
			tileset_tag,
			blocks_tag,
			occ_blocks_tag
		};
		int i;

		for(i = 0; i < 16; i++)
		{
			if(!xmlStrcmp(name, elements[i]))
			{
				functions[i]((Level*)user_data, (const char **)attrs);
				break;
			}
		}	
	}

	void XMLParser::loadLevel(string fileName, Level* level)
	{
		xmlSAXHandler sh = {NULL};
		sh.startElement = start_level_element;
		sh.error = error;

		if(xmlSAXUserParseFile(&sh, level, fileName.c_str()))
			puts("Error in reading XML level file");

		id_monster = 0;
		id_tileset = 0;
	}

	void start_world_element(void *user_data, const xmlChar *name, const xmlChar **attrs) 
	{
		if(!xmlStrcmp(name, BAD_CAST"level"))
			level_tag((World*)user_data, (const char**)attrs);
	}

	void XMLParser::loadWorld(string fileName, World* world)
	{
		xmlSAXHandler sh = {NULL};
		sh.startElement = start_world_element;
		sh.error = error;

		if(xmlSAXUserParseFile(&sh, world, fileName.c_str()))
			puts("Error in reading XML level file");
	}
}