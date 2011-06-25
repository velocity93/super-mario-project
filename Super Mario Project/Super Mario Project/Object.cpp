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
		/* Compute coord sprite according to elapsedTime */
		const View& view = app.GetDefaultView();
		int nbSprites = _spriteNumbersByState.front();
		int spriteHeight = _texture->getImage()->GetHeight() / nbSprites;
		Sprite sprite = _texture->getSprite();
		int cpt = 0;

		/* If object is smaller than screen size */
		while(sprite.GetPosition().x < view.GetRect().Right)
		{
			sprite.SetPosition(_position.x + _texture->getImage()->GetWidth() * cpt, _position.y);
			sprite.SetSubRect(IntRect(0, (((int)time) % nbSprites) * spriteHeight, _texture->getImage()->GetWidth(), (1 + (((int)time) % nbSprites)) * spriteHeight));
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
					_spriteNumbersByState.push_back(nb_sprites);
					continue;
				}

				found = word.find("v_anim=");
				if(found != string::npos)
				{
					int v_anim = 0;
					istringstream nbSprites(word.substr(found + 7));
					nbSprites >> v_anim;
					_animationSpeeds.push_back(v_anim);
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
