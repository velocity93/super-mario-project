////////////////////////////////////////////////////////////////////////
// XMLLevelParser.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "XMLLevelParser.hpp"
#include "Level.hpp"
#include "MonsterTypes.hpp"
#include "Background.hpp"
#include "Foreground.hpp"
#include "Object.hpp"
#include "Finish.hpp"
#include "Projectile.hpp"
#include "Item.hpp"
#include "Checkpoint.hpp"
#include "Pipe.hpp"
#include "Tileset.hpp"
#include "Block.hpp"
#include "ResourceManager.hpp"
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/parserInternals.h>
#include <libxml/xmlschemas.h>
#include <libxml/xmlschemastypes.h>
#include <cstring>

using namespace std;
using sf::Vector2f;

namespace smp
{
	/* PARSING LEVEL XML */
	int id_item;
	int id_monster;
	int id_tileset;

	void level_tag(XMLLevelContext * lvlctxt, const char **attrs)
	{
		Level* level = (Level*)(lvlctxt->ctxt);

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

	void spawn_tag(XMLLevelContext * lvlctxt, const char **attrs)
	{
		Level* level = (Level*)(lvlctxt->ctxt);

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

	void checkpoint_tag(XMLLevelContext * lvlctxt, const char **attrs)
	{
		Vector2f position;
		string img = "";
		Level* level = (Level*)(lvlctxt->ctxt);

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

	void background_tag(XMLLevelContext * lvlctxt, const char **attrs)
	{
		//Vector2f position(atoi(attrs[3]), atoi(attrs[5]));
		//level->addBackground(new Background(attrs[1], position));
		string img = "";
		Level* level = (Level*)(lvlctxt->ctxt);

		for(int i = 0; i < 2; i = i + 2)
		{
			if(!strcmp(attrs[i], "img"))
			{
				img = attrs[i + 1];
			}
		}
		level->addBackground(new Background(img));
	}

	void foreground_tag(XMLLevelContext * lvlctxt, const char **attrs)
	{
		string img = "";
		Level* level = (Level*)(lvlctxt->ctxt);

		for(int i = 0; i < 2; i = i + 2)
		{
			if(!strcmp(attrs[i], "img"))
			{
				img = attrs[i + 1];
			}
		}

		level->addForeground(new Foreground(img));
	}

	void object_tag(XMLLevelContext * lvlctxt, const char **attrs)
	{
		Vector2f position;
		string img = "";
		Level* level = (Level*)(lvlctxt->ctxt);

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

	void finish_tag(XMLLevelContext * lvlctxt, const char **attrs)
	{
		Vector2f position;
		string img = "";
		Level* level = (Level*)(lvlctxt->ctxt);

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

	void projectile_tag(XMLLevelContext * lvlctxt, const char **attrs)
	{
		string img = "";
		Level* level = (Level*)(lvlctxt->ctxt);

		for(int i = 0; i < 2; i = i + 2)
		{
			if(!strcmp(attrs[i], "img"))
			{
				img = attrs[i + 1];
			}
		}
		level->addProjectile(new Projectile(img));
	}

	void item_tag(XMLLevelContext * lvlctxt, const char **attrs)
	{
		string img = "";
		Item::Type type = Item::COIN;
		Level* level = (Level*)(lvlctxt->ctxt);

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

	void occ_item_tag(XMLLevelContext * lvlctxt, const char **attrs)
	{
		Vector2f position;
		Level* level = (Level*)(lvlctxt->ctxt);

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

	void walking_monster_tag(XMLLevelContext * lvlctxt, const char **attrs)
	{
		string img = "";
		Level* level = (Level*)(lvlctxt->ctxt);

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

	void shell_monster_tag(XMLLevelContext * lvlctxt, const char **attrs)
	{
		string img = "";
		Level* level = (Level*)(lvlctxt->ctxt);

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

	void flying_monster_tag(XMLLevelContext * lvlctxt, const char **attrs)
	{
		string img = "";
		Level* level = (Level*)(lvlctxt->ctxt);

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

	void occ_monster_tag(XMLLevelContext * lvlctxt, const char **attrs)
	{
		Vector2f position;
		Level* level = (Level*)(lvlctxt->ctxt);

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

	void pipe_tag(XMLLevelContext * lvlctxt, const char **attrs)
	{
		Vector2f position;
		string img = "", level_destination = "";
		string monster_name = "";
		int id_PipeDestination = -1;
		int length = 1;
		Pipe::State state = Pipe::CLOSED;
		Pipe::Direction direction = Pipe::TO_TOP;
		Level* level = (Level*)(lvlctxt->ctxt);

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
				ResourceManager::getMonster(monster_name)));
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
	void tileset_tag(XMLLevelContext * lvlctxt, const char **attrs)
	{
		string img = "";
		Level* level = (Level*)(lvlctxt->ctxt);

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
	void block_tag(XMLLevelContext * lvlctxt, const char **attrs)
	{
		int physicIndex = 0;
		int type = 0;
		Level* level = (Level*)(lvlctxt->ctxt);

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
	void occ_block_tag(XMLLevelContext * lvlctxt, const char **attrs)
	{
		Vector2f position;
		int id_model = -1, 
			id_alternative = -1, 
			id_item = -1,
			id_tileset_actual = -1, 
			id_tileset_alt = -1;
		Level* level = (Level*)(lvlctxt->ctxt);

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

	static void error(void * /*ctx*/, const char * msg, ...)
	{
		cout << "error parsing level XML :" << msg << endl;
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
				functions[i]((XMLLevelContext*)user_data, (const char **)attrs);
				break;
			}
		}	
	}

	void parseLevel(string fileName, Level* level)
	{
		XMLLevelContext lvlCtxt;

		/* Initialization of context */
		lvlCtxt.ctxt = level;
		lvlCtxt.id_monster = 0;
		lvlCtxt.id_tileset = 0;
		lvlCtxt.id_item = 0;

		xmlSAXHandler sh = {NULL};
		sh.startElement = start_level_element;
		sh.error = error;

		xmlSAXUserParseFile(&sh, &lvlCtxt, fileName.c_str());
	}


	XMLLevelParser* XMLLevelParser::_parser = nullptr;

	XMLLevelParser* XMLLevelParser::getParser()
	{
		if(_parser == nullptr)
		{
			_parser = new XMLLevelParser();
		}

		return _parser;
	}

	void XMLLevelParser::loadLevel(string fileName, Level* level)
	{
		if(validateSchema("levels/level.xsd", fileName.c_str()) == 0)
			parseLevel(fileName, level);
	}

	void XMLLevelParser::killParser()
	{
		delete _parser;
	}
}
