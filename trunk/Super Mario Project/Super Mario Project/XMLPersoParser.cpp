////////////////////////////////////////////////////////////////////////
// XMLPersoParser.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "XMLPersoParser.hpp"

namespace XMLPersoParsing
{
	/* To manage if we are in nb_sprites or in frame_delay */
	string section;
	
	void AddDataToAnimation(Collisions::Perso* perso, Collisions::Perso::State state, int value)
	{
		if(section == "nb_sprites")
		{
			perso->getAnimation().addNbSpritesForGivenState(state, value);
		}
		else if(section == "frame_delay")
		{
			perso->getAnimation().addFrameDelayForGivenState(state, value);
		}
	}
	
	void LeftDelta_tag(Collisions::Perso* perso, const char ** attrs)
	{
		perso->setDeltaX(atoi(attrs[1]));
	}
	
	void TopDelta_tag(Collisions::Perso* perso, const char ** attrs)
	{
		perso->setDeltaY(atoi(attrs[1]));
	}
	
	void NbSprites_tag(Collisions::Perso*, const char **)
	{
		section = "nb_sprites";
	}
	
	void FrameDelay_tag(Collisions::Perso*, const char **)
	{
		section = "frame_delay";
	}
	
	void Standing_tag(Collisions::Perso* perso, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(perso, Collisions::Perso::STANDING, value);
	}
	
	void Walk_tag(Collisions::Perso* perso, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(perso, Collisions::Perso::WALK, value);
	}
	
	void Run_tag(Collisions::Perso* perso, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(perso, Collisions::Perso::RUN_1, value);
		AddDataToAnimation(perso, Collisions::Perso::RUN_2, value);
	}
	
	void Skid_tag(Collisions::Perso* perso, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(perso, Collisions::Perso::SKID, value);
	}
	
	void Jump_tag(Collisions::Perso* perso, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(perso, Collisions::Perso::JUMP, value);
	}
	
	void JumpFalling_tag(Collisions::Perso* perso, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(perso, Collisions::Perso::JUMP_FALLING, value);
	}
	
	void Fly_tag(Collisions::Perso* perso, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(perso, Collisions::Perso::FLY, value);
	}
	
	void Face_tag(Collisions::Perso* perso, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(perso, Collisions::Perso::GET_OUT_FROM_PIPE_VERTICAL, value);
	}
	
	void Back_tag(Collisions::Perso* perso, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(perso, Collisions::Perso::FLY, value);
	}
	
	void LookTop_tag(Collisions::Perso* perso, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(perso, Collisions::Perso::GET_OUT_FROM_PIPE_VERTICAL, value);
	}
	
	void Lowered_tag(Collisions::Perso* perso, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(perso, Collisions::Perso::FLY, value);
	}
	
	void ClimbLadder_tag(Collisions::Perso* perso, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(perso, Collisions::Perso::CLIMB_LADDER, value);
	}
	
	void StandingShell_tag(Collisions::Perso* perso, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(perso, Collisions::Perso::STANDING_SHELL, value);
	}
	
	void WalkShell_tag(Collisions::Perso* perso, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(perso, Collisions::Perso::WALK_SHELL, value);
	}
	
	void PushShell_tag(Collisions::Perso* perso, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(perso, Collisions::Perso::PUSH_SHELL, value);
	}
	
	void JumpShell_tag(Collisions::Perso* perso, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(perso, Collisions::Perso::JUMP_SHELL, value);
	}
	
	void LoweredShell_tag(Collisions::Perso* perso, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(perso, Collisions::Perso::LOWERED_SHELL, value);
	}
	
	void LookTopShell_tag(Collisions::Perso* perso, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(perso, Collisions::Perso::LOOK_TOP_SHELL, value);
	}
	
	void Dead_tag(Collisions::Perso* perso, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(perso, Collisions::Perso::DEAD, value);
	}
	
	void FinishCastle_tag(Collisions::Perso* perso, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(perso, Collisions::Perso::FINISH, value);
	}
	
	void FrameDelayRun2_tag(Collisions::Perso* perso, const char ** attrs)
	{
		int value = atoi(attrs[1]);
		
		AddDataToAnimation(perso, Collisions::Perso::RUN_2, value);
	}
	

	/* PARSING PERSO XML */
	void start_perso_element(void *user_data, const xmlChar *name, const xmlChar **attrs) 
	{
		static const xmlChar *elements[] = {
			BAD_CAST"LeftDelta", 
			BAD_CAST"TopDelta",
			BAD_CAST"NbSprites",
			BAD_CAST"Standing",
			BAD_CAST"Walk",
			BAD_CAST"Run",
			BAD_CAST"Skid",
			BAD_CAST"Jump",
			BAD_CAST"JumpFalling",
			BAD_CAST"Fly",
			BAD_CAST"Face",
			BAD_CAST"Back",
			BAD_CAST"LookTop",
			BAD_CAST"Lowered",
			BAD_CAST"ClimbLadder",
			BAD_CAST"StandingShell",
			BAD_CAST"WalkShell",
			BAD_CAST"PushShell",
			BAD_CAST"JumpShell",
			BAD_CAST"LoweredShell",
			BAD_CAST"LookTopShell",
			BAD_CAST"Dead",
			BAD_CAST"FinishCastle",
			BAD_CAST"FrameDelay",
			BAD_CAST"Run2"
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

		for(i = 0; i < 24; i++)
		{
			if(!xmlStrcmp(name, elements[i]))
			{
				functions[i]((Collisions::Perso*)user_data, (const char **)attrs);
				break;
			}
		}	
	}

	void error(void * /*ctx*/, const char * msg, ...)
	{
		cout << "error parsing Perso XML :" << msg << endl;
	}

	void parsePerso(string fileName, Collisions::Perso* perso)
	{
		xmlSAXHandler sh = {NULL};
		sh.startElement = start_perso_element;
		sh.error = XMLPersoParsing::error;

		xmlSAXUserParseFile(&sh, perso, fileName.c_str());
	}
}

namespace SuperMarioProject
{
	XMLPersoParser* XMLPersoParser::_parser = nullptr;

	XMLPersoParser* XMLPersoParser::getParser()
	{
		if(_parser == nullptr)
		{
			_parser = new XMLPersoParser();
		}

		return _parser;
	}

	void XMLPersoParser::loadPerso(string fileName, Collisions::Perso* perso)
	{
		if(validateSchema("persos/perso.xsd", fileName.c_str()) == 0)
			XMLPersoParsing::parsePerso(fileName, perso);
	}

	XMLPersoParser::~XMLPersoParser()
	{
		delete _parser;
	}
}