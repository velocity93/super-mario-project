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

	void Particle::update(float time)
	{
		update(time, false);
	}

	void Particle::update(float time, bool hasGravity)
	{
		_life -= time;

		if(hasGravity)
		{
			/* Update physic position */
			/* Save actual position in previous prosition */
			this->getPreviousPosition().set(this->getPosition());

			/* Compute new position */
			this->getPosition().set(this->getPosition().getX() + this->getSpeed().getX() * time, this->getPosition().getY() + this->getSpeed().getY() * time);
		}
	}

	void Particle::render(RenderWindow& app, Screen& screen)
	{
		Sprite sprite(getTexture()->getImage());
		app.Draw(sprite);
	}

	Particle::~Particle()
	{
	}
} // namespace
