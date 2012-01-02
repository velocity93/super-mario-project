////////////////////////////////////////////////////////////////////////
// Door.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_DOOR
#define HPP_DOOR

#include "Collisionable.hpp"
#include "Animation.hpp"

namespace Collisions
{
	class Door : public Collisionable
    {
		
    public:
		typedef enum 
		{
			OPEN,
			CLOSED
		} State;


		/* Constructors */
		Door(const string& textureName);
		Door(const string& textureName, Vector2f position, int indexDestination, const string& levelDestination, State state);
		/* getters and setters */
		int getIndexDestination();
		string& getLevelDestination();
		State getState();
		void setIndexDestination(int indexDestination);
		void setLevelDestination(const string& levelDestination);
		void setState(State state);
		void setActivity(RenderWindow& app);

		/* Methods */
		void updateGraphicData(RenderWindow& app);
		void render(RenderWindow& app);

        virtual ~Door();
		
    private:
		Animation<State> _animation;
		int _indexDestination;
		string _levelDestination;
		State _state;

		void loadDoor(const string& textureName);
    };
} // namespace

#endif // HPP_DOOR
