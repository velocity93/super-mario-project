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

#include "Collisionable.hpp"
#include "Monster.hpp"

#define MONSTER_EXIT_TIME 4000

namespace Collisions
{
	class Pipe : public Collisionable
    {

	public:
		typedef enum 
		{
			OPEN,
			CLOSED
		} State;

		enum Direction
		{
			TO_TOP,
			TO_LEFT,
			TO_RIGHT,
			TO_BOTTOM
		};
    
		/* Constructors */
		Pipe(const string& textureName) : Collisionable("textures/pipes/" + textureName),
			_direction(TO_TOP), 
			_monster(nullptr), 
			_monsterExitDuration(Clock()), 
			_lenght(1) { }
		Pipe(const string& textureName,Vector2f position,
			int indexPipeDestination, 
			const string& levelDestination, 
			State state, 
			int lenght, 
			Direction direction, 
			Monster* monster)
			: Collisionable("textures/pipes/" + textureName, position), 
			_indexDestination(indexPipeDestination), 
			_levelDestination(levelDestination), 
			_state(state), 
			_lenght(lenght), 
			_direction(direction), 
			_monster(monster),
			_monsterExitDuration(Clock()) { }

		/* getters and setters */
		Direction getDirection();
		Monster* getMonster();
		int getLenght();
		float getMonsterExitDuration();
		void setDirection(Direction Direction);
		void setMonster(Monster* Monster);

		/* Methods */
		void update(RenderWindow& app);
		void render(RenderWindow& app);

		/* Destructor */
        virtual ~Pipe();
		
    private:
		int _indexDestination;
		string _levelDestination;
		State _state;
		Direction _direction;
		Monster* _monster;
		int _lenght;
		Clock _monsterExitDuration;
    };
} // namespace

#endif // HPP_PIPE
