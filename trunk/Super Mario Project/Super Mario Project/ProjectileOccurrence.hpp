////////////////////////////////////////////////////////////////////////
// ProjectileOccurrence.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_PROJECTILEOCCURRENCE
#define HPP_PROJECTILEOCCURRENCE

#include "EntityMovable.hpp"
#include "Animation.hpp"

namespace Collisions
{
	class Projectile;
	class ProjectileOccurrence : public EntityMovable
    {

	public:
		enum Sender {
			GENTILE,
			VILAIN
		};

		enum State {
			CHARGING = -1,
			LAUNCHED,
			DEAD
		};
    
		/* Constructors */
		ProjectileOccurrence(
			Projectile* projectile,
			const string& textureName,
			Vector2f& position, 
			Vector2f& speed, 
			State state, 
			Side side,
			map<ProjectileOccurrence::State, int>& nbSpritesByState,
			map<ProjectileOccurrence::State, int>& frameDelayByState);

		/* Getter and setter */
		Sender getSender();
		State getState();
		void setState(State state);
		void setActivity(RenderWindow& app);

		/* Methods */
		void onCollision(Collisionable* c);
		void updatePhysicData(RenderWindow& app);
		void updateGraphicData(RenderWindow& app);
		void render(RenderWindow& app);

        virtual ~ProjectileOccurrence();
		
    private:
		Animation<State> _animation;
		Sender _sender;
		State _state;
		Projectile* _projectile;
		PausableClock _lifeTime;
		PausableClock _appearanceTime;
    };
} // namespace

#endif // HPP_PROJECTILEOCCURRENCE
