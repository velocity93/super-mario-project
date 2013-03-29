////////////////////////////////////////////////////////////////////////
// XMLParser.cpp
// Super Mario Project
// Copyright (C) 2011
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "XMLParser.hpp"
#include "World.hpp"
#include "Level.hpp"
#include "Block.hpp"
#include "MonsterTypes.hpp"
#include "Background.hpp"
#include "Foreground.hpp"
#include "Object.hpp"
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/parserInternals.h>
#include <libxml/xmlschemas.h>
#include <libxml/xmlschemastypes.h>
#include <cstring>
#include <iostream>

using namespace std;
using sf::Vector2f;

namespace smp
{

	/*void XMLParser::loadLevel(string fileName, Level* level)
	{
		if(validateSchema("levels/level.xsd", fileName.c_str()) == 0)
			XMLParsing::parseLevel(fileName, level);
	}*/

	int XMLParser::validateSchema(const char * XMLSchemaFile_shorterNamename, const char * XMLfile_shorterNamename)
	{
		xmlSchemaPtr ptr_schema = NULL;
		xmlSchemaParserCtxtPtr ptr_ctxt;
		xmlSchemaValidCtxtPtr ptr_validctxt;
		int vl_return = 0;
		xmlDocPtr vl_doc;


		/* Open Xml Schema File */
		ptr_ctxt = xmlSchemaNewParserCtxt(XMLSchemaFile_shorterNamename);
		xmlSchemaSetParserErrors(ptr_ctxt,
			(xmlSchemaValidityErrorFunc) fprintf,
			(xmlSchemaValidityWarningFunc) fprintf,
			stderr);

		ptr_schema = xmlSchemaParse(ptr_ctxt);
		xmlSchemaFreeParserCtxt(ptr_ctxt);

		/* If xml schema file wasn't loaded correctly */
		if (ptr_schema == NULL)
		{
			cout << "XMLSCHEMA: Could not open XML Schema " << XMLSchemaFile_shorterNamename << endl;
			xmlSchemaCleanupTypes();
			xmlCleanupParser();
			xmlMemoryDump();
			return -1;
		}

		vl_doc = xmlReadFile(XMLfile_shorterNamename,NULL,0);

		/* If xml file wasn't loaded correctly */
		if (vl_doc == NULL) 
		{
			cout << "XML: Could not parse " << XMLfile_shorterNamename << endl;
		} 
		else 
		{
			/* Loading XML Schema */
			ptr_validctxt = xmlSchemaNewValidCtxt(ptr_schema);
			xmlSchemaSetValidErrors(ptr_validctxt,
				(xmlSchemaValidityErrorFunc) fprintf,
				(xmlSchemaValidityWarningFunc) fprintf,
				stderr);

			/* On valide le fichier XML à partir de la structure du XML Schema */
			vl_return = xmlSchemaValidateDoc(ptr_validctxt, vl_doc);

			if (vl_return == 0)
			{ 
				// If the XML file is valid
				cout << "XMLSCHEMA VERDICT : Xml file " << XMLfile_shorterNamename << " is OK." << endl;
			} 
			else if (vl_return > 0)
			{ 
				// If XML File doesn't correspond to Schema
				cout << "XMLSCHEMA VERDICT : Xml file " << XMLfile_shorterNamename <<  " fails to validate." << endl;
			} 
			else 
			{ 
				// Other error
				cout << "XMLSCHEMA VERDICT : " << XMLfile_shorterNamename << " validation generated an internal error." << endl;
			}

			xmlSchemaFreeValidCtxt(ptr_validctxt);
			xmlFreeDoc(vl_doc);
		}

		return vl_return;
	}

	XMLParser::~XMLParser() { }
}
