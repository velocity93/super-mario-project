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
#include "Block.hpp"
#include "MonsterTypes.hpp"
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/parserInternals.h>
#include <libxml/xmlschemas.h>
#include <libxml/xmlschemastypes.h>
#include <cstring>

namespace XMLParsing
{
	/* PARSING WORLD XML */
	void level_tag(World* world, const char ** attrs)
	{
		world->addLevelName(attrs[1]);
	}

	/* PARSING LEVEL XML */
	int id_item;
	int id_monster;
	int id_tileset;

	void level_tag(Level * level, const char **attrs)
	{
		for(int i = 0; i < 8; i = i + 2)
		{
			if(!strcmp(attrs[i], "name"))
			{
				level->setName(attrs[i + 1]);
			}
			else if(!strcmp(attrs[i], "width"))
			{
				level->setWidth(atoi(attrs[i + 1]));
			}
			else if(!strcmp(attrs[i], "height"))
			{
				level->setHeight(atoi(attrs[i + 1]));
			}
			else if(!strcmp(attrs[i], "music"))
			{
				level->setMusicTitle(attrs[i + 1]);
			}
		}
	}

	void spawn_tag(Level * level, const char **attrs)
	{
		for(int i = 0; i < 4; i = i + 2)
		{
			if(!strcmp(attrs[i], "positionX"))
			{
				level->setSpawnX((float)atoi(attrs[i + 1]));
			}
			else if(!strcmp(attrs[i], "positionY"))
			{
				level->setSpawnY((float)atoi(attrs[i + 1]));
			}
		}
	}

	void checkpoint_tag(Level * level, const char **attrs)
	{
		Vector2f position;
		string img = "";

		for(int i = 0; i < 6; i = i + 2)
		{
			if(!strcmp(attrs[i], "positionX"))
			{
				position.x = (float)atoi(attrs[i + 1]);
			}
			else if(!strcmp(attrs[i], "positionY"))
			{
				position.y = level->getSize().y - (float)atoi(attrs[i + 1]);
			}
			else if(!strcmp(attrs[i], "img"))
			{
				img = attrs[i + 1];
			}
		}
		level->addCheckpoint(new Checkpoint(img, position, Checkpoint::NOT_PASSED));
	}

	void background_tag(Level * level, const char **attrs)
	{
		//Vector2f position(atoi(attrs[3]), atoi(attrs[5]));
		//level->addBackground(new Background(attrs[1], position));
		string img = "";

		for(int i = 0; i < 2; i = i + 2)
		{
			if(!strcmp(attrs[i], "img"))
			{
				img = attrs[i + 1];
			}
		}
		level->addBackground(new Background(img));
	}

	void foreground_tag(Level * level, const char **attrs)
	{
		string img = "";

		for(int i = 0; i < 2; i = i + 2)
		{
			if(!strcmp(attrs[i], "img"))
			{
				img = attrs[i + 1];
			}
		}

		level->addForeground(new Foreground(img));
	}

	void object_tag(Level * level, const char **attrs)
	{
		Vector2f position;
		string img = "";

		for(int i = 0; i < 6; i = i + 2)
		{
			if(!strcmp(attrs[i], "positionX"))
			{
				position.x = (float)atoi(attrs[i + 1]);
			}
			else if(!strcmp(attrs[i], "positionY"))
			{
				position.y = level->getSize().y - (float)atoi(attrs[i + 1]);
			}
			else if(!strcmp(attrs[i], "img"))
			{
				img = attrs[i + 1];
			}
		}

		level->addObject(new Object(img, position));
	}

	void finish_tag(Level * level, const char **attrs)
	{
		Vector2f position;
		string img = "";

		for(int i = 0; i < 6; i = i + 2)
		{
			if(!strcmp(attrs[i], "positionX"))
			{
				position.x = (float)atoi(attrs[i + 1]);
			}
			else if(!strcmp(attrs[i], "positionY"))
			{
				position.y = level->getSize().y - (float)atoi(attrs[i + 1]);
			}
			else if(!strcmp(attrs[i], "img"))
			{
				img = attrs[i + 1];
			}
		}

		level->addFinish(new Finish(img, position));
	}

	void projectile_tag(Level * level, const char **attrs)
	{
		string img = "";

		for(int i = 0; i < 2; i = i + 2)
		{
			if(!strcmp(attrs[i], "img"))
			{
				img = attrs[i + 1];
			}
		}
		level->addProjectile(new Projectile(img));
	}

	void item_tag(Level * level, const char **attrs)
	{
		string img = "";
		Item::Type type = Item::COIN;

		for(int i = 0; i < 4; i = i + 2)
		{
			if(!strcmp(attrs[i], "img"))
			{
				img = attrs[i + 1];
			}
			else if(!strcmp(attrs[i], "type"))
			{
				type = (Item::Type)atoi(attrs[i + 1]);
			}
		}
		level->addItem(new Item(img, type));
		id_item++;
	}

	void occ_item_tag(Level * level, const char **attrs)
	{
		Vector2f position;

		for(int i = 0; i < 4; i = i + 2)
		{
			if(!strcmp(attrs[i], "positionX"))
			{
				position.x = (float)atoi(attrs[i + 1]);
			}
			else if(!strcmp(attrs[i], "positionY"))
			{
				position.y = level->getSize().y - (float)atoi(attrs[i + 1]);
			}
		}

		level->getItems()[id_item - 1]->addNewItemOccurrence(position);
	}

	void walking_monster_tag(Level * level, const char **attrs)
	{
		string img = "";

		for(int i = 0; i < 2; i = i + 2)
		{
			if(!strcmp(attrs[i], "name"))
			{
				img = attrs[i + 1];
			}
		}

		level->addMonster(new WalkingMonster(img));
		id_monster++;
	}

	void shell_monster_tag(Level * level, const char **attrs)
	{
		string img = "";

		for(int i = 0; i < 2; i = i + 2)
		{
			if(!strcmp(attrs[i], "name"))
			{
				img = attrs[i + 1];
			}
		}

		level->addMonster(new ShellMonster(img));
		id_monster++;
	}

	void flying_monster_tag(Level * level, const char **attrs)
	{
		string img = "";

		for(int i = 0; i < 2; i = i + 2)
		{
			if(!strcmp(attrs[i], "img"))
			{
				img = attrs[i + 1];
			}
		}

		level->addMonster(new FlyingMonster(img));
		id_monster++;
	}

	void occ_monster_tag(Level * level, const char **attrs)
	{
		Vector2f position;

		for(int i = 0; i < 4; i = i + 2)
		{
			if(!strcmp(attrs[i], "positionX"))
			{
				position.x = (float)atoi(attrs[i + 1]);
			}
			else if(!strcmp(attrs[i], "positionY"))
			{
				position.y = level->getSize().y - (float)atoi(attrs[i + 1]);
			}
		}
		level->getMonsters()[id_monster - 1]->addNewMonsterOccurrence(position);
	}

	void pipe_tag(Level * level, const char **attrs)
	{
		Vector2f position;
		string img = "", level_destination = "";
		string monster_name = "";
		int id_PipeDestination = -1;
		int length = 1;
		Pipe::State state = Pipe::CLOSED;
		Pipe::Direction direction = Pipe::TO_TOP;

		for(int i = 0; i < 18; i = i + 2)
		{
			if(!strcmp(attrs[i], "positionX"))
			{
				position.x = (float)atoi(attrs[i + 1]);
			}
			else if(!strcmp(attrs[i], "positionY"))
			{
				position.y = level->getSize().y - (float)atoi(attrs[i + 1]);
			}
			else if(!strcmp(attrs[i], "img"))
			{
				img = attrs[i + 1];
			}
			else if(!strcmp(attrs[i], "state"))
			{
				state = (Pipe::State)atoi(attrs[i + 1]);
			}
			else if(!strcmp(attrs[i], "destination_pipe"))
			{
				id_PipeDestination = atoi(attrs[i + 1]);
			}
			else if(!strcmp(attrs[i], "level_destination"))
			{
				level_destination = attrs[i + 1];
			}
			else if(!strcmp(attrs[i], "length"))
			{
				length = atoi(attrs[i + 1]);
			}
			else if(!strcmp(attrs[i], "direction"))
			{
				direction = (Pipe::Direction)atoi(attrs[i + 1]);
			}
			else if(!strcmp(attrs[i], "monster"))
			{
				monster_name = attrs[i + 1];
			}
		}

		if(monster_name != "")
		{
			level->addPipe(new Pipe(
				img,
				position,
				id_PipeDestination,
				level_destination,
				state,
				length,
				direction,
				new Monster(monster_name)));
		}
		else
		{
			level->addPipe(new Pipe(
				img,
				position,
				id_PipeDestination,
				level_destination,
				state,
				length,
				direction,
				nullptr));
		}
	}

	// <tileset img="nomTexture.png">
	void tileset_tag(Level * level, const char **attrs)
	{
		string img = "";

		for(int i = 0; i < 2; i = i + 2)
		{
			if(!strcmp(attrs[i], "img"))
			{
				img = attrs[i + 1];
			}
		}
		Tileset* tileset = new Tileset(img);
		level->addTileset(tileset);
		id_tileset++;
	}

	// <block physIndex="" type="" />
	void block_tag(Level * level, const char **attrs)
	{
		int physicIndex = 0;
		int type = 0;

		for(int i = 0; i < 4; i = i + 2)
		{
			if(!strcmp(attrs[i], "physicIndex"))
			{
				physicIndex = atoi(attrs[i + 1]);
			}
			else if(!strcmp(attrs[i], "type_bloc"))
			{
				type = atoi(attrs[i + 1]);
			}
		}

		Tileset* tileset = level->getTilesets()[id_tileset - 1];
		tileset->addBlock(physicIndex, type);
	}

	//<occ_block actualModel="" alternativeModel="" pos="x:y"/>
	void occ_block_tag(Level* level, const char** attrs)
	{
		Vector2f position;
		int id_model = -1, 
			id_alternative = -1, 
			id_item = -1,
			id_tileset_actual = -1, 
			id_tileset_alt = -1;

		for(int i = 0; i < 14; i = i + 2)
		{
			if(!strcmp(attrs[i], "positionX"))
			{
				position.x = (float)atoi(attrs[i + 1]);
			}
			else if(!strcmp(attrs[i], "positionY"))
			{
				position.y = level->getSize().y - (float)atoi(attrs[i + 1]);
			}
			else if(!strcmp(attrs[i], "actual"))
			{
				id_model = atoi(attrs[i + 1]);
			}
			else if(!strcmp(attrs[i], "alt"))
			{
				id_alternative = atoi(attrs[i + 1]);
			}
			else if(!strcmp(attrs[i], "item"))
			{
				id_item = atoi(attrs[i + 1]);
			}
			else if(!strcmp(attrs[i], "tileset_actual"))
			{
				id_tileset_actual = atoi(attrs[i + 1]);
			}
			else if(!strcmp(attrs[i], "tileset_alt"))
			{
				id_tileset_alt = atoi(attrs[i + 1]);
			}
		}

		if(id_tileset_actual > -1)
		{
			Tileset* tileset = level->getTilesets()[id_tileset_actual];
			if(tileset != nullptr)
			{
				Tileset* tileset_alt = level->getTilesets()[id_tileset_alt];

				if(tileset_alt != nullptr && id_model > -1)
				{
					BlockOccurrence* block;
					if(id_alternative > -1)
					{
						block = tileset->getBlocks()[id_model]->addNewBlockOccurrence(tileset_alt->getBlocks()[id_alternative], position);
					}
					else
					{
						block = tileset->getBlocks()[id_model]->addNewBlockOccurrence(nullptr, position);
					}

					level->addBlockOccurrence(block);
				}
			}
		}
	}

	void error(void * /*ctx*/, const char * msg, ...)
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
			BAD_CAST"occ_block"
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
			occ_block_tag
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

	void parseLevel(string fileName, Level* level)
	{
		/* Initialization of ids */
		id_monster = 0;
		id_tileset = 0;
		id_item = 0;

		xmlSAXHandler sh = {NULL};
		sh.startElement = start_level_element;
		sh.error = error;

		xmlSAXUserParseFile(&sh, level, fileName.c_str());
	}

	void start_world_element(void *user_data, const xmlChar *name, const xmlChar **attrs) 
	{
		if(!xmlStrcmp(name, BAD_CAST"level"))
			level_tag((World*)user_data, (const char**)attrs);
	}

	void parseWorld(string fileName, World* world)
	{
		xmlSAXHandler sh = {NULL};
		sh.startElement = start_world_element;
		sh.error = XMLParsing::error;

		xmlSAXUserParseFile(&sh, world, fileName.c_str());
	}
}


namespace SuperMarioProject
{
	void XMLParser::loadLevel(string fileName, Level* level)
	{
		if(validateSchema("levels/level.xsd", fileName.c_str()) == 0)
			XMLParsing::parseLevel(fileName, level);
	}

	void XMLParser::loadWorld(string fileName, World* world)
	{
		if(validateSchema("worlds/world.xsd", fileName.c_str()) == 0)
			XMLParsing::parseWorld(fileName, world);
	}

	int XMLParser::validateSchema(const char * XMLSchemaFile_shorterNamename, const char * XMLfile_shorterNamename)
	{
		xmlSchemaPtr ptr_schema = NULL;
		xmlSchemaParserCtxtPtr ptr_ctxt;
		xmlSchemaValidCtxtPtr ptr_validctxt;
		int vl_return = 0;
		xmlDocPtr vl_doc;


		/* Open Xml Schema File */
		ptr_ctxt = xmlSchemaNewParserCtxt(XMLSchemaFile_shorterNamename);
		xmlSchemaSetParserErrors(ptr_ctxt,
			(xmlSchemaValidityErrorFunc) fprintf,
			(xmlSchemaValidityWarningFunc) fprintf,
			stderr);

		ptr_schema = xmlSchemaParse(ptr_ctxt);
		xmlSchemaFreeParserCtxt(ptr_ctxt);

		/* If xml schema file wasn't loaded correctly */
		if (ptr_schema == NULL)
		{
			cout << "XMLSCHEMA: Could not open XML Schema " << XMLSchemaFile_shorterNamename << endl;
			xmlSchemaCleanupTypes();
			xmlCleanupParser();
			xmlMemoryDump();
			return -1;
		}

		vl_doc = xmlReadFile(XMLfile_shorterNamename,NULL,0);

		/* If xml file wasn't loaded correctly */
		if (vl_doc == NULL) 
		{
			cout << "XML: Could not parse " << XMLfile_shorterNamename << endl;
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
				cout << "XMLSCHEMA VERDICT : Xml file " << XMLfile_shorterNamename << " is OK." << endl;
			} 
			else if (vl_return > 0)
			{ 
				// If XML File doesn't correspond to Schema
				cout << "XMLSCHEMA VERDICT : Xml file " << XMLfile_shorterNamename <<  " fails to validate." << endl;
			} 
			else 
			{ 
				// Other error
				cout << "XMLSCHEMA VERDICT : " << XMLfile_shorterNamename << " validation generated an internal error." << endl;
			}

			xmlSchemaFreeValidCtxt(ptr_validctxt);
			xmlFreeDoc(vl_doc);
		}

		return vl_return;
	}
}
