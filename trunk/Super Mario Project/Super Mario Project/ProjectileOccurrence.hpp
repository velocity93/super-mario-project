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
	enum Sender {
		GENTILE,
		VILAIN
	};

    public:
		/* Constructors */
		ProjectileOccurrence() : EntityMovable(), _sender(GENTILE) { }
		ProjectileOccurrence(Coord<float> position) : EntityMovable(position), _sender(GENTILE) { }

		/* Getter and setter */
		Sender getSender();
		void setSender(Sender sender);

		/* Methods */
		void update(float time);
		void render();

        ~ProjectileOccurrence();
		
    private:
		Sender _sender;
		Projectile* model;
    };
} // namespace

#endif // HPP_PROJECTILEOCCURRENCE
