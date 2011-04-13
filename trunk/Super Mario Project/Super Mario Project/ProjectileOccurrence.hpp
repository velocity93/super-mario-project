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
	enum Projectile_Sender {
		GENTILE,
		VILAIN
	};

	class ProjectileOccurrence : EntityMovable
    {
    public:
		ProjectileOccurrence() : EntityMovable(), sender(GENTILE) { }
		ProjectileOccurrence(Coord<float> Position) : EntityMovable(Position), sender(GENTILE) { }

		Projectile_Sender GetSender()
		{
			return sender;
		}

		void SetSender(Projectile_Sender Sender)
		{
			sender = Sender;
		}

        ~ProjectileOccurrence();
		
    private:
		Projectile_Sender sender;
		//Projectile model;
    };
} // namespace

#endif // HPP_PROJECTILEOCCURRENCE
