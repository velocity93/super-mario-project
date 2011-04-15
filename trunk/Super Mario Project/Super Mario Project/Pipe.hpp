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
	class Pipe : public Door
    {
		enum Direction
		{
			TO_TOP,
			TO_LEFT,
			TO_RIGHT,
			TO_BOTTOM
		};


    public:
		/* Constructors */
		Pipe() : Door(), _direction(TO_TOP), _monster(Monster()), _monsterExitTime(0) { }
		Pipe(Coord<float> position, int indexDoorDestination, string levelDestination, State state, Direction direction, Monster& monster, int monsterExitTime) 
			: Door(position, indexDoorDestination, levelDestination, state), _direction(direction), _monster(monster), _monsterExitTime(monsterExitTime) { }

		/* getters and setters */
		Direction getDirection();
		Monster getMonster();
		int getMonsterExitTime();
		void setDirection(Direction Direction);
		void setMonster(Monster& Monster);
		void setMonsterExitTime(int MonsterExitTime);

		/* Methods */
		void update(float time);
		void render();

		/* Destructor */
        ~Pipe();
		
    private:
		Direction _direction;
		Monster _monster;
		int _monsterExitTime;
    };
} // namespace

#endif // HPP_PIPE
