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

	void Door::setLevelDestination(string levelDestination)
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

	void Door::render(RenderWindow& app)
	{

	}

	Door* Door::loadDoor(Coord<float> position, int indexDestination, string levelDestination, State state)
	{
		Door* door = new Door(position, indexDestination, levelDestination, state);

		// Load texture with the 'name' parameter
		// door->loadTexture(name);

		return door;
	}


	Door::~Door()
	{
	}
} // namespace
