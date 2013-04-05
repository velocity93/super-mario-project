////////////////////////////////////////////////////////////////////////
// XMLTilesetParser.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "XMLTilesetParser.hpp"
#include "Tileset.hpp"
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/parserInternals.h>
#include <libxml/xmlschemas.h>
#include <libxml/xmlschemastypes.h>
#include <sstream>

using namespace std;

namespace smp
{
	void Tileset_tag(Tileset* tileset, const char ** attrs)
	{
		int x = 0, y = 0;

		for(int i = 0; i < 6; i += 2)
		{
			if(!strcmp(attrs[i], "lines") == 0)
			{
				x = atoi(attrs[i]);
			}
			else if (!strcmp(attrs[i], "columns") == 0)
			{
				y = atoi(attrs[i]);
			}
			else if (!strcmp(attrs[i], "frame_delay") == 0)
			{
				tileset->setFrameDelay(atoi(attrs[i]));
			}
		}

		tileset->setNbSprites(x, y);
	}

	void Physic_tag(Tileset* tileset, const char ** attrs)
	{
		int value = 0;

		stringstream ss;
		ss << std::hex << attrs[1];
		ss >> value;

		tileset->getPhysics().push_back(value);
	}

	void start_tileset_element(void *user_data, const xmlChar *name, const xmlChar **attrs) 
	{
		static const xmlChar *elements[] = {
			BAD_CAST"tileset",
			BAD_CAST"physic"
		};
		static const tileset_func functions[] = {
			Tileset_tag,
			Physic_tag
		};
		int i;

		for(i = 0; i < 2; i++)
		{
			if(!xmlStrcmp(name, elements[i]))
			{
				functions[i]((Tileset*)user_data, (const char **)attrs);
				break;
			}
		}       
	}

	static void error(void * /*ctx*/, const char * msg, ...)
	{
		cout << "error parsing Tileset XML :" << msg << endl;
	}

	void parseTileset(const std::string &fileName, Tileset* tileset)
	{
		xmlSAXHandler sh = {NULL};
		sh.startElement = start_tileset_element;
		sh.error = error;

		xmlSAXUserParseFile(&sh, tileset, fileName.c_str());
	}

	XMLTilesetParser* XMLTilesetParser::_parser = nullptr;

	XMLTilesetParser* XMLTilesetParser::getParser()
	{
		if(_parser == nullptr)
		{
			_parser = new XMLTilesetParser();
		}

		return _parser;
	}

	void XMLTilesetParser::loadTileset(const std::string &fileName, Tileset* tileset)
	{
		if(validateSchema("blocs/blocs.xsd", fileName.c_str()) == 0)
			parseTileset(fileName, tileset);
	}

	XMLTilesetParser::~XMLTilesetParser()
	{
		delete _parser;
	}
}
