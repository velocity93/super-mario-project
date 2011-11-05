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

#define MONSTER_EXIT_TIME 4000

namespace Collisions
{
	class Monster;
	class Pipe : public Collisionable
    {

	public:
		typedef enum State
		{
			OPEN,
			CLOSED
		} State;

		typedef enum Direction
		{
			TO_TOP,
			TO_LEFT,
			TO_RIGHT,
			TO_BOTTOM
		}Direction;
    
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
		int getState();
		string& getLevelDestination();
		int getPipeDestination();
		float getMonsterExitDuration();
		void setDirection(Direction Direction);
		void setMonster(Monster* Monster);

		/* Methods */
		void update(RenderWindow& app);
		void render(RenderWindow& app);
		void serialize(ofstream& file, const string& tabs);

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
