////////////////////////////////////////////////////////////////////////
// XMLMonsterParser.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_XML_MONSTER_PARSER
#define HPP_XML_MONSTER_PARSER

#include "XMLParser.hpp"
#include <string>

namespace smp
{
	// forward declaration
	class Monster;

	typedef struct : XMLParserContext
	{
		std::string section;
	} XMLMonsterContext;

	typedef void (*monster_func)(XMLMonsterContext *, const char **);

	class XMLMonsterParser : XMLParser
	{
	public :
		static XMLMonsterParser* getParser();

		void loadMonster(const std::string &fileName, Monster* monster);
		virtual ~XMLMonsterParser();

	private :
		static XMLMonsterParser* _parser;

		XMLMonsterParser() { }
	};
}

#endif
