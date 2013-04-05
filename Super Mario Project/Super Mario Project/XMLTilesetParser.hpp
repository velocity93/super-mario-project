////////////////////////////////////////////////////////////////////////
// XMLTilesetParser.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_XML_TILESET_PARSER
#define HPP_XML_TILESET_PARSER

#include "XMLParser.hpp"
#include <string>

namespace smp
{
	// Forward declaration
	class Tileset;

	typedef void (*tileset_func)(Tileset *, const char **);

	class XMLTilesetParser : XMLParser
	{
	public :
		static XMLTilesetParser* getParser();

		void loadTileset(const std::string &fileName, Tileset* tileset);
		virtual ~XMLTilesetParser();

	private :
		static XMLTilesetParser* _parser;

		XMLTilesetParser() { }
	};
}

#endif