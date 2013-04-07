////////////////////////////////////////////////////////////////////////
// XMLPersoParser.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "XMLPersoParser.hpp"
#include "Perso.hpp"
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/parserInternals.h>
#include <libxml/xmlschemas.h>
#include <libxml/xmlschemastypes.h>
#include <string>

using namespace std;

namespace smp
{	
	void AddDataToAnimation(XMLPersoContext* persoCtxt, Perso::State state, int value)
	{
		Perso* perso = (Perso *)persoCtxt->ctxt;

		if(persoCtxt->section == "nb_sprites")
		{
			perso->getAnimation().addNbSpritesForGivenState(state, value);
		}
		else if(persoCtxt->section == "frame_delay")
		{
			perso->getAnimation().addFrameDelayForGivenState(state, value);
		}
	}
	
	void LeftDelta_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		Perso* perso = (Perso *)persoCtxt->ctxt;

		perso->setDeltaX(atoi(attrs[1]));
	}
	
	void TopDelta_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		Perso* perso = (Perso *)persoCtxt->ctxt;

		perso->setDeltaY(atoi(attrs[1]));
	}
	
	void NbSprites_tag(XMLPersoContext* persoCtxt, const char **)
	{
		persoCtxt->section = "nb_sprites";
	}
	
	void FrameDelay_tag(XMLPersoContext* persoCtxt, const char **)
	{
		persoCtxt->section = "frame_delay";
	}
	
	void Standing_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);		
		
		AddDataToAnimation(persoCtxt, Perso::STANDING, value);
	}
	
	void Walk_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);

		AddDataToAnimation(persoCtxt, Perso::WALK, value);
	}
	
	void Run_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		//AddDataToAnimation(persoCtxt, Perso::RUN, value);
		AddDataToAnimation(persoCtxt, Perso::RUN_2, value);
	}
	
	void Skid_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(persoCtxt, Perso::SKID, value);
	}
	
	void Jump_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);		
		
		AddDataToAnimation(persoCtxt, Perso::JUMP, value);
	}
	
	void JumpFalling_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);		
		
		AddDataToAnimation(persoCtxt, Perso::JUMP_FALLING, value);
	}
	
	void Fly_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(persoCtxt, Perso::FLY, value);
	}
	
	void Face_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(persoCtxt, Perso::GET_OUT_FROM_PIPE_VERTICAL, value);
	}
	
	void Back_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(persoCtxt, Perso::BACK, value);
	}
	
	void LookTop_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(persoCtxt, Perso::LOOK_TOP, value);
	}
	
	void Lowered_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(persoCtxt, Perso::LOWERED, value);
	}
	
	void ClimbLadder_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(persoCtxt, Perso::CLIMB_LADDER, value);
	}
	
	void StandingShell_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(persoCtxt, Perso::STANDING_SHELL, value);
	}
	
	void WalkShell_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(persoCtxt, Perso::WALK_SHELL, value);
	}
	
	void PushShell_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);		
		
		AddDataToAnimation(persoCtxt, Perso::PUSH_SHELL, value);
	}
	
	void JumpShell_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(persoCtxt, Perso::JUMP_SHELL, value);
	}
	
	void LoweredShell_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(persoCtxt, Perso::LOWERED_SHELL, value);
	}
	
	void LookTopShell_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(persoCtxt, Perso::LOOK_TOP_SHELL, value);
	}
	
	void Dead_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(persoCtxt, Perso::DEAD, value);
	}
	
	void FinishCastle_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(persoCtxt, Perso::FINISH, value);
	}
	
	void FrameDelayRun2_tag(XMLPersoContext* persoCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(persoCtxt, Perso::RUN_2, value);
	}
	

	/* PARSING PERSO XML */
	void start_perso_element(void *user_data, const xmlChar *name, const xmlChar **attrs) 
	{
		static const xmlChar *elements[] = {
			BAD_CAST"left_delta", 
			BAD_CAST"top_delta",
			BAD_CAST"nb_sprites",
			BAD_CAST"standing",
			BAD_CAST"walk",
			BAD_CAST"run",
			BAD_CAST"skid",
			BAD_CAST"jump",
			BAD_CAST"jump_falling",
			BAD_CAST"fly",
			BAD_CAST"face",
			BAD_CAST"back",
			BAD_CAST"look_top",
			BAD_CAST"lowered",
			BAD_CAST"climb_ladder",
			BAD_CAST"standing_shell",
			BAD_CAST"walk_shell",
			BAD_CAST"push_shell",
			BAD_CAST"jump_shell",
			BAD_CAST"lowered_shell",
			BAD_CAST"look_top_shell",
			BAD_CAST"dead",
			BAD_CAST"finish_castle",
			BAD_CAST"frame_delay",
			BAD_CAST"run2"
		};
		static const perso_func functions[] = {
			LeftDelta_tag, 
			TopDelta_tag,
			NbSprites_tag,
			Standing_tag,
			Walk_tag,
			Run_tag,
			Skid_tag,
			Jump_tag,
			JumpFalling_tag,
			Fly_tag,
			Face_tag,
			Back_tag,
			LookTop_tag,
			Lowered_tag,
			ClimbLadder_tag,
			StandingShell_tag,
			WalkShell_tag,
			PushShell_tag,
			JumpShell_tag,
			LoweredShell_tag,
			LookTopShell_tag,
			Dead_tag,
			FinishCastle_tag,
			FrameDelay_tag,
			FrameDelayRun2_tag
		};
		int i;

		for(i = 0; i < 25; i++)
		{
			if(!xmlStrcmp(name, elements[i]))
			{
				functions[i]((XMLPersoContext*)user_data, (const char **)attrs);
				break;
			}
		}	
	}

	static void error(void * /*ctx*/, const char * msg, ...)
	{
		cout << "error parsing Perso XML :" << msg << endl;
	}

	void parsePerso(string fileName, Perso* perso)
	{
		XMLPersoContext persoCtxt;

		/* Initialization of context */
		persoCtxt.ctxt = perso;
		persoCtxt.section = "";

		xmlSAXHandler sh = {NULL};
		sh.startElement = start_perso_element;
		sh.error = error;

		xmlSAXUserParseFile(&sh, &persoCtxt, fileName.c_str());
	}


	XMLPersoParser* XMLPersoParser::_parser = nullptr;

	XMLPersoParser* XMLPersoParser::getParser()
	{
		if(_parser == nullptr)
		{
			_parser = new XMLPersoParser();
		}

		return _parser;
	}

	void XMLPersoParser::loadPerso(const string &fileName, Perso* perso)
	{
		if(validateSchema("textures/persos/persos.xsd", fileName.c_str()) == 0)
			parsePerso(fileName, perso);
	}

	XMLPersoParser::~XMLPersoParser()
	{
		delete _parser;
	}
}
