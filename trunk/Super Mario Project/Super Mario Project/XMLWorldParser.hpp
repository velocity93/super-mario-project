////////////////////////////////////////////////////////////////////////
// XMLWorldParser.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_XML_WORLD_PARSER
#define HPP_XML_WORLD_PARSER

#include "XMLParser.hpp"
#include <string>

using namespace std;

namespace SuperMarioProject
{
	/* Declaration */
	class World;

	class XMLWorldParser : XMLParser
	{
	public :
		static XMLWorldParser* getParser();

		void loadWorld(string fileName, World* world);
		virtual ~XMLWorldParser();

	private :
		static XMLWorldParser* _parser;

		XMLWorldParser() { }
	};
}

#endif