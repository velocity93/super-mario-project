////////////////////////////////////////////////////////////////////////
// Background.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Background.hpp"
#include <fstream>
#include <sstream>

namespace Rendering
{
	Background::Background(const string& textureName, const View& view) : Object(textureName), _verticalRepetition(false)
	{
		configureBackground(textureName, view);
	}

	Background::Background(const string& textureName, const View& view,Vector2f& position) : Object(textureName, position), _verticalRepetition(false)
	{
		configureBackground(textureName, view);
	}

	void Background::configureBackground(const string& textureName, const View& view)
	{
		/* Loading informations */
		loadCfgBackground(textureName);

		/* Compute max number of displayed sprites */
		/*Sprite sprite = _texture->getSprite();
		int spriteWidth = _texture->getImage()->GetWidth() / _spriteNumbersByState.front();
		float widthFactor = ceil((view.GetRect().GetWidth() / _texture->getImage()->GetWidth()));
		float heightFactor = ceil((view.GetRect().GetWidth() / _texture->getImage()->GetHeight()));

		for(int i = 0; i < widthFactor; i++)
		{
			if(_verticalRepetition)
			{
				for(int j = 0; j < heightFactor; j++)
				{
					sprite.SetPosition(_position.x + spriteWidth * i, _position.y + _texture->getImage()->GetHeight() * j);
					_sprites.push_back(sprite);
				}
			}

			sprite.SetPosition(_position.x + spriteWidth * i, _position.y);
			_sprites.push_back(sprite);
		}*/
	}



	bool Background::getVerticalRepetition()
	{
		return _verticalRepetition;
	}

	void Background::update(RenderWindow& app)
	{
		/*const View& view = app.GetDefaultView();*/

		//int nbSprites = _spriteNumbersByState.front();
		//int spriteHeight = _texture->getImage()->)->GetHeight();
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

		for(itSprites = _sprites.begin(); itSprites != _sprites.end(); ++itSprites)
			app.Draw(*itSprites);
	}

	void Background::loadCfgBackground(const string& textureName)
	{
		string fileName = textureName + ".obj";
		ifstream stream(fileName.c_str());
		
		if(stream)
		{
			string word;

			/* We read file to search the keyword and read his value */
			while(getline(stream, word))
			{
				int found = word.find("vertical_repetition=");
				if(found != string::npos)
				{
					istringstream verticalRepetition(word.substr(found + 20));
					verticalRepetition >> _verticalRepetition;
					break; // We don't have to read more
				}
			}
		}
		else
		{
			string exceptionName = "Exception occured while opening " + fileName;
			throw exception(exceptionName.c_str());
		}

		/* initialization to upper sprite */
		//_texture->setSubRect(0, 0, _texture->getImage()->GetWidth(), _texture->getImage()->GetHeight() / _spriteNumbersByState.front());
	}

    Background::~Background()
    {
    }

} // namespace
