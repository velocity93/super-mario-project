////////////////////////////////////////////////////////////////////////
// Tileset.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Tileset.hpp"
#include <fstream>
#include <sstream>

namespace Collisions
{
	Tileset::Tileset(const string& textureName) : Resource("textures\\blocs\\" + textureName),
		_nbSprites(Vector2i()),
		_frameDelay(0)
	{
		loadConfiguration(textureName);
	}

	int Tileset::getFrameDelay()
	{
		return _frameDelay;
	}

	Vector2i Tileset::getNbSprites()
	{
		return _nbSprites;
	}

	void Tileset::loadConfiguration(const string& textureName)
	{
		/* Build cfg file path */
		string fileName = "textures\\blocs\\";
		string buffer = textureName;
		while(buffer.find_first_of("\\") != string::npos)
		{

			fileName += buffer.substr(0, buffer.find_first_of("\\"));
			buffer = buffer.substr(buffer.find_first_of("\\") + 1, buffer.length());

			if(buffer.find_first_of("\\") != string::npos)
				fileName += "\\";
			else
				fileName += fileName.substr(fileName.find_last_of("\\"), fileName.length()); 
		}

		fileName += ".cfg";

		ifstream stream(fileName.c_str());

		if(stream)
		{
			int phys;

			/* Number of sprites in width and height */
			stream >> _nbSprites.y;
			stream >> _nbSprites.x;

			for(int i = 0; i < _nbSprites.x * _nbSprites.y; ++i)
			{
				/* If we have only one line, then we have only one block 
				 * following by his animation, with the same physic obviously 
				 */
				if(_nbSprites.y == 1 && i == 0)
					stream >> hex >> phys;

				_physics.push_back(phys);
			}

			/* Frame delay */
			stream >> _frameDelay;
		}
		else
		{
			// Exception
		}
	}

	Tileset::~Tileset()
	{
		release();
	}
}