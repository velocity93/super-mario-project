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
#include "Projectile.hpp"

namespace Collisions
{
	
	class ProjectileOccurrence : public EntityMovable
    {

	public:
		enum Sender {
		GENTILE,
		VILAIN
		};

    
		/* Constructors */
		ProjectileOccurrence(string textureName) : EntityMovable(textureName), _sender(GENTILE) { }
		ProjectileOccurrence(string textureName, Coord<float> position) : EntityMovable(textureName, position), _sender(GENTILE) { }

		/* Getter and setter */
		Sender getSender();
		void setSender(Sender sender);

		/* Methods */
		void update(float time);
		void render(RenderWindow& app);

        virtual ~ProjectileOccurrence();
		
    private:
		Sender _sender;
		Projectile* model;
    };
} // namespace

#endif // HPP_PROJECTILEOCCURRENCE
