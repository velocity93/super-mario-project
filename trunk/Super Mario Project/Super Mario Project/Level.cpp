////////////////////////////////////////////////////////////////////////
// Level.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Level.hpp"

namespace SuperMarioProject
{
	Coord<int> Level::getSize()
	{
		return _size;
	}

	Coord<int> Level::getBlockSize()
	{
		return _blockSize;
	}

	void Level::update(float time)
	{

	}

	void Level::render(RenderWindow& app)
	{

	}

    Level::~Level()
    {
    }
} // namespace
