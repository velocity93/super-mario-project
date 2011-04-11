////////////////////////////////////////////////////////////////////////
// Projectile.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_PROJECTILE
#define HPP_PROJECTILE

namespace Collisions
{
	enum Projectile_Sender {
		LEVEL,
		GENTILE,
		VILAIN
	};

	enum Projectile_Type {
		FRAGMENT,
		FIREBALL,
		SPECIAL_FIREBALL,
		ICEBALL,
		THUNDER_BALL,
		SUPER_FIREBALL,
		HYPER_FIREBALL,
		SHURIKEN
	};

    class Projectile
    {
    public:
        Projectile();
        ~Projectile();
		
    private:
    };
} // namespace

#endif // HPP_PROJECTILE
