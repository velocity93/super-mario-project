////////////////////////////////////////////////////////////////////////
// XMLMonsterParser.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "XMLMonsterParser.hpp"
#include "Monster.hpp"
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/parserInternals.h>
#include <libxml/xmlschemas.h>
#include <libxml/xmlschemastypes.h>
#include <string>

using namespace std;

namespace smp
{	
	void AddDataToAnimation(XMLMonsterContext* monsterCtxt, MonsterOccurrence::State state, int value)
	{
		Monster* monster = (Monster *)monsterCtxt->ctxt;

		if(monsterCtxt->section == "nb_sprites")
		{
			monster->addNbSpritesForState(state, value);
		}
		else if(monsterCtxt->section == "frame_delay")
		{
			monster->addFrameDelayForState(state, value);
		}
	}
	
	void LeftDelta_tag(XMLMonsterContext* monsterCtxt, const char ** attrs)
	{
		Monster* monster = (Monster *)monsterCtxt->ctxt;

		monster->setDeltaX(atoi(attrs[1]));
	}

	void Features_tag(XMLMonsterContext* monsterCtxt, const char ** attrs)
	{
		Monster* monster = (Monster *)monsterCtxt->ctxt;

		monster->setFeature(attrs[1]);
	}
	
	void NbSprites_tag(XMLMonsterContext* monsterCtxt, const char **)
	{
		monsterCtxt->section = "nb_sprites";
	}
	
	void FrameDelay_tag(XMLMonsterContext* monsterCtxt, const char **)
	{
		monsterCtxt->section = "frame_delay";
	}
	
	void Walk_tag(XMLMonsterContext* monsterCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);

		AddDataToAnimation(monsterCtxt, MonsterOccurrence::WALK, value);
	}

	void Retracted_tag(XMLMonsterContext* monsterCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);

		AddDataToAnimation(monsterCtxt, MonsterOccurrence::RETRACTED, value);
	}

	void GetOutFromShell_tag(XMLMonsterContext* monsterCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);

		AddDataToAnimation(monsterCtxt, MonsterOccurrence::GET_OUT_FROM_SHELL, value);
	}
	
	void DeadByJump_tag(XMLMonsterContext* monsterCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(monsterCtxt, MonsterOccurrence::DEAD_BY_JUMP_ON, value);
	}
	
	void DeadByProj_tag(XMLMonsterContext* monsterCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(monsterCtxt, MonsterOccurrence::DEAD_BY_PROJ, value);
	}

	/* PARSING PERSO XML */
	void start_monster_element(void *user_data, const xmlChar *name, const xmlChar **attrs) 
	{
		static const xmlChar *elements[] = {
			BAD_CAST"left_delta",
			BAD_CAST"features",
			BAD_CAST"nb_sprites",
			BAD_CAST"walk",
			BAD_CAST"retracted",
			BAD_CAST"dead_by_jump",
			BAD_CAST"dead_by_proj",
			BAD_CAST"get_out_from_shell",
			BAD_CAST"frame_delay"
		};
		static const monster_func functions[] = {
			LeftDelta_tag, 
			Features_tag,
			NbSprites_tag,
			Walk_tag,
			Retracted_tag,
			DeadByJump_tag,
			GetOutFromShell_tag,
			DeadByProj_tag,
			FrameDelay_tag
		};
		int i;

		for(i = 0; i < 9; i++)
		{
			if(!xmlStrcmp(name, elements[i]))
			{
				functions[i]((XMLMonsterContext*)user_data, (const char **)attrs);
				break;
			}
		}	
	}

	static void error(void * /*ctx*/, const char * msg, ...)
	{
		cout << "error parsing Monster XML :" << msg << endl;
	}

	void parseMonster(string fileName, Monster* monster)
	{
		XMLMonsterContext monsterctxt;

		/* Initialization of context */
		monsterctxt.ctxt = monster;
		monsterctxt.section = "";

		xmlSAXHandler sh = {NULL};
		sh.startElement = start_monster_element;
		sh.error = error;

		xmlSAXUserParseFile(&sh, &monsterctxt, fileName.c_str());
	}


	XMLMonsterParser* XMLMonsterParser::_parser = nullptr;

	XMLMonsterParser* XMLMonsterParser::getParser()
	{
		if(_parser == nullptr)
		{
			_parser = new XMLMonsterParser();
		}

		return _parser;
	}

	void XMLMonsterParser::loadMonster(const string &fileName, Monster* monster)
	{
		if(validateSchema("textures/monsters/monsters.xsd", fileName.c_str()) == 0)
			parseMonster(fileName, monster);
	}

	XMLMonsterParser::~XMLMonsterParser()
	{
		delete _parser;
	}
}
