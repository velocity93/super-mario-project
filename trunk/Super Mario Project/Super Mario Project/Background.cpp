////////////////////////////////////////////////////////////////////////
// Background.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Background.hpp"

namespace Rendering
{
	bool Background::getVerticalRepetition()
	{
		return _verticalRepetition;
	}

	void Background::setVerticalRepetition(bool verticalRepetition)
	{
		_verticalRepetition = verticalRepetition;
	}

	void Background::update(float time)
	{
		int nbSprites = this->getSpriteNumbersByState().front();
		int spriteHeight = (this->getTexture()->getImage().GetHeight() / nbSprites);

		/* Compute coord sprite according to elapsedTime */
		this->getTexture()->setCoordSprite(0, (((int)time) % nbSprites) * spriteHeight, this->getTexture()->getImage().GetWidth(), (1 + (((int)time) % nbSprites)) * spriteHeight);
		

	}

	void Background::render(RenderWindow& app, Screen& screen)
	{
		app.Draw(this->getTexture()->getSprite());
	}

    Background::~Background()
    {
    }

} // namespace
