////////////////////////////////////////////////////////////////////////
// XMLParser.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_XMLPARSER
#define HPP_XMLPARSER

#include <string>

using namespace std;

namespace SuperMarioProject
{
	class Level;
	class World;
	typedef void (*balise_func)(Level *, const char **);

	class XMLParser
	{
	public :
		static void loadLevel(string fileName, Level* level);
		static void loadWorld(string fileName, World* world);
	};
}
#endif