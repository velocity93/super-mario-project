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

	/*void level_tag(Level * level, const char **attrs)
	{
		level->setName(attrs[1]);
	}*/

	/*void spawn_tag(Level * level, const char **attrs)
	{
		level->setSpawn(atoi(attrs[1]), atoi(strchr(attrs[1], ':') + 1));
	}

	//void start_level_element(void *user_data, const xmlChar *name, const xmlChar **attrs) 
	//{
	//	static const xmlChar *elements[] = {
	//		BAD_CAST"level", 
	//		BAD_CAST"spawn", 
	//		/*BAD_CAST"checkpoints", 
	//		BAD_CAST"checkpoint", 
	//		BAD_CAST"backgrounds", 
	//		BAD_CAST"background",
	//		BAD_CAST"background_generators",
	//		BAD_CAST"background_generator",
	//		BAD_CAST"foregrounds", 
	//		BAD_CAST"foreground",
	//		BAD_CAST"foreground_generators",
	//		BAD_CAST"foreground_generator",
	//		BAD_CAST"objects",
	//		BAD_CAST"object",
	//		BAD_CAST"finishes",
	//		BAD_CAST"finish",
	//		BAD_CAST"projectiles",
	//		BAD_CAST"projectile",
	//		BAD_CAST"items",
	//		BAD_CAST"item",
	//		BAD_CAST"occ_item",
	//		BAD_CAST"monsters", 
	//		BAD_CAST"monster", 
	//		BAD_CAST"occ",
	//		BAD_CAST"pipes",
	//		BAD_CAST"pipe",
	//		BAD_CAST"blocs", 
	//		BAD_CAST"textures", 
	//		BAD_CAST"bloc", 
	//		BAD_CAST"layers", 
	//		BAD_CAST"layer",
	//		BAD_CAST"occ_block"*/
	//	};
	//	static const balise_func functions[] = {
	//		level_tag,
	//		spawn_tag,
	//		/*balise_checkpoints,
	//		balise_checkpoint,
	//		balise_backgrounds,
	//		balise_background,
	//		balise_background_generators,
	//		balise_background_generator,
	//		balise_foregrounds,
	//		balise_foreground,
	//		balise_foreground_generators,
	//		balise_foreground_generator,
	//		balise_objects,
	//		balise_object,
	//		balise_finishes,
	//		balise_finish,
	//		balise_projectiles,
	//		balise_projectile,
	//		balise_items,
	//		balise_item,
	//		balise_occ_item,
	//		balise_monsters,
	//		balise_monster,
	//		balise_occ,
	//		balise_pipes,
	//		balise_pipe,
	//		balise_blocs,
	//		balise_textures,
	//		balise_bloc,
	//		balise_layers,
	//		balise_layer,
	//		balise_occ_block*/
	//	};
	//	int i;

	//	for(i = 0; i < 2; i++)
	//	{
	//		if(!xmlStrcmp(name, elements[i]))
	//		{
	//			functions[i]((Level*)user_data, (const char **)attrs);
	//			break;
	//		}
	//	}	
	//}

	void XMLParser::loadLevel(string fileName, Level* level)
	{
		/*xmlSAXHandler sh = {NULL};
		sh.startElement = start_level_element;
		sh.error = error;

		if(xmlSAXUserParseFile(&sh, level, fileName.c_str()))
			puts("Error in reading XML level file");*/
	}
	

	void start_world_element(void *user_data, const xmlChar *name, const xmlChar **attrs) 
	{
		if(!xmlStrcmp(name, BAD_CAST"level"))
			level_tag((World*)user_data, (const char**)attrs);
	}

	void error(void * ctx, const char * msg, ...)
	{
		cout << "error parsing XML :" << msg << endl;
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