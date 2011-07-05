////////////////////////////////////////////////////////////////////////
// MonsterOccurrence.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ResourceManager.hpp"
#include "MonsterOccurrence.hpp"
#include "Monster.hpp"

using namespace SuperMarioProject;

namespace Collisions
{
	MonsterOccurrence::MonsterOccurrence(
		const string& textureName, 
		Vector2f& position,
		Vector2f& speed,
		MonsterOccurrence::State state,
		MonsterOccurrence::Side side,
		map<MonsterOccurrence::State, int> nbSpritesByState,
		map<MonsterOccurrence::State, int> vAnimByState)
			: EntityMovable(textureName, position, speed, side), _initialPosition(position), _state(state), _isActive(true)
	{
		_monster = ResourceManager::getMonster(textureName);

		// Use AnimationClass with maps passed in arguments
		nbSpritesByState;
		vAnimByState;

		// Define hitbox size here
	}

	MonsterOccurrence::State MonsterOccurrence::getState()
	{
		return _state;
	}

	void MonsterOccurrence::setState(State state)
	{
		_state = state;
	}


	void MonsterOccurrence::update(RenderWindow& app)
	{
		updateMonsterActivity(app);

		/* If it falls in hole */
		if(_hitboxPosition.y + _hitboxSize.y < 0)
			_monster->removeMonsterOccurrence(this);

		/* Update physic position */
		/* Save actual position in previous prosition */
		_previousPosition = _position;

		/* Compute new position */
		this->setPosition(_position.x + _speed.x * app.GetFrameTime(), 
			_position.y + _speed.y * app.GetFrameTime());
	}

	void MonsterOccurrence::render(RenderWindow& app)
	{

	}

	void MonsterOccurrence::updateMonsterActivity(RenderWindow& app)
	{
		const View& view = app.GetDefaultView();

		if(_hitboxPosition.x < view.GetCenter().x - view.GetHalfSize().x
			|| _hitboxPosition.x + _hitboxSize.x < view.GetCenter().x + view.GetHalfSize().x
			|| _hitboxPosition.y > view.GetCenter().y + view.GetHalfSize().y
			|| _hitboxPosition.y + _hitboxSize.y < view.GetCenter().y - view.GetHalfSize().y)
		{
			
			if(this->_initialPosition.x < view.GetCenter().x - view.GetHalfSize().x
			|| this->_initialPosition.x + _hitboxSize.x < view.GetCenter().x + view.GetHalfSize().x
			|| this->_initialPosition.y > view.GetCenter().y + view.GetHalfSize().y
			|| this->_initialPosition.y + _hitboxSize.y < view.GetCenter().y - view.GetHalfSize().y)
			{
				/* If view pass monster's initial position, we put monster as the beginning of the level */
				_position = _initialPosition;
				_previousPosition = _initialPosition;
				_state = M_WALK;
				_speed.x = -M_SPEED_WALK_MIN;
				_side = LEFT_SIDE;
			}

			_isActive = false;
		}
		else
			_isActive = true;

	}

    MonsterOccurrence::~MonsterOccurrence()
    {		
    }
} // namespace
