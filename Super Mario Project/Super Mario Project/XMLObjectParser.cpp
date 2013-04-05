////////////////////////////////////////////////////////////////////////
// XMLObjectParser.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "XMLObjectParser.hpp"
#include "Object.hpp"
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/parserInternals.h>
#include <libxml/xmlschemas.h>
#include <libxml/xmlschemastypes.h>
#include <sstream>

using namespace std;

namespace smp
{
        void NbSprites_tag(Object* object, const char ** attrs)
        {
			object->getAnimation().addNbSpritesForGivenState(Object::NORMAL, atoi(attrs[1]));
        }

        void FrameDelay_tag(Object* object, const char ** attrs)
        {
			object->getAnimation().addFrameDelayForGivenState(Object::NORMAL, atoi(attrs[1]));
        }

        void start_object_element(void *user_data, const xmlChar *name, const xmlChar **attrs) 
        {
                static const xmlChar *elements[] = {
                        BAD_CAST"nb_sprites",
                        BAD_CAST"frame_delay"
                };
                static const object_func functions[] = {
                        NbSprites_tag,
                        FrameDelay_tag
                };
                int i;

                for(i = 0; i < 2; i++)
                {
                        if(!xmlStrcmp(name, elements[i]))
                        {
                                functions[i]((Object*)user_data, (const char **)attrs);
                                break;
                        }
                }       
        }

        static void error(void * /*ctx*/, const char * msg, ...)
        {
                cout << "error parsing Object XML :" << msg << endl;
        }

        void parseObject(const std::string &fileName, Object* object)
        {
                xmlSAXHandler sh = {NULL};
                sh.startElement = start_object_element;
                sh.error = error;

                xmlSAXUserParseFile(&sh, object, fileName.c_str());
        }

        XMLObjectParser* XMLObjectParser::_parser = nullptr;

        XMLObjectParser* XMLObjectParser::getParser()
        {
                if(_parser == nullptr)
                {
                        _parser = new XMLObjectParser();
                }

                return _parser;
        }

        void XMLObjectParser::loadObject(const std::string &fileName, Object* object)
        {
                if(validateSchema("objects/objects.xsd", fileName.c_str()) == 0)
                        parseObject(fileName, object);
        }

        XMLObjectParser::~XMLObjectParser()
        {
                delete _parser;
        }
}
