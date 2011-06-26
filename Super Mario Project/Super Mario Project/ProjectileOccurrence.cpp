////////////////////////////////////////////////////////////////////////
// ProjectileOccurrence.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ResourceManager.hpp"
#include "ProjectileOccurrence.hpp"
#include "Projectile.hpp"

using namespace SuperMarioProject;

namespace Collisions
{
	ProjectileOccurrence::ProjectileOccurrence(const string& textureName)
		: EntityMovable(textureName), _sender(GENTILE)
	{
		_projectile = ResourceManager::getProjectile(textureName);
		_position.x = 0;
		_position.y = 0;
		/* Compute Hitbox */
	}

	ProjectileOccurrence::ProjectileOccurrence(const string& textureName, Vector2f& position)
		: EntityMovable(textureName, position), _sender(GENTILE)
	{
		_projectile = ResourceManager::getProjectile(textureName);
		_position = position;
		/* Compute Hitbox */
	}

	ProjectileOccurrence::Sender ProjectileOccurrence::getSender()
	{
		return _sender;
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
