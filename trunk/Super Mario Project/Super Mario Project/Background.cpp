////////////////////////////////////////////////////////////////////////
// Background.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Background.hpp"
#include <fstream>

namespace Rendering
{
	Background::Background(const string& textureName) : Object(textureName), _verticalRepetition(false)
	{
		loadCfgBackground(textureName);
	}

	Background::Background(const string& textureName, Coord<float>& position) : Object(textureName, position), _verticalRepetition(false)
	{
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
		const View& view = app.GetDefaultView();

		int nbSprites = this->getSpriteNumbersByState().front();
		int spriteHeight = (this->getTexture()->getImage().GetHeight() / nbSprites);
		Sprite sprite = this->getTexture()->getSprite();

		/* Display background in actual view */
		for(int cptWidth = 0; sprite.GetPosition().x < view.GetRect().Right; cptWidth++)
		{
			if(_verticalRepetition)
			{
				for(int cptHeight = 1; sprite.GetPosition().y < view.GetRect().Bottom; cptHeight++)
				{
					sprite.SetPosition(getPosition().getX() + getTexture()->getImage().GetWidth() * cptWidth, getPosition().getY() + getTexture()->getImage().GetHeight() * cptHeight);
					sprite.SetSubRect(IntRect(0, (((int)time) % nbSprites) * spriteHeight + view.GetRect().Bottom - sprite.GetPosition().y, view.GetRect().Right - sprite.GetPosition().x, (1 + (((int)time) % nbSprites)) * spriteHeight));
					app.Draw(sprite);
				}
			}

			sprite.SetPosition(getPosition().getX() + getTexture()->getImage().GetWidth() * cptWidth, getPosition().getY());
			sprite.SetSubRect(IntRect(0, (((int)time) % nbSprites) * spriteHeight, view.GetRect().Right - sprite.GetPosition().x, (1 + (((int)time) % nbSprites)) * spriteHeight));
			app.Draw(sprite);
		}
	}

	void Background::loadCfgBackground(const string& textureName)
	{
		string fileName = textureName + ".obj";
		ifstream stream(fileName.c_str());
		
		if(stream)
		{
			try
			{
				string word;
				int nbWords;

				/* According to number of sprites, we count how many words we avdance in file */
				if(this->getSpriteNumbersByState()[0] > 1)
					nbWords = 4;
				else
					nbWords = 2;

				/* We put cursor on the keyword */
				for(int i = 0; i < nbWords; i++)
					stream >> word;

				stream >> word;
				if(word == "vertical_repetition=")
				{
					stream >> _verticalRepetition;
				}
				else
					throw exception(" \"vertical_repetition=\" keyword is missing", 1);
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

    Background::~Background()
    {
    }

} // namespace
