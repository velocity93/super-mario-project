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

	void ProjectileOccurrence::update(RenderWindow& app)
	{
		/* Update physic position */
		/* Save actual position in previous prosition */
		this->setPreviousPosition(this->getPosition());

		/* Compute new position */
		this->setPosition(this->getPosition().getX() + this->getSpeed().x * app.GetFrameTime(), this->getPosition().getY() + this->getSpeed().x * app.GetFrameTime());
	}

	void ProjectileOccurrence::render(RenderWindow& app)
	{

	}

	ProjectileOccurrence::~ProjectileOccurrence()
	{
	}
} // namespace
