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
		Pipe() : Door(), _direction(TO_TOP), _monster(nullptr), _monsterExitTime(0) { }
		Pipe(Coord<float> position, int indexDoorDestination, string levelDestination, State state, Direction direction, Monster* monster) 
			: Door(position, indexDoorDestination, levelDestination, state), _direction(direction), _monster(monster) { }

		/* getters and setters */
		Direction getDirection();
		Monster* getMonster();
		int getMonsterExitTime();
		void setDirection(Direction Direction);
		void setMonster(Monster* Monster);
		void setMonsterExitTime(int MonsterExitTime);

		/* Methods */
		void update(float time);
		void render(RenderWindow& app);
		static Pipe* loadPipe(string name, Direction direction, int lenght, Coord<float> position, State state, 
			int indexDestination, string levelDestination, Monster* monster);

		/* Destructor */
        virtual ~Pipe();
		
    private:
		Direction _direction;
		Monster* _monster;
		int _lenght;
		int _monsterExitTime;
    };
} // namespace

#endif // HPP_PIPE
