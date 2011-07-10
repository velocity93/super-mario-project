////////////////////////////////////////////////////////////////////////
// Foreground.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Foreground.hpp"

namespace Rendering
{
	Foreground::Foreground(const string& textureName) : Object(textureName)
	{ 
		Object::loadCfgObject(textureName);
	}

	void Foreground::update(RenderWindow& app)
	{
		Object::update(app);
	}

	void Foreground::render(RenderWindow& app)
	{
		Object::render(app);
	}


    Foreground::~Foreground()
    {
    }
} // namespace
