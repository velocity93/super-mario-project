////////////////////////////////////////////////////////////////////////
// XMLObjectParser.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_XML_OBJECT_PARSER
#define HPP_XML_OBJECT_PARSER

#include "XMLParser.hpp"
#include <string>

namespace smp
{
        // Forward declaration
        class Object;

        typedef void (*object_func)(Object *, const char **);

        class XMLObjectParser : XMLParser
        {
        public :
                static XMLObjectParser* getParser();

                void loadObject(const std::string &fileName, Object* object);
                virtual ~XMLObjectParser();

        private :
                static XMLObjectParser* _parser;

                XMLObjectParser() { }
        };
}

#endif