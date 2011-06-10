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
			/* Save actual position in previous position */
			_previousPosition = _position;

			/* Compute new position */
			_position = _position.x + _speed.x * time, _position.y + _speed.y * time;
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
