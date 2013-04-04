////////////////////////////////////////////////////////////////////////
// XMLBackgroundParser.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_XML_BACKGROUND_PARSER
#define HPP_XML_BACKGROUND_PARSER

#include "XMLParser.hpp"
#include <string>

namespace smp
{
	// Forward declaration
	class Background;

	typedef void (*background_func)(Background *, const char **);

	class XMLBackgroundParser : XMLParser
	{
	public :
		static XMLBackgroundParser* getParser();

		void loadBackground(const std::string &fileName, Background* background);
		virtual ~XMLBackgroundParser();

	private :
		static XMLBackgroundParser* _parser;

		XMLBackgroundParser() { }
	};
}

#endif