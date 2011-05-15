////////////////////////////////////////////////////////////////////////
// Object.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Object.hpp"
#include <fstream>
#include <iostream>

namespace Rendering
{
	void Object::update(float time)
	{
		/* Update graphic data */
		//TODO
	}
	
	void Object::render(RenderWindow& app, Screen& screen)
	{
		app.Draw(Sprite(getTexture()->getImage()));
	}

	void Object::loadObject(const string& textureName)
	{
		string fileName = textureName + ".obj";
		
		ifstream stream(fileName.c_str());
		
		if(stream)
		{
			string line;
			while(getline(stream, line))
			{
				string lineSubstr = line.substr(line.find(":") + 2);				
				this->addSpriteNumber(atoi(lineSubstr.c_str()));
			}
		}
		else
		{
			cout << "ERROR : Impossible to open file " << fileName << endl;
		}

	}

    Object::~Object()
    {
    }
} // namespace
