////////////////////////////////////////////////////////////////////////
// XMLProjectileParser.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_XML_PROJECTILE_PARSER
#define HPP_XML_PROJECTILE_PARSER

#include "XMLParser.hpp"
#include <string>

namespace smp
{
	// forward declaration
	class Projectile;

	typedef struct : XMLParserContext
	{
		std::string section;
	} XMLProjectileContext;

	typedef void (*proj_func)(XMLProjectileContext *, const char **);

	class XMLProjectileParser : XMLParser
	{
	public :
		static XMLProjectileParser* getParser();

		void loadProjectile(const std::string &fileName, Projectile* proj);
		virtual ~XMLProjectileParser();

	private :
		static XMLProjectileParser* _parser;

		XMLProjectileParser() { }
	};
}

#endif
