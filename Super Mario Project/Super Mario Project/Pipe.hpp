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

namespace smp
{
	// forward declaration
	class Monster;
	
	class Pipe : public Collisionable
    {

	public:
		typedef enum State
		{
			CLOSED,
			OPEN
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
		Pipe(const std::string& textureName, sf::Vector2f& position,
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
		std::string& getLevelDestination();
		int getPipeDestination();
		float getMonsterExitDuration();
		void setDirection(Direction Direction);
		void setMonster(Monster* Monster);

		/* Methods */
		void updateGraphicData(sf::RenderWindow& app);
		void updatePhysicData(float time, sf::RenderWindow& app);
		void render(sf::RenderWindow& app);
		void serialize(std::ofstream& file, const std::string& tabs);

		/* Destructor */
        virtual ~Pipe();

		static const int MONSTER_EXIT_TIME = 4000;
		
    private:
		int _indexDestination;
		std::string _levelDestination;
		State _state;
		Direction _direction;
		Monster* _monster;
		int _lenght;
		sf::Clock _monsterExitDuration;
    };
} // namespace

#endif // HPP_PIPE
