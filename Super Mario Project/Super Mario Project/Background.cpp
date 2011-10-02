////////////////////////////////////////////////////////////////////////
// Background.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Background.hpp"
#include <fstream>
#include <sstream>

namespace Rendering
{
	Background::Background(const string& textureName) : Object(textureName), _verticalRepetition(false)
	{
		/* Loading informations */
		loadCfgBackground(textureName);
	}

	Background::Background(const string& textureName, Vector2f& position) : Object(textureName, position), _verticalRepetition(false)
	{
		_position = position;

		/* Loading informations */
		loadCfgBackground(textureName);
	}

	bool Background::getVerticalRepetition()
	{
		return _verticalRepetition;
	}

	void Background::update(RenderWindow& app)
	{
		Object::update(app);
	}

	void Background::render(RenderWindow& app)
	{
		Object::render(app);
	}

	void Background::loadCfgBackground(const string& textureName)
	{
		string fileName = textureName + ".obj";
		ifstream stream(fileName.c_str());
		
		if(stream)
		{
			string word;

			/* We read file to search the keyword and read his value */
			while(getline(stream, word))
			{
				int found = word.find("vertical_repetition=");
				if(found != string::npos)
				{
					istringstream verticalRepetition(word.substr(found + 20));
					verticalRepetition >> _verticalRepetition;
					break; // We don't have to read more
				}
			}
		}
		else
		{
			string exceptionName = "Exception occured while opening " + fileName;
			throw exception(exceptionName.c_str());
		}
	}

    Background::~Background()
    {
    }

} // namespace
