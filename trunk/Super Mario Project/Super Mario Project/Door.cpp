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
		Sprite sprite = _texture->getSprite();

		if(_state == CLOSED)
		{
			sprite.SetSubRect(IntRect(0, 0, _texture->getImage()->GetWidth(), _texture->getImage()->GetHeight() / 2));
		}
		else
		{
			sprite.SetSubRect(IntRect(0, _texture->getImage()->GetHeight(), _texture->getImage()->GetWidth(), _texture->getImage()->GetHeight()));
		}

		app.Draw(sprite);
	}


	Door::~Door()
	{
	}
} // namespace
