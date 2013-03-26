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
#include "Perso.hpp"
#include <string>

using namespace std;

namespace SuperMarioProject
{
	typedef void (*perso_func)(Collisions::Perso *, const char **);

	class XMLPersoParser : XMLParser
	{
	public :
		static XMLPersoParser* getParser();

		void loadPerso(string fileName, Collisions::Perso* perso);
		virtual ~XMLPersoParser();

	private :
		static XMLPersoParser* _parser;

		XMLPersoParser() { }
	};
}

#endif