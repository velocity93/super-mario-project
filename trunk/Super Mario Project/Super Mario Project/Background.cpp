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

	}
	void Background::render(RenderWindow& app)
	{

	}

    Background::~Background()
    {
    }

} // namespace
