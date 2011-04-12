////////////////////////////////////////////////////////////////////////
// Pipe.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_PIPE
#define HPP_PIPE

#include "Door.hpp"
#include "Monster.hpp"

namespace Collisions
{
	enum Pipe_direction
	{
		TO_TOP,
		TO_LEFT,
		TO_RIGHT,
		TO_BOTTOM
	};

    class Pipe : Door
    {
    public:
		Pipe() : Door(), direction(TO_TOP), monster(Monster()), monsterExitTime(0) { }
		Pipe(Coord<float> Position, int IndexDoorDestination, string LevelDestination, IO_state State, Pipe_direction Direction, Monster Monster, int MonsterExitTime) 
			: Door(Position, IndexDoorDestination, LevelDestination, State), direction(Direction), monster(Monster), monsterExitTime(MonsterExitTime) { }

		Pipe_direction GetDirection()
		{
			return direction;
		}

		Monster GetMonster()
		{
			return monster;
		}

		int GetMonsterExitTime()
		{
			return monsterExitTime;
		}

		void SetDirection(Pipe_direction Direction)
		{
			direction = Direction;
		}

		void SetMonster(Monster Monster)
		{
			monster = Monster;
		}

		void SetMonsterExitTime(int MonsterExitTime)
		{
			monsterExitTime = MonsterExitTime;
		}

		void Update();
		void Render();
        ~Pipe();
		
    private:
		Pipe_direction direction;
		Monster monster;
		int monsterExitTime;
    };
} // namespace

#endif // HPP_PIPE
