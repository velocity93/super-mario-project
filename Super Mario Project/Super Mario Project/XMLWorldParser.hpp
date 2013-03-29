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

namespace smp
{
	// forward declaration
	class World;

	class XMLWorldParser : XMLParser
	{
	public :
		static XMLWorldParser* getParser();

		void loadWorld(const std::string &fileName, World* world);
		void killParser();

	private :
		static XMLWorldParser* _parser;
		virtual ~XMLWorldParser() { }
		XMLWorldParser() { }
	};
}

#endif
