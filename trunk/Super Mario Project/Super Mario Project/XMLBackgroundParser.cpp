////////////////////////////////////////////////////////////////////////
// XMLBackgroundParser.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "XMLBackgroundParser.hpp"
#include "Background.hpp"
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/parserInternals.h>
#include <libxml/xmlschemas.h>
#include <libxml/xmlschemastypes.h>
#include <sstream>

using namespace std;

namespace smp
{
	void NbSprites_tag(Background* background, const char ** attrs)
	{
		background->getAnimation().addNbSpritesForGivenState(Background::NORMAL, atoi(attrs[0]));
	}

	void VerticalRepetition_tag(Background* background, const char ** attrs)
	{
		background->setVerticalRepetition(atoi(attrs[1]));
	}


	/* PARSING PERSO XML */
	void start_background_element(void *user_data, const xmlChar *name, const xmlChar **attrs) 
	{
		static const xmlChar *elements[] = {
			BAD_CAST"nb_Sprites",
			BAD_CAST"vertical_repetition"
		};
		static const background_func functions[] = {
			NbSprites_tag,
			VerticalRepetition_tag
		};
		int i;

		for(i = 0; i < 2; i++)
		{
			if(!xmlStrcmp(name, elements[i]))
			{
				functions[i]((Background*)user_data, (const char **)attrs);
				break;
			}
		}	
	}

	static void error(void * /*ctx*/, const char * msg, ...)
	{
		cout << "error parsing Background XML :" << msg << endl;
	}

	void parseItem(const std::string &fileName, Background* background)
	{
		xmlSAXHandler sh = {NULL};
		sh.startElement = start_background_element;
		sh.error = error;

		xmlSAXUserParseFile(&sh, background, fileName.c_str());
	}

	XMLBackgroundParser* XMLBackgroundParser::_parser = nullptr;

	XMLBackgroundParser* XMLBackgroundParser::getParser()
	{
		if(_parser == nullptr)
		{
			_parser = new XMLBackgroundParser();
		}

		return _parser;
	}

	void XMLBackgroundParser::loadBackground(const std::string &fileName, Background* background)
	{
		if(validateSchema("backgrounds/backgrounds.xsd", fileName.c_str()) == 0)
			parseItem(fileName, background);
	}

	XMLBackgroundParser::~XMLBackgroundParser()
	{
		delete _parser;
	}
}