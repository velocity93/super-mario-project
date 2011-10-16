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
	Object::Object(const string& textureName) : Drawable("textures/objects/" + textureName)
	{
		loadCfgObject(textureName);
		_animation.setCurrentState(State::NORMAL);
	}

	Object::Object(const string& textureName,Vector2f& position) : Drawable("textures/objects/" + textureName, position)
	{ 
		loadCfgObject(textureName);
		_animation.setCurrentState(State::NORMAL);
	}

	void Object::update(RenderWindow& app)
	{
		_animation.update(app);
	}
	
	void Object::render(RenderWindow& app)
	{
		_animation.render(_texture, app, _position, false);
	}

	void Object::loadCfgObject(const string& textureName)
	{
		string fileName = _texture->name() + ".obj";
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

					if(nb_sprites == 1)
						break; /* No animation */
					else
						continue;
				}

				found = word.find("frame_delay=");
				if(found != string::npos)
				{
					int frame_delay = 0;
					istringstream frameDelay(word.substr(found + 12));
					frameDelay >> frame_delay;
					_animation.addFrameDelayForGivenState(State::NORMAL, frame_delay);
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
