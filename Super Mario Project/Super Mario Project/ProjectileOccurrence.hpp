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

namespace smp
{
	// forward declaration
	class Projectile;
	class BlockOccurrence;

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
			DEAD,
			NB_STATES
		};
    
		/* Constructors */
		ProjectileOccurrence(
			Projectile* projectile,
			const std::string& textureName,
			const sf::Vector2f& position, 
			const sf::Vector2f& speed, 
			State state, 
			Side side,
			std::map<ProjectileOccurrence::State, int>& nbSpritesByState,
			std::map<ProjectileOccurrence::State, int>& frameDelayByState);

		/* Getter and setter */
		Sender getSender();
		State getState();
		void setState(State state);		

		/* Methods */
		void onCollision(Collisionable* c, int collision_type);
		void onCollision(BlockOccurrence* block, int collision_type);
		void updatePhysicData(float time, sf::RenderWindow& app);
		void updateGraphicData(sf::RenderWindow& app);
		void render(sf::RenderWindow& app);

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
