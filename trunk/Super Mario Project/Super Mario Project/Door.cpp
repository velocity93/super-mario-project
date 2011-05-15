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

	void Door::setIndexDestination(int indexDestination)
	{
		_indexDestination = indexDestination;
	}

	void Door::setLevelDestination(const string& levelDestination)
	{
		_levelDestination = levelDestination;
	}

	void Door::setState(State state)
	{
		_state = state;
	}

	void Door::update(float time)
	{

	}

	void Door::render(RenderWindow& app, Screen& screen)
	{

	}


	Door::~Door()
	{
	}
} // namespace
