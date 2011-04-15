////////////////////////////////////////////////////////////////////////
// Particle.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Particle.hpp"

namespace Collisions
{
	int Particle::getLife()
	{
		return _life;
	}

	void Particle::setLife(int life)
	{
		_life = life;
	}

	void Particle::update(float time)
	{
	}

	void Particle::render()
	{
	}

	Particle::~Particle()
	{
	}
} // namespace
