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

    
		/* Constructors */
		ProjectileOccurrence(const string& textureName) : EntityMovable(textureName), _sender(GENTILE) { }
		ProjectileOccurrence(const string& textureName,Vector2f& position) : EntityMovable(textureName, position), _sender(GENTILE) { }

		/* Getter and setter */
		Sender getSender();
		void setSender(Sender sender);

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
