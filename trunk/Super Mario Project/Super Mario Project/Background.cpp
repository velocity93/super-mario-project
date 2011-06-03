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
	Background::Background(const string& textureName, const View& view) : Object(textureName), _verticalRepetition(false)
	{
		configureBackground(textureName, view);
	}

	Background::Background(const string& textureName, const View& view, Coord<float>& position) : Object(textureName, position), _verticalRepetition(false)
	{
		configureBackground(textureName, view);
	}

	void Background::configureBackground(const string& textureName, const View& view)
	{
		/* Loading informations */
		loadCfgBackground(textureName);

		/* Compute max number of displayed sprites */
		Sprite sprite = _texture->getSprite();
		int spriteWidth = _texture->getImage().GetWidth() / _spriteNumbersByState.front();
		float widthFactor = ceil((view.GetRect().GetWidth() / _texture->getImage().GetWidth()));
		float heightFactor = ceil((view.GetRect().GetWidth() / _texture->getImage().GetHeight()));

		for(int i = 0; i < widthFactor; i++)
		{
			if(_verticalRepetition)
			{
				for(int j = 0; j < heightFactor; j++)
				{
					sprite.SetPosition(_position.getX() + spriteWidth * i, _position.getY() + _texture->getImage().GetHeight() * j);
					_sprites.push_back(sprite);
				}
			}

			sprite.SetPosition(_position.getX() + spriteWidth * i, _position.getY());
			_sprites.push_back(sprite);
		}
	}



	bool Background::getVerticalRepetition()
	{
		return _verticalRepetition;
	}

	void Background::update(RenderWindow& app)
	{
		//const View& view = app.GetDefaultView();

		//int nbSprites = _spriteNumbersByState.front();
		//int spriteHeight = (_texture->getImage().GetHeight() / nbSprites);
		//Sprite sprite = _texture->getSprite();
		//vector<Sprite>::iterator itSprites;

		//for(itSprites = _sprites.begin(); itSprites < _sprites.end(); itSprites++)
		//{
		//	itSprites->SetSubRect(IntRect(max(view.GetCenter().x - view.GetHalfSize().x, itSprites->GetPosition().x),
		//		max(view.GetCenter().y - view.GetHalfSize().y, itSprites->GetPosition().y),
		//		min(view.GetCenter().x + view.GetHalfSize().x, itSprites->GetPosition().x + itSprites->GetSize().x),
		//		min(view.GetCenter().y + view.GetHalfSize().y, itSprites->GetPosition().y + itSprites->GetSize().y)));
		//}
	}

	void Background::render(RenderWindow& app)
	{
		vector<Sprite>::iterator itSprites;

		for(itSprites = _sprites.begin(); itSprites < _sprites.end(); itSprites++)
			app.Draw(*itSprites);
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
				if(_spriteNumbersByState[0] > 1)
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

		/* initialization to upper sprite */
		_texture->setSubRect(0, 0, _texture->getImage().GetWidth(), _texture->getImage().GetHeight() / _spriteNumbersByState.front());
	}

    Background::~Background()
    {
    }

} // namespace
