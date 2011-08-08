////////////////////////////////////////////////////////////////////////
// Object.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Object.hpp"
#include <fstream>
#include <sstream>
#include <exception>

namespace Rendering
{
	Object::Object(const string& textureName) : Drawable(textureName) 
	{
		loadCfgObject(textureName);
	}

	Object::Object(const string& textureName,Vector2f& position) : Drawable(textureName, position)
	{ 
		loadCfgObject(textureName);
	}

	void Object::update(RenderWindow& app)
	{

	}
	
	void Object::render(RenderWindow& app)
	{
		_animation.render(_texture, app, _position);
	}

	void Object::loadCfgObject(const string& textureName)
	{
		string fileName = textureName + ".obj";
		ifstream stream(fileName.c_str());
		
		if(stream)
		{
			string word;

			/* We read file to search the keyword and read his value */
			while(getline(stream, word))
			{
				int found = word.find("nb_sprites=");
				if(found != string::npos)
				{
					int nb_sprites = 0;
					istringstream nbSprites(word.substr(found + 11));
					nbSprites >> nb_sprites;
					_animation.addNbSpritesForGivenState(State::NORMAL, nb_sprites);
					continue;
				}

				found = word.find("v_anim=");
				if(found != string::npos)
				{
					int v_anim = 0;
					istringstream vAnim(word.substr(found + 7));
					vAnim >> v_anim;
					_animation.addVAnimForGivenState(State::NORMAL, v_anim);
				}
			}
		}
		else
		{
			string exceptionName = "Exception occured while opening " + fileName;
			throw exception(exceptionName.c_str());
		}
	}

    Object::~Object()
    {
    }
} // namespace
