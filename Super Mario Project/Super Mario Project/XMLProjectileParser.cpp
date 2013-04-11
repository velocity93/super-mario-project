////////////////////////////////////////////////////////////////////////
// XMLProjectileParser.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "XMLProjectileParser.hpp"
#include "Projectile.hpp"
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/parserInternals.h>
#include <libxml/xmlschemas.h>
#include <libxml/xmlschemastypes.h>
#include <sstream>

using namespace std;

namespace smp
{
	void AddDataToAnimation(XMLProjectileContext* projCtxt, ProjectileOccurrence::State state, int value)
	{
		Projectile* proj = (Projectile *)projCtxt->ctxt;

		if(projCtxt != nullptr)
		{
			if(projCtxt->section == "nb_sprites")
			{
				proj->addNbSpritesForState(state, value);
			}
			else if(projCtxt->section == "frame_delay")
			{
				proj->addFrameDelayForState(state, value);
			}
		}
	}

	void SpeedX_tag(XMLProjectileContext* projCtxt, const char ** attrs)
	{
		Projectile* proj = (Projectile *)projCtxt->ctxt;
		
		if(proj != nullptr)
			proj->setInitialSpeedX(atoi(attrs[1]));
	}

	void LeftDelta_tag(XMLProjectileContext* projCtxt, const char ** attrs)
	{
		Projectile* proj = (Projectile *)projCtxt->ctxt;
		
		if(proj != nullptr)
			proj->setBottomLeft(atoi(attrs[1]));
	}

	void TopDelta_tag(XMLProjectileContext* projCtxt, const char ** attrs)
	{
		Projectile* proj = (Projectile *)projCtxt->ctxt;
		
		if(proj != nullptr)
			proj->setTop(atoi(attrs[1]));
	}

	void Submission_tag(XMLProjectileContext* projCtxt, const char ** attrs)
	{
		int value = 0;
		Projectile* proj = (Projectile *)projCtxt->ctxt;

		if(proj != nullptr)
		{
			std::stringstream ss;
			ss << std::hex << attrs[1];
			ss >> value;

			proj->setSubmission(value);
		}
	}

	void NbSprites_tag(XMLProjectileContext* projCtxt, const char ** )
	{
		projCtxt->section = "nb_sprites";
	}

	void Run_tag(XMLProjectileContext* projCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);

		AddDataToAnimation(projCtxt, ProjectileOccurrence::LAUNCHED, value);
	}

	void Dead_tag(XMLProjectileContext* projCtxt, const char ** attrs)
	{
		int value = atoi(attrs[1]);

		AddDataToAnimation(projCtxt, ProjectileOccurrence::DEAD, value);
	}

	void FrameDelay_tag(XMLProjectileContext* projCtxt, const char ** )
	{
		projCtxt->section = "frame_delay";
	}


	/* PARSING PERSO XML */
	void start_projectile_element(void *user_data, const xmlChar *name, const xmlChar **attrs) 
	{
		static const xmlChar *elements[] = {
			BAD_CAST"speed_x",
			BAD_CAST"left_delta",
			BAD_CAST"top_delta",
			BAD_CAST"submission",
			BAD_CAST"nb_sprites",
			BAD_CAST"run",
			BAD_CAST"dead",
			BAD_CAST"frame_delay"
			//BAD_CAST"appearance"
			//BAD_CAST"appearance"
			//BAD_CAST"appearance"
		};
		static const proj_func functions[] = {
			SpeedX_tag,
			LeftDelta_tag,
			TopDelta_tag,
			Submission_tag,
			NbSprites_tag,
			Run_tag,
			Dead_tag,
			FrameDelay_tag
			//NbSprites_tag,
		};
		int i;

		for(i = 0; i < 9; i++)
		{
			if(!xmlStrcmp(name, elements[i]))
			{
				functions[i]((XMLProjectileContext*)user_data, (const char **)attrs);
				break;
			}
		}	
	}

	static void error(void * /*ctx*/, const char * msg, ...)
	{
		cout << "error parsing Perso XML :" << msg << endl;
	}

	void parseProjectile(const std::string &fileName, Projectile* projectile)
	{
		/* Initialize context */
		XMLProjectileContext projctxt;
		projctxt.ctxt = projectile;
		projctxt.section = "";

		xmlSAXHandler sh = {NULL};
		sh.startElement = start_projectile_element;
		sh.error = error;

		xmlSAXUserParseFile(&sh, &projctxt, fileName.c_str());
	}

	XMLProjectileParser* XMLProjectileParser::_parser = nullptr;

	XMLProjectileParser* XMLProjectileParser::getParser()
	{
		if(_parser == nullptr)
		{
			_parser = new XMLProjectileParser();
		}

		return _parser;
	}

	void XMLProjectileParser::loadProjectile(const std::string &fileName, Projectile* projectile)
	{
		if(validateSchema("textures/projectiles/projectiles.xsd", fileName.c_str()) == 0)
			parseProjectile(fileName, projectile);
	}

	XMLProjectileParser::~XMLProjectileParser()
	{
		delete _parser;
	}
}