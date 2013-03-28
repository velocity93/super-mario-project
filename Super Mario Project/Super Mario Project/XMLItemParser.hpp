////////////////////////////////////////////////////////////////////////
// XMLItemParser.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_XML_ITEM_PARSER
#define HPP_XML_ITEM_PARSER

#include "XMLParser.hpp"
#include "Item.hpp"
#include <string>

using namespace std;

namespace SuperMarioProject
{
	typedef void (*item_func)(Collisions::Item *, const char **);

	class XMLItemParser : XMLParser
	{
	public :
		static XMLItemParser* getParser();

		void loadItem(string fileName, Collisions::Item* item);
		virtual ~XMLItemParser();

	private :
		static XMLItemParser* _parser;

		XMLItemParser() { }
	};
}

#endif