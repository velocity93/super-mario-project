////////////////////////////////////////////////////////////////////////
// XMLLevelParser.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_XML_LEVEL_PARSER
#define HPP_XML_LEVEL_PARSER

#include "XMLParser.hpp"
#include <string>

namespace smp
{
	// forward declaration
	class Level;

	typedef void (*balise_func)(Level *, const char **);

	class XMLLevelParser : XMLParser
	{
	public :
		static XMLLevelParser* getParser();

		void loadLevel(std::string fileName, Level* level);
		static void killParser();

	private :
		static XMLLevelParser* _parser;

		XMLLevelParser() { }

		~XMLLevelParser() { }
	};
}

#endif