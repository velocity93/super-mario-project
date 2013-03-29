////////////////////////////////////////////////////////////////////////
// XMLPersoParser.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_XML_PERSO_PARSER
#define HPP_XML_PERSO_PARSER

#include "XMLParser.hpp"
#include <string>

namespace smp
{
	// forward declaration
	class Perso;

	typedef void (*perso_func)(Perso *, const char **);

	class XMLPersoParser : XMLParser
	{
	public :
		static XMLPersoParser* getParser();

		void loadPerso(const std::string &fileName, Perso* perso);
		virtual ~XMLPersoParser();

	private :
		static XMLPersoParser* _parser;

		XMLPersoParser() { }
	};
}

#endif
