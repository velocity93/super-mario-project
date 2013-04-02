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
#include <string>

namespace smp
{
	// Forward declaration
	class Item;

	typedef void (*item_func)(Item *, const char **);

	class XMLItemParser : XMLParser
	{
	public :
		static XMLItemParser* getParser();

		void loadItem(const std::string &fileName, Item* item);
		virtual ~XMLItemParser();

	private :
		static XMLItemParser* _parser;

		XMLItemParser() { }
	};
}

#endif