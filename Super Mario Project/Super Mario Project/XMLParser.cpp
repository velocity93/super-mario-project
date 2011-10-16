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
#include <libxml/xmlschemas.h>
#include <libxml/xmlschemastypes.h>

namespace SuperMarioProject
{
	int id_item;
	int id_monster;
	int id_tileset;

	void level_tag(World* world, const char ** attrs)
	{
		world->addLevelName(attrs[1]);
	}

	void level_tag(Level * level, const char **attrs)
	{
		/* Name and size */
		level->setName(attrs[1]);
		level->setSize(atoi(attrs[3]), atoi(attrs[5]));

		/* Music */
		level->setMusicTitle(attrs[7]);
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
		//Vector2f position(atoi(attrs[3]), atoi(strchr(attrs[3], ':') + 1));
		//level->addBackground(new Background(attrs[1], position));
		level->addBackground(new Background(attrs[1]));
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

	void walking_monster_tag(Level * level, const char **attrs)
	{
		level->addMonster(new WalkingMonster(attrs[1]));
		id_monster++;
	}

	void shell_monster_tag(Level * level, const char **attrs)
	{
		level->addMonster(new ShellMonster(attrs[1]));
		id_monster++;
	}

	void flying_monster_tag(Level * level, const char **attrs)
	{
		level->addMonster(new FlyingMonster(attrs[1]));
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
		int index_monster = atoi(attrs[15]);

		if(index_monster >= 0)
		{
			level->addPipe(new Pipe(
				attrs[1],
				position,
				atoi(attrs[5]),
				attrs[7],
				(Pipe::State)atoi(attrs[9]),
				atoi(attrs[11]),
				(Pipe::Direction)atoi(attrs[13]),
				level->getMonsters()[index_monster]));
		}
		else
		{
			level->addPipe(new Pipe(
				attrs[1],
				position,
				atoi(attrs[5]),
				attrs[7],
				(Pipe::State)atoi(attrs[9]),
				atoi(attrs[11]),
				(Pipe::Direction)atoi(attrs[13]),
				nullptr));
		}
	}

	// <tileset img="nomTexture.png" size="x:y">
	void tileset_tag(Level * level, const char **attrs)
	{
		Tileset* tileset = new Tileset(attrs[1]);
		level->addTileset(tileset);
		level->setBlockSize(atoi(attrs[3]), atoi(strchr(attrs[3], ':') + 1));
		id_tileset++;
	}

	// <block physIndex="" />
	void block_tag(Level * level, const char **attrs)
	{
		Block* block = new Block(level->getTilesets()[id_tileset - 1], atoi(attrs[1]), atoi(attrs[3]));
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
			BAD_CAST"walking_monster", 
			BAD_CAST"shell_monster", 
			BAD_CAST"flying_monster", 
			BAD_CAST"occ_monster",			
			BAD_CAST"pipe",
			BAD_CAST"tileset",
			BAD_CAST"block", 
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
			walking_monster_tag,
			shell_monster_tag,
			flying_monster_tag,
			occ_monster_tag,
			pipe_tag,
			tileset_tag,
			block_tag,
			occ_blocks_tag
		};
		int i;

		for(i = 0; i < 18; i++)
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
		/* Initialization of ids */
		id_monster = 0;
		id_tileset = 0;
		id_item = 0;

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

	/**
	* Valider un fichier XML à partir d'un fichier XML Schema
	**/
	int XMLParser::validateSchema(char * XMLSchemaFile_pathname, char * XMLfile_pathname)
	{
		xmlSchemaPtr ptr_schema = NULL;
		xmlSchemaParserCtxtPtr ptr_ctxt;
		xmlSchemaValidCtxtPtr ptr_validctxt;
		int vl_return;
		xmlDocPtr vl_doc;
		HINSTANCE vl_hModule;


		/* Open Xml Schema File */
		ptr_ctxt = xmlSchemaNewParserCtxt(XMLSchemaFile_pathname);
		xmlSchemaSetParserErrors(ptr_ctxt,
			(xmlSchemaValidityErrorFunc) fprintf,
			(xmlSchemaValidityWarningFunc) fprintf,
			stderr);

		ptr_schema = xmlSchemaParse(ptr_ctxt);
		xmlSchemaFreeParserCtxt(ptr_ctxt);

		/* If xml schema file wasn't loaded correctly */
		if (ptr_schema == NULL)
		{
			cout << "XMLSCHEMA: Could not open XML Schema " << XMLSchemaFile_pathname << endl;
			xmlSchemaCleanupTypes();
			xmlCleanupParser();
			xmlMemoryDump();
			FreeLibrary(vl_hModule);
			return -1;
		}

		vl_doc = xmlReadFile(XMLfile_pathname,NULL,0);

		/* If xml file wasn't loaded correctly */
		if (vl_doc == NULL) 
		{
			cout << "XML: Could not parse " << XMLfile_pathname << endl;
		} 
		else 
		{
			/* Loading XML Schema */
			ptr_validctxt = xmlSchemaNewValidCtxt(ptr_schema);
			xmlSchemaSetValidErrors(ptr_validctxt,
				(xmlSchemaValidityErrorFunc) fprintf,
				(xmlSchemaValidityWarningFunc) fprintf,
				stderr);

			/* On valide le fichier XML à partir de la structure du XML Schema */
			vl_return = xmlSchemaValidateDoc(ptr_validctxt, vl_doc);

			if (vl_return == 0)
			{ 
				// If the XML file is valid
				cout << "XMLSCHEMA VERDICT : Xml file " << XMLfile_pathname << "is OK." << endl;
			} 
			else if (vl_return > 0)
			{ 
				// If XML File doesn't correpsond to Schema
				cout << "XMLSCHEMA VERDICT : Xml file " << XMLfile_pathname <<  " fails to validate." << endl;
			} 
			else 
			{ 
				// Other error
				cout << "XMLSCHEMA VERDICT : " << XMLfile_pathname << " validation generated an internal error." << endl;
			}

			xmlSchemaFreeValidCtxt(ptr_validctxt);
			xmlFreeDoc(vl_doc);
		}

		FreeLibrary(vl_hModule);	
		return(0);
	}

}