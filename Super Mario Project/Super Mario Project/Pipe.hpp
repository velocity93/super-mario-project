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
		} Direction;
    
		/* Constructors */
		Pipe(const std::string& textureName);
		Pipe(const std::string& textureName, Vector2f& position,
			int indexPipeDestination, 
			const std::string& levelDestination, 
			State state, 
			int lenght, 
			Direction direction, 
			Monster* monster);

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
		void updateGraphicData(RenderWindow& app);
		void updatePhysicData(float time, RenderWindow& app);
		void render(RenderWindow& app);
		void serialize(ofstream& file, const string& tabs);

		/* Destructor */
        virtual ~Pipe();

		static const int MONSTER_EXIT_TIME = 4000;
		
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
