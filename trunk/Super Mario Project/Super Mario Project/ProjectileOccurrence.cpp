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
	ProjectileOccurrence::ProjectileOccurrence(const string& textureName, Vector2f& position, State state,
			map<ProjectileOccurrence::State, int> nbSpritesByState,
			map<ProjectileOccurrence::State, int> vAnimByState)
		: EntityMovable(textureName, position), _sender(GENTILE)
	{
		_projectile = ResourceManager::getProjectile(textureName);
		_position = position;
		_hitboxSize.y = _projectile->getTop();
		//_hitboxSize.x = _texture->getImage()->GetWidth() / _projectile->getNbSpritesMax() - 2 * _projectile->getBottomLeft();

		// Initialize animationClass with the two map passing in arguments
		nbSpritesByState;
		vAnimByState;
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
