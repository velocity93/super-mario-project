////////////////////////////////////////////////////////////////////////
// XMLWriter.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_XMLWRITER
#define HPP_XMLWRITER

#include <string>
#include <fstream>

using namespace std;

namespace SuperMarioProject
{
	class Level;

	class XMLWriter
	{
	public :
		XMLWriter();
		static void saveLevel(const string& fileName, Level* level);

	private :
		static int _tabs;

		static void openElement(ofstream& file, const string& name);
		static void endElement(ofstream& file);
		static void closeElement(ofstream& file, const string& name);
		static void closeShortElement(ofstream& file);
		static void addAttribute(ofstream& file, const string& name, const string& format, ...);
	};
}

#endif