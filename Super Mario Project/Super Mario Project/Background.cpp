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
	Background::Background(const string& textureName) : Drawable("textures/backgrounds/" + textureName), _verticalRepetition(false), _position(Vector2f(0,0))
	{
		/* Loading informations */
		loadCfgBackground();

		_animation.setCurrentState(NORMAL);
		_texture->setRepeated(true);
	}

	Background::Background(const string& textureName, Vector2f& position) : 
		Drawable(textureName, position),
			_verticalRepetition(false),
			_position(position)
	{

		/* Loading informations */
		loadCfgBackground();

		_animation.setCurrentState(NORMAL);
		_texture->setRepeated(true);
	}

	bool Background::getVerticalRepetition()
	{
		return _verticalRepetition;
	}

	void Background::updateGraphicData(RenderWindow&/*app*/)
	{
		if(_isActive)
			_animation.update();
	}

	void Background::render(RenderWindow& app)
	{
		float x = _position.x, widthX = x + _texture->getSize().x / _animation.getNbSpritesMax();
		float viewXWidth = app.getView().getCenter().x + app.getView().getSize().x / 2;

		/* We draw texture as many times, as needed to fill view */
		while(x < viewXWidth || widthX < viewXWidth)
		{
			Vector2f newPosition = Vector2f(x, _position.y);

			_animation.render(_texture, app, newPosition, false);

			x += _texture->getSize().x / _animation.getNbSpritesMax();
			widthX = x + _texture->getSize().x / _animation.getNbSpritesMax();
		}
	}

	void Background::serialize(ofstream& file, const string& tabs)
	{
		file << tabs << "<background ";
		file << "img=\"" << _texture->shorterName() << "\" ";
		file << "positionX=\"" << _position.x << "\" ";
		file << "positionY=\"" << _position.y << "\"/>" << endl;
	}

	void Background::loadCfgBackground()
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

				found = word.find("vertical_repetition=");
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
	}

    Background::~Background()
    {
    }

} // namespace
