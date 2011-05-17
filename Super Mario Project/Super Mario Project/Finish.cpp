////////////////////////////////////////////////////////////////////////
// Finish.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Finish.hpp"

namespace Collisions
{
	void Finish::update(RenderWindow& app)
    {
    }

	void Finish::render(RenderWindow& app, const View& view)
    {
		app.Draw(this->getTexture()->getSprite());
    }

    Finish::~Finish()
    {
    }
} // namespace
