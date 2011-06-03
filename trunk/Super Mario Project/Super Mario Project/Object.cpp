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
#include <exception>

namespace Rendering
{
	Object::Object(const string& textureName) : Drawable(textureName) 
	{ 
		loadCfgObject(textureName);
	}

	Object::Object(const string& textureName, Coord<float>& position) : Drawable(textureName, position)
	{ 
		loadCfgObject(textureName);
	}

	void Object::update(RenderWindow& app)
	{
		/* Compute coord sprite according to elapsedTime */
		const View& view = app.GetDefaultView();
		int nbSprites = _spriteNumbersByState.front();
		int spriteHeight = _texture->getImage().GetHeight() / nbSprites;
		Sprite sprite = _texture->getSprite();
		int cpt = 0;

		/* If object is smaller than screen size */
		while(sprite.GetPosition().x < view.GetRect().Right)
		{
			sprite.SetPosition(_position.getX() + _texture->getImage().GetWidth() * cpt, _position.getY());
			sprite.SetSubRect(IntRect(0, (((int)time) % nbSprites) * spriteHeight, _texture->getImage().GetWidth(), (1 + (((int)time) % nbSprites)) * spriteHeight));
			cpt++;
		}
	}
	
	void Object::render(RenderWindow& app)
	{
		app.Draw(_texture->getSprite());
	}

	void Object::loadCfgObject(const string& textureName)
	{
		string fileName = textureName + ".obj";
		
		ifstream stream(fileName.c_str());
		
		/* test if the stream is open*/
		if(stream)
		{
			try
			{
				string word;
				int value = 0;

				stream >> word;
				if(word == "nb_sprites=")
				{
					stream >> value;
					_spriteNumbersByState.push_back(value);
					value = 0;
				}
				else
					throw exception(" \"nb_sprites=\" keyword is missing", 1);

				if(_spriteNumbersByState[0] > 1)
				{
					stream >> word;
					if(word == "v_anim=")
					{
						stream >> value;
						_animationSpeeds.push_back(value);
					}
					else
						throw exception("\"v_anim=\" keyword is missing", 1);
				}
			}
			catch(exception& e)
			{
				cout << "Exception occured while reading " << fileName << " : " << e.what() << endl;
				getchar();
				exit(1);
			}
		}
		else
		{
			cout << "Exception occured while opening " << fileName << " : file doesn't exist." << endl;
			getchar();
			exit(1);
		}

	}

    Object::~Object()
    {
    }
} // namespace
