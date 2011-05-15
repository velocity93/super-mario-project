////////////////////////////////////////////////////////////////////////
// Particle.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_PARTICLE
#define HPP_PARTICLE

#include "EntityMovable.hpp"

namespace Collisions
{
    class Particle : public EntityMovable
    {
    public:
		Particle(const string& textureName) : EntityMovable(textureName), _life(0) { }
		Particle(const string& textureName, Coord<float> position) : EntityMovable(textureName, position), _life(0) { }

		int getLife();		

		void update(float time);
		void update(float time, bool hasGravity);
		void render(RenderWindow& app, Screen& screen);

        virtual ~Particle();
		
    private:
		int _life;
    };
} // namespace

#endif // HPP_PARTICLE
