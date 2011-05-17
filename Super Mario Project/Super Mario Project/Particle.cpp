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

	void Particle::update(RenderWindow& app)
	{
		update(app.GetFrameTime(), false);
	}

	void Particle::update(float time, bool hasGravity)
	{
		_life -= time;

		if(hasGravity)
		{
			/* Update physic position */
			/* Save actual position in previous prosition */
			this->setPreviousPosition(this->getPosition());

			/* Compute new position */
			this->setPosition(this->getPosition().getX() + this->getSpeed().x * time, this->getPosition().getY() + this->getSpeed().y * time);
		}
	}

	void Particle::render(RenderWindow& app)
	{
		app.Draw(this->getTexture()->getSprite());
	}

	Particle::~Particle()
	{
	}
} // namespace
