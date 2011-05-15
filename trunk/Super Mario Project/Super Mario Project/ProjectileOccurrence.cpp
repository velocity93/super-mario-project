////////////////////////////////////////////////////////////////////////
// ProjectileOccurrence.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ProjectileOccurrence.hpp"

namespace Collisions
{
	ProjectileOccurrence::Sender ProjectileOccurrence::getSender()
	{
		return _sender;
	}

	void ProjectileOccurrence::setSender(Sender sender)
	{
		_sender = sender;
	}

	void ProjectileOccurrence::update(float time)
	{
		/* Update physic position */
		/* Save actual position in previous prosition */
		this->getPreviousPosition().set(this->getPosition());

		/* Compute new position */
		this->getPosition().set(this->getPosition().getX() + this->getSpeed().getX() * time, this->getPosition().getY() + this->getSpeed().getY() * time);
	}

	void ProjectileOccurrence::render(RenderWindow& app, Screen& screen)
	{

	}

	ProjectileOccurrence::~ProjectileOccurrence()
	{
	}
} // namespace
