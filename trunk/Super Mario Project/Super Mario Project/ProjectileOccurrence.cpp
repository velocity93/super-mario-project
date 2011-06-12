////////////////////////////////////////////////////////////////////////
// ProjectileOccurrence.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ProjectileOccurrence.hpp"
#include "Projectile.hpp"

namespace Collisions
{
	ProjectileOccurrence::ProjectileOccurrence(const string& textureName, Projectile* projectile) : EntityMovable(textureName), _sender(GENTILE)
	{
		_projectile = projectile;
		_hitboxPosition.x = 0;
		_hitboxPosition.y = 0;
		/* Compute HitboxSize */
	}

	ProjectileOccurrence::ProjectileOccurrence(const string& textureName, Projectile* projectile, Vector2f& position) : EntityMovable(textureName, position), _sender(GENTILE)
	{
		_projectile = projectile;
		_hitboxPosition = position;
		/* Compute HitboxSize */
	}

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
		/* If it falls in hole */
		if(_hitboxPosition.y + _hitboxSize.y < 0)
			_projectile->removeProjectileOccurrence(this);

		/* Submissions */
		if(_projectile->getSubmission() & GRAVITY_SUBMISSION)
			gravity(_speed, app.GetFrameTime());

		/* Update physic position */
		/* Save actual position in previous prosition */
		_previousPosition = _position;

		/* Compute new position */
		this->setPosition(_position.x + _speed.x * app.GetFrameTime(), 
			_position.y + _speed.x * app.GetFrameTime());
	}

	void ProjectileOccurrence::render(RenderWindow& app)
	{

	}

	ProjectileOccurrence::~ProjectileOccurrence()
	{
	}
} // namespace
