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

using namespace std;

namespace SuperMarioProject
{
	/* Declaration in advance */
	class Level;
	typedef void (*balise_func)(Level *, const char **);

	class XMLLevelParser : XMLParser
	{
	public :
		static XMLLevelParser* getParser();

		void loadLevel(string fileName, Level* level);
		virtual ~XMLLevelParser();

	private :
		static XMLLevelParser* _parser;

		XMLLevelParser() { };
	};
}

#endif