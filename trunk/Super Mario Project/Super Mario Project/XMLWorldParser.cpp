////////////////////////////////////////////////////////////////////////
// XMLWorldParser.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "XMLWorldParser.hpp"
#include "World.hpp"

namespace XMLWorldParsing
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

	void error(void * /*ctx*/, const char * msg, ...)
	{
		cout << "error parsing world XML :" << msg << endl;
	}
}


namespace SuperMarioProject
{
	XMLWorldParser* XMLWorldParser::_parser = nullptr;

	XMLWorldParser* XMLWorldParser::getParser()
	{
		if(_parser == nullptr)
		{
			_parser = new XMLWorldParser();
		}

		return _parser;
	}


	void XMLWorldParser::loadWorld(string fileName, World* world)
	{
		if(validateSchema("worlds/world.xsd", fileName.c_str()) != 0)
			return;

		/* Initialize parser */
		xmlSAXHandler sh = {NULL};
		sh.startElement = XMLWorldParsing::startElement;
		sh.error = XMLWorldParsing::error;

		xmlSAXUserParseFile(&sh, world, fileName.c_str());
	}

	XMLWorldParser::~XMLWorldParser()
	{
		delete _parser;
	}
}