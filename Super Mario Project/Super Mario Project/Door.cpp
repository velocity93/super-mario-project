////////////////////////////////////////////////////////////////////////
// Door.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Door.hpp"

namespace Collisions
{
	int Door::getIndexDestination()
	{
		return _indexDestination;
	}

	string Door::getLevelDestination()
	{
		return _levelDestination;
	}

	Door::State Door::getState()
	{
		return _state;
	}

	void Door::setState(State state)
	{
		_state = state;
	}

	void Door::update(RenderWindow& app)
	{

	}

	void Door::render(RenderWindow& app)
	{
		Sprite sprite = this->getTexture()->getSprite();

		if(_state == CLOSED)
		{
			sprite.SetSubRect(IntRect(0, 0, this->getTexture()->getImage().GetWidth(), this->getTexture()->getImage().GetHeight() / 2));
		}
		else
		{
			sprite.SetSubRect(IntRect(0, this->getTexture()->getImage().GetHeight(), this->getTexture()->getImage().GetWidth(), this->getTexture()->getImage().GetHeight()));
		}

		app.Draw(sprite);
	}


	Door::~Door()
	{
	}
} // namespace
