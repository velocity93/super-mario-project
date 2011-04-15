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
	int Door::getIndexDoorDestination()
	{
		return _indexDoorDestination;
	}

	string Door::getLevelDestination()
	{
		return _levelDestination;
	}

	Door::State Door::getState()
	{
		return _state;
	}

	void Door::setIndexDoorDestination(int indexDoorDestination)
	{
		_indexDoorDestination = indexDoorDestination;
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

	void Door::render()
	{

	}


	Door::~Door()
	{
	}
} // namespace
