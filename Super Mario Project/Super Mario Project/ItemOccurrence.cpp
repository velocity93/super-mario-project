////////////////////////////////////////////////////////////////////////
// ItemOccurrence.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ResourceManager.hpp"
#include "ItemOccurrence.hpp"
#include "Item.hpp"

using namespace SuperMarioProject;

namespace Collisions
{
	ItemOccurrence::ItemOccurrence(
		const string& textureName, 
		Vector2f& position, 
		Vector2f& speed, 
		State state, 
		Side side,
		const map<ItemOccurrence::State, int>& nbSpritesByState,
		const map<ItemOccurrence::State, int>& vAnimByState)
			: EntityMovable(textureName, position, speed, side), _state(state), _isActive(true), _blockExitTime(0)
	{
		_item = ResourceManager::getItem(textureName);

		_position = _hitboxPosition = position;
		//_hitboxSize.x = _texture->getImage()->GetWidth()/ _item->getNbSprites();
		_hitboxSize.y = _texture->getImage()->GetHeight();

		// Initialize animationClass with the two map passing in arguments
		nbSpritesByState;
		vAnimByState;
	}

	ItemOccurrence::State ItemOccurrence::getState()
	{
		return _state;
	}

	bool ItemOccurrence::getIsActive()
	{
		return _isActive;
	}

	void ItemOccurrence::setState(State state)
	{
		_state = state;
	}

	void ItemOccurrence::setIsActive(bool isActive)
	{
		_isActive = isActive;
	}

	void ItemOccurrence::update(RenderWindow& app)
	{
		/* If it falls in hole */
		if(_hitboxPosition.y + _hitboxSize.y < 0)
			_item->removeItemOccurrence(this);

		/* Submissions */
		if(this->_item->getSubmission() & GRAVITY_SUBMISSION)
			gravity(_speed, app.GetFrameTime());

		/* Update physic position */
		/* Save actual position in previous position */
		_previousPosition = _position;

		/* Compute new position */
		this->setPosition(_position.x + _speed.x * app.GetFrameTime(), 
			_position.y + _speed.y * app.GetFrameTime());

	}

	void ItemOccurrence::render(RenderWindow& app)
	{
		Sprite sprite = _texture->getSprite();
		app.Draw(sprite);
	}

	ItemOccurrence::~ItemOccurrence()
	{
	}
} // namespace
