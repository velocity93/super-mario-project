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
			CHARGING,
			LAUNCHED,
			DEAD
		};
    
		/* Constructors */
		ProjectileOccurrence(const string& textureName, Vector2f& position, State state,
			map<ProjectileOccurrence::State, int> nbSpritesByState,
			map<ProjectileOccurrence::State, int> vAnimByState);

		/* Getter and setter */
		Sender getSender();

		/* Methods */
		void update(RenderWindow& app);
		void render(RenderWindow& app);

        virtual ~ProjectileOccurrence();
		
    private:
		Sender _sender;
		Projectile* _projectile;
    };
} // namespace

#endif // HPP_PROJECTILEOCCURRENCE
