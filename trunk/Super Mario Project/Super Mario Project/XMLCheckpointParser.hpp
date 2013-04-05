////////////////////////////////////////////////////////////////////////
// XMLCheckpointParser.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_XML_CHECKPOINT_PARSER
#define HPP_XML_CHECKPOINT_PARSER

#include "XMLParser.hpp"
#include <string>

namespace smp
{
        // Forward declaration
        class Checkpoint;
		
		typedef struct : XMLParserContext
        {
                std::string section;
        } XMLCheckpointContext;

        typedef void (*checkpoint_func)(XMLCheckpointContext *, const char **);

        class XMLCheckpointParser : XMLParser
        {
        public :
                static XMLCheckpointParser* getParser();

                void loadCheckpoint(const std::string &fileName, Checkpoint* checkpoint);
                virtual ~XMLCheckpointParser();

        private :
                static XMLCheckpointParser* _parser;

                XMLCheckpointParser() { }
        };
}

#endif