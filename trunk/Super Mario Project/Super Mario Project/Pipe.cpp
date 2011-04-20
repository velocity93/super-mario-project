////////////////////////////////////////////////////////////////////////
// Pipe.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Pipe.hpp"

namespace Collisions
{
	Pipe::Direction Pipe::getDirection()
	{
		return _direction;
	}

	Monster Pipe::getMonster()
	{
		return _monster;
	}

	int Pipe::getMonsterExitTime()
	{
		return _monsterExitTime;
	}

	void Pipe::setDirection(Pipe::Direction direction)
	{
		_direction = direction;
	}

	void Pipe::setMonster(Monster& monster)
	{
		_monster = monster;
	}

	void Pipe::setMonsterExitTime(int monsterExitTime)
	{
		_monsterExitTime = monsterExitTime;
	}

	void Pipe::update(float time)
    {
    }

	void Pipe::render(RenderWindow& app)
    {
    }

    Pipe::~Pipe()
    {
    }
} // namespace
