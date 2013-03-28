////////////////////////////////////////////////////////////////////////
// XMLItemParser.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "XMLItemParser.hpp"
#include <sstream>

namespace XMLItemParsing
{
	void Speed_tag(Collisions::Item* item, const char ** attrs)
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

	void Submission_tag(Collisions::Item* item, const char ** attrs)
	{
		int value;
		
		std::stringstream ss;
		ss << std::hex << attrs[0];
		ss >> value;

		item->setSubmission(value);		
	}

	void NbSprites_tag(Collisions::Item* item, const char ** attrs)
	{
		item->addNbSpritesForState(Collisions::ItemOccurrence::NORMAL, atoi(attrs[0]));
	}

	void FrameDelay_tag(Collisions::Item* item, const char ** attrs)
	{
		item->addFrameDelayForState(Collisions::ItemOccurrence::NORMAL, atoi(attrs[0]));
	}


	/* PARSING PERSO XML */
	void start_item_element(void *user_data, const xmlChar *name, const xmlChar **attrs) 
	{
		static const xmlChar *elements[] = {
			BAD_CAST"Speed",
			BAD_CAST"Submission",
			BAD_CAST"NbSprites",
			BAD_CAST"FrameDelay"
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
				functions[i]((Collisions::Item*)user_data, (const char **)attrs);
				break;
			}
		}	
	}

	void error(void * /*ctx*/, const char * msg, ...)
	{
		cout << "error parsing Perso XML :" << msg << endl;
	}

	void parseItem(string fileName, Collisions::Item* item)
	{
		xmlSAXHandler sh = {NULL};
		sh.startElement = start_item_element;
		sh.error = XMLItemParsing::error;

		xmlSAXUserParseFile(&sh, item, fileName.c_str());
	}
}

namespace SuperMarioProject
{
	XMLItemParser* XMLItemParser::_parser = nullptr;

	XMLItemParser* XMLItemParser::getParser()
	{
		if(_parser == nullptr)
		{
			_parser = new XMLItemParser();
		}

		return _parser;
	}

	void XMLItemParser::loadItem(string fileName, Collisions::Item* item)
	{
		if(validateSchema("items/item.xsd", fileName.c_str()) == 0)
			XMLItemParsing::parseItem(fileName, item);
	}

	XMLItemParser::~XMLItemParser()
	{
		delete _parser;
	}
}