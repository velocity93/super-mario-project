////////////////////////////////////////////////////////////////////////
// Foreground.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Foreground.hpp"
#include <fstream>
#include <sstream>

namespace Rendering
{
	Foreground::Foreground(const string& textureName) : Drawable("textures/backgrounds/" + textureName)
	{ 
		loadCfgForeground(textureName);
	}

	void Foreground::updateGraphicData(RenderWindow& app)
	{
		setActivity(app);

		if(_isActive)
			_animation.update();
	}

	void Foreground::render(RenderWindow& app)
	{
		if(_isActive)
			_animation.render(_texture, app, _position, false);
	}

	void Foreground::serialize(ofstream& file, const string& tabs)
	{
		file << tabs << "<foreground ";
		file << "img=\"" << _texture->shorterName() << "\" ";
		file << "positionX=\"" << _position.x << "\" ";
		file << "positionY=\"" << _position.y << "\"/>" << endl;
	}

	void Foreground::setActivity(RenderWindow& app)
	{
		const sf::View& view = app.GetView();
		const sf::Vector2f& center = view.GetCenter();
		const sf::Vector2f& halfSize = view.GetHalfSize();
		int width = _texture->getSprite().GetSize().x / _animation.getNbSpritesMax();
		int height = _texture->getSprite().GetSize().y;

		_isActive = _position.x >= (center.x - halfSize.x);
		_isActive &= (_position.x + width) <= (center.x + halfSize.x);
		_isActive &= _position.y >= (center.y + halfSize.y);
		_isActive &= (_position.y + height) <= (center.y - halfSize.y);
	}

	void Foreground::loadCfgForeground(const string& textureName)
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

    Foreground::~Foreground()
    {
    }
} // namespace
