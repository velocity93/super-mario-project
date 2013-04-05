////////////////////////////////////////////////////////////////////////
// XMLCheckpointParser.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "XMLCheckpointParser.hpp"
#include "Checkpoint.hpp"
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/parserInternals.h>
#include <libxml/xmlschemas.h>
#include <libxml/xmlschemastypes.h>
#include <string>

using namespace std;

namespace smp
{       
        void AddDataToAnimation(XMLCheckpointContext* checkpointCtxt, Checkpoint::State state, int value)
        {
                Checkpoint* checkpoint = (Checkpoint *)checkpointCtxt->ctxt;

                if(checkpointCtxt->section == "nb_sprites")
                {
                        checkpoint->getAnimation().addNbSpritesForGivenState(state, value);
                }
                else if(checkpointCtxt->section == "frame_delay")
                {
                        checkpoint->getAnimation().addFrameDelayForGivenState(state, value);
                }
        }
        
        void NbSprites_tag(XMLCheckpointContext* checkpointCtxt, const char **)
        {
                checkpointCtxt->section = "nb_sprites";
        }
        
        void FrameDelay_tag(XMLCheckpointContext* checkpointCtxt, const char **)
        {
                checkpointCtxt->section = "frame_delay";
        }
        
        void Active_tag(XMLCheckpointContext* checkpointCtxt, const char ** attrs)
        {
                int value = atoi(attrs[1]);             
                
                AddDataToAnimation(checkpointCtxt, Checkpoint::NOT_PASSED, value);
        }

		void Inactive_tag(XMLCheckpointContext* checkpointCtxt, const char ** attrs)
        {
                int value = atoi(attrs[1]);
                
                AddDataToAnimation(checkpointCtxt, Checkpoint::PASSED, value);
        }        

        /* PARSING CHECKPOINT XML */
        void start_checkpoint_element(void *user_data, const xmlChar *name, const xmlChar **attrs) 
        {
                static const xmlChar *elements[] = {
                        BAD_CAST"nb_sprites",
                        BAD_CAST"active",
                        BAD_CAST"inactive",
                        BAD_CAST"frame_delay"
                };
                static const checkpoint_func functions[] = {
                        NbSprites_tag,
                        Active_tag,
                        Inactive_tag,
                        FrameDelay_tag,
                };
                int i;

                for(i = 0; i < 4; i++)
                {
                        if(!xmlStrcmp(name, elements[i]))
                        {
                                functions[i]((XMLCheckpointContext*)user_data, (const char **)attrs);
                                break;
                        }
                }       
        }

        static void error(void * /*ctx*/, const char * msg, ...)
        {
                cout << "error parsing Checkpoint XML :" << msg << endl;
        }

        void parseCheckpoint(string fileName, Checkpoint* checkpoint)
        {
                XMLCheckpointContext checkpointCtxt;

                /* Initialization of context */
                checkpointCtxt.ctxt = checkpoint;
                checkpointCtxt.section = "";

                xmlSAXHandler sh = {NULL};
                sh.startElement = start_checkpoint_element;
                sh.error = error;

                xmlSAXUserParseFile(&sh, &checkpointCtxt, fileName.c_str());
        }


        XMLCheckpointParser* XMLCheckpointParser::_parser = nullptr;

        XMLCheckpointParser* XMLCheckpointParser::getParser()
        {
                if(_parser == nullptr)
                {
                        _parser = new XMLCheckpointParser();
                }

                return _parser;
        }

        void XMLCheckpointParser::loadCheckpoint(const string &fileName, Checkpoint* checkpoint)
        {
                if(validateSchema("objects/checkpoint.xsd", fileName.c_str()) == 0)
                        parseCheckpoint(fileName, checkpoint);
        }

        XMLCheckpointParser::~XMLCheckpointParser()
        {
                delete _parser;
        }
}