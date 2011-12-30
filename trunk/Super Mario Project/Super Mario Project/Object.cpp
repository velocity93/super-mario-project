////////////////////////////////////////////////////////////////////////
// Object.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Object.hpp"
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

	void Object::update(RenderWindow&)
	{
		_animation.update();
	}
	
	void Object::render(RenderWindow& app)
	{
		_animation.render(_texture, app, _position, false);
	}

	void Object::serialize(ofstream& file, const string& tabs)
	{
		file << tabs << "<object ";
		file << "img=\"" << _texture->shorterName() << "\" ";
		file << "positionX=\"" << _position.x << "\" ";
		file << "positionY=\"" << _position.y << "\"/>" << endl;
	}

	void Object::setActivity(RenderWindow& app)
	{

	}

	void Object::loadCfgObject(const string& textureName)
	{
		string fileName = _texture->name() + ".obj";
		ifstream file(fileName.c_str());
		
		if(file)
		{
			string word;

			/* We read file to search the keyword and read his value */
			while(getline(file, word))
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

				found = word.find("v_anim=");
				if(found != string::npos)
				{
					int frame_delay = 0;
					istringstream frameDelay(word.substr(found + 7));
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
