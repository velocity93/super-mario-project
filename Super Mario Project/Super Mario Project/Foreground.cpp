////////////////////////////////////////////////////////////////////////
// Foreground.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Foreground.hpp"
#include "Exceptions.hpp"
#include <fstream>
#include <sstream>

using namespace std;
using sf::RenderWindow;

namespace smp
{
	Foreground::Foreground(const string& textureName) : Drawable("textures/backgrounds/" + textureName),
		_animation(1)
	{ 
		loadCfgForeground();
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
		const sf::View& view = app.getView();
		const sf::Vector2f& center = view.getCenter();
		const sf::Vector2f& halfSize = view.getSize();
		float width = _texture->getSprite().getTextureRect().width / _animation.getNbSpritesMax();
		float height = _texture->getSprite().getTextureRect().height;

		_isActive = _position.x >= (center.x - halfSize.x);
		_isActive &= (_position.x + width) <= (center.x + halfSize.x);
		_isActive &= _position.y >= (center.y + halfSize.y);
		_isActive &= (_position.y + height) <= (center.y - halfSize.y);
	}

	void Foreground::loadCfgForeground()
	{
		string fileName = _texture->name() + ".obj";
		ifstream stream(fileName.c_str());
		
		if(stream)
		{
			string word;

			/* We read file to search the keyword and read his value */
			while(getline(stream, word))
			{
				unsigned int found = word.find("nb_sprites=");
				if(found != string::npos)
				{
					int nb_sprites = 0;
					istringstream nbSprites(word.substr(found + 11));
					nbSprites >> nb_sprites;
					_animation.addNbSpritesForGivenState(NORMAL, nb_sprites);

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
					_animation.addFrameDelayForGivenState(NORMAL, frame_delay);
				}
			}
		}
		else
		{
			throw FileNotFoundException(fileName);
		}
	}

    Foreground::~Foreground()
    {
    }
} // namespace
