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
		time;
	}
	
	void Object::render(RenderWindow& app)
	{
		/* Compute coord sprite according to elapsedTime */
		const View& view = app.GetDefaultView();
		int nbSprites = this->getSpriteNumbersByState().front();
		int spriteHeight = (this->getTexture()->getImage().GetHeight() / nbSprites);		
		Sprite sprite = this->getTexture()->getSprite();
		int cpt = 0;

		/* If object is smaller than screen size */
		while(sprite.GetPosition().x < view.GetRect().Right)
		{
			sprite.SetPosition(getPosition().getX() + getTexture()->getImage().GetWidth() * cpt, getPosition().getY());
			sprite.SetSubRect(IntRect(0, (((int)time) % nbSprites) * spriteHeight, this->getTexture()->getImage().GetWidth(), (1 + (((int)time) % nbSprites)) * spriteHeight));
			app.Draw(sprite);
			cpt++;
		}
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
					this->addSpriteNumber(value);
					value = 0;
				}
				else
					throw exception(" \"nb_sprites=\" keyword is missing", 1);

				if(this->getSpriteNumbersByState()[0] > 1)
				{
					stream >> word;
					if(word == "v_anim=")
					{
						stream >> value;
						this->addAnimationSpeed(value);
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
