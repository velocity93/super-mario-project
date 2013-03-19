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
	Object::Object(const string& textureName, Vector2f& position) : Drawable("textures/objects/" + textureName, position), _animation(1)
	{ 
		loadCfgObject();
		_animation.setCurrentState(NORMAL);
	}

	void Object::updateGraphicData(RenderWindow& app)
	{
		setActivity(app);

		if(_isActive)
			_animation.update();
	}
	
	void Object::render(RenderWindow& app)
	{
		if(_isActive)
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
		const sf::View& view = app.getDefaultView();
		const sf::Vector2f& center = view.getCenter();
		const sf::Vector2f& halfSize = view.getSize();
		float width = _texture->getSprite().getTextureRect().width / _animation.getNbSpritesMax();
		float height = _texture->getSprite().getTextureRect().height;

		_isActive = _position.x >= (center.x - halfSize.x);
		_isActive &= (_position.x + width) <= (center.x + halfSize.x);
		_isActive &= _position.y >= (center.y + halfSize.y);
		_isActive &= (_position.y + height) <= (center.y - halfSize.y);

	}

	void Object::loadCfgObject()
	{
		string fileName = _texture->name() + ".obj";
		ifstream file(fileName.c_str());
		
		if(file)
		{
			string word;

			/* We read file to search the keyword and read his value */
			while(getline(file, word))
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

				found = word.find("v_anim=");
				if(found != string::npos)
				{
					int frame_delay = 0;
					istringstream frameDelay(word.substr(found + 7));
					frameDelay >> frame_delay;
					_animation.addFrameDelayForGivenState(NORMAL, frame_delay);
				}
			}
		}
		else
		{
			throw "Exception occured while opening " + fileName;
		}
	}

    Object::~Object()
    {
    }
} // namespace
