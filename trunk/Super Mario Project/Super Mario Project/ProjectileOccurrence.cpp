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
	ProjectileOccurrence::ProjectileOccurrence(
		const string& textureName, 
		Vector2f& position, 
		Vector2f& speed, 
		State state,
		Side side,
		map<ProjectileOccurrence::State, int>& nbSpritesByState,
		map<ProjectileOccurrence::State, int>& frameDelayByState) :
		EntityMovable(textureName, position, speed, side), 
			_sender(GENTILE),
			_state(state)
	{
		_projectile = ResourceManager::getProjectile(textureName);

		/* Initialize animation class */
		_animation.setMapNbSprites(nbSpritesByState);
		_animation.setMapFrameDelay(frameDelayByState);
		_animation.setCurrentState(state);

		/* Hitbox */
		_position = position;
		_hitboxSize.y = _projectile->getTop();
		_hitboxSize.x = _texture->getImage()->GetWidth() / _animation.getNbSpritesMax() - 2 * _projectile->getBottomLeft();
	}

	ProjectileOccurrence::State ProjectileOccurrence::getState()
	{
		return _state;
	}

	ProjectileOccurrence::Sender ProjectileOccurrence::getSender()
	{
		return _sender;
	}

	void ProjectileOccurrence::setState(State state)
	{
		_state = state;
		_animation.setCurrentState(state);
	}

	void ProjectileOccurrence::setActivity(RenderWindow& app)
	{

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
		this->setPositionX(_position.x + _speed.x * app.GetFrameTime());
		this->setPositionY(_position.y + _speed.x * app.GetFrameTime());
	}

	void ProjectileOccurrence::render(RenderWindow& app)
	{
		_animation.render(_texture, app, _position, _side == Side::LEFT_SIDE);
	}

	ProjectileOccurrence::~ProjectileOccurrence()
	{
	}
} // namespace
