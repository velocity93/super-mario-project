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
	ItemOccurrence::ItemOccurrence(const string& textureName) :  
	EntityMovable(textureName), _state(NORMAL), _isActive(true), _blockExitTime(0)
	{
		_item = ResourceManager::getItem(textureName);

		_position = _hitboxPosition = Vector2f(0, 0);
		_hitboxSize.x = _texture->getImage()->GetWidth() / _item->getNbSprites();
		_hitboxSize.y = _texture->getImage()->GetHeight();
	}

	ItemOccurrence::ItemOccurrence(const string& textureName, Vector2f& position, State state)
			: EntityMovable(textureName, position), _state(state), _isActive(true), _blockExitTime(0)
	{
		_item = ResourceManager::getItem(textureName);

		_position = _hitboxPosition = position;
		_hitboxSize.x = _texture->getImage()->GetWidth()/ _item->getNbSprites();
		_hitboxSize.y = _texture->getImage()->GetHeight();
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
		/* Save actual position in previous prosition */
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
