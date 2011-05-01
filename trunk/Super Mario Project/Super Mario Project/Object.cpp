////////////////////////////////////////////////////////////////////////
// Object.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Object.hpp"

namespace Rendering
{
	void Object::update(float time)
	{
		/* Update graphic data */
		//TODO
	}
	
	void Object::render(RenderWindow& app)
	{
		Sprite sprite;
		sprite.SetImage(getTexture()->getImage());
		sprite.SetPosition(this->getPosition().getX(), this->getPosition().getY());

		app.Draw(sprite);
	}

    Object::~Object()
    {
    }
} // namespace
