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
		level->addBackground(new Background(attrs[1], Vector2f(0, 0)));
	}

	void foreground_tag(Level * level, const char **attrs)
	{
		level->addForeground(new Foreground(attrs[1]));
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
			/*BAD_CAST"object",
			BAD_CAST"finish",
			BAD_CAST"projectile",
			BAD_CAST"item",
			BAD_CAST"occ_item",			
			BAD_CAST"monster", 
			BAD_CAST"occ",			
			BAD_CAST"pipe",
			BAD_CAST"blocs", 
			BAD_CAST"textures", 
			BAD_CAST"bloc", 
			BAD_CAST"layers", 
			BAD_CAST"layer",
			BAD_CAST"occ_block"*/
		};
		static const balise_func functions[] = {
			level_tag,
			spawn_tag,
			checkpoint_tag,
			background_tag,
			foreground_tag,
			/*balise_object,			
			balise_finish,			
			balise_projectile,			
			balise_item,
			balise_occ_item,
			balise_monster,
			balise_occ,
			balise_pipe,
			balise_blocs,
			balise_textures,
			balise_bloc,
			balise_layers,
			balise_layer,
			balise_occ_block*/
		};
		int i;

		for(i = 0; i < 5; i++)
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