////////////////////////////////////////////////////////////////////////
// XMLWorldParser.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "XMLWorldParser.hpp"
#include "World.hpp"
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/parserInternals.h>
#include <libxml/xmlschemas.h>
#include <libxml/xmlschemastypes.h>
#include <iostream>

using namespace std;

namespace smp
{
	void level_tag(World* world, const char ** attrs)
	{
		world->addLevelName(attrs[1]);
	}

	void startElement(void *user_data, const xmlChar *name, const xmlChar **attrs) 
	{
		if(!xmlStrcmp(name, BAD_CAST"level"))
			level_tag((World*)user_data, (const char**)attrs);
	}

	static void error(void * /*ctx*/, const char * msg, ...)
	{
		cout << "error parsing world XML :" << msg << endl;
	}


	XMLWorldParser* XMLWorldParser::_parser = nullptr;

	XMLWorldParser* XMLWorldParser::getParser()
	{
		if(_parser == nullptr)
		{
			_parser = new XMLWorldParser();
		}

		return _parser;
	}


	void XMLWorldParser::loadWorld(const string &fileName, World* world)
	{
		if(validateSchema("worlds/world.xsd", fileName.c_str()) != 0)
			return;

		/* Initialize parser */
		xmlSAXHandler sh = {NULL};
		sh.startElement = startElement;
		sh.error = error;

		xmlSAXUserParseFile(&sh, world, fileName.c_str());
	}

	void XMLWorldParser::killParser()
	{
		delete _parser;
	}
}
