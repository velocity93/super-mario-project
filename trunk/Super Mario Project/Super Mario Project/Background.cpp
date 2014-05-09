////////////////////////////////////////////////////////////////////////
// Background.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Background.hpp"
#include "XMLBackgroundParser.hpp"
#include <fstream>
#include <sstream>

using namespace std;
using sf::Vector2f;
using sf::RenderWindow;

namespace smp
{
	Background::Background(const string& textureName, const Vector2f& position) : 
		Drawable("textures/backgrounds/" + textureName, position),
			_animation(1),
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

	void Background::setVerticalRepetition(bool verticalRepetition)
	{
		_verticalRepetition = verticalRepetition;
	}

	Animation<Background::State>& Background::getAnimation()
	{
		return _animation;
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

			_animation.render(_texture, newPosition, false);

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
		XMLBackgroundParser::getParser()->loadBackground(_texture->name() + ".xml", this);
	}

    Background::~Background()
    {
    }

} // namespace
