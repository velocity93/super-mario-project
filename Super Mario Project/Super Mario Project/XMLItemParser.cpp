////////////////////////////////////////////////////////////////////////
// XMLItemParser.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "XMLItemParser.hpp"
#include "Item.hpp"
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/parserInternals.h>
#include <libxml/xmlschemas.h>
#include <libxml/xmlschemastypes.h>
#include <sstream>

using namespace std;

namespace smp
{
	void Speed_tag(Item* item, const char ** attrs)
	{
		for(int i = 0; i < 4; i = i + 2)
		{
			if(!strcmp(attrs[i], "x"))
			{
				item->setInitialSpeedX(atoi(attrs[i + 1]));
			}
			else if(!strcmp(attrs[i], "y"))
			{
				item->setInitialSpeedY(atoi(attrs[i + 1]));
			}
		}
	}

	void Submission_tag(Item* item, const char ** attrs)
	{
		int value = 0;
		
		std::stringstream ss;
		ss << std::hex << attrs[1];
		ss >> value;

		item->setSubmission(value);
	}

	void NbSprites_tag(Item* item, const char ** attrs)
	{
		item->addNbSpritesForState(ItemOccurrence::NORMAL, atoi(attrs[1]));
	}

	void FrameDelay_tag(Item* item, const char ** attrs)
	{
		item->addFrameDelayForState(ItemOccurrence::NORMAL, atoi(attrs[1]));
	}


	/* PARSING PERSO XML */
	void start_item_element(void *user_data, const xmlChar *name, const xmlChar **attrs) 
	{
		static const xmlChar *elements[] = {
			BAD_CAST"speed",
			BAD_CAST"submission",
			BAD_CAST"nb_sprites",
			BAD_CAST"frame_delay"
		};
		static const item_func functions[] = {
			Speed_tag, 
			Submission_tag,
			NbSprites_tag,
			FrameDelay_tag
		};
		int i;

		for(i = 0; i < 4; i++)
		{
			if(!xmlStrcmp(name, elements[i]))
			{
				functions[i]((Item*)user_data, (const char **)attrs);
				break;
			}
		}	
	}

	static void error(void * /*ctx*/, const char * msg, ...)
	{
		cout << "error parsing Perso XML :" << msg << endl;
	}

	void parseItem(const std::string &fileName, Item* item)
	{
		xmlSAXHandler sh = {NULL};
		sh.startElement = start_item_element;
		sh.error = error;

		xmlSAXUserParseFile(&sh, item, fileName.c_str());
	}

	XMLItemParser* XMLItemParser::_parser = nullptr;

	XMLItemParser* XMLItemParser::getParser()
	{
		if(_parser == nullptr)
		{
			_parser = new XMLItemParser();
		}

		return _parser;
	}

	void XMLItemParser::loadItem(const std::string &fileName, Item* item)
	{
		if(validateSchema("textures/items/items.xsd", fileName.c_str()) == 0)
			parseItem(fileName, item);
	}

	XMLItemParser::~XMLItemParser()
	{
		delete _parser;
	}
}