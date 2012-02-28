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
		Monster* monster,
		const string& textureName, 
		Vector2f& position,
		Vector2f& speed,
		MonsterOccurrence::State state,
		MonsterOccurrence::Side side,
		map<MonsterOccurrence::State, int>& nbSpritesByState,
		map<MonsterOccurrence::State, int>& frameDelayByState)
			: EntityMovable(textureName, position, speed, side), _initialPosition(position), _state(state)
	{
		_monster = monster;

		// Animation
		_animation.setMapFrameDelay(frameDelayByState);
		_animation.setMapNbSprites(nbSpritesByState);
		_animation.setCurrentState(state);

		// Hitbox Definition
		_hitboxSize.x = _texture->getImage()->GetWidth() / _animation.getNbSpritesMax() - 2 * _monster->getBottomLeft();
		_hitboxSize.y = _texture->getImage()->GetHeight() / State::M_NB_STATES;
	}

	MonsterOccurrence::State MonsterOccurrence::getState()
	{
		return _state;
	}

	void MonsterOccurrence::setState(State state)
	{
		_state = state;
		_animation.setCurrentState(state);
	}

	Monster* MonsterOccurrence::getModel()
	{
		return _monster;
	}

	void MonsterOccurrence::OnCollision(Collisionable* c, vector<bool>& infos)
	{
		// TO DO
	}

	void MonsterOccurrence::updatePhysicData(RenderWindow& app)
	{
		setActivity(app);

		if(_isActive)
		{
			/* If it falls in hole */
			if(_hitboxPosition.y + _hitboxSize.y < 0)
				_monster->removeMonsterOccurrence(this);

			/* Update physic position */
			/* Save actual position in previous prosition */
			_previousPosition = _position;

			/* Compute new position */
			_position.x = _position.x + _speed.x * app.GetFrameTime(); 
			_position.y = _position.y + _speed.y * app.GetFrameTime();
		}
	}

	void MonsterOccurrence::updateGraphicData(RenderWindow&)
	{
		if(_isActive)
			_animation.update();
	}

	void MonsterOccurrence::render(RenderWindow& app)
	{
		if(_isActive)
		{
			/* Update animation data */
			int delta = 0;
			if(_state != M_WALK)
			{
				delta = !_monster->canBeKilledByJump() + !_monster->canBeKilledByFire();
			}
			_animation.render(_texture, app, _position, _side == LEFT_SIDE, delta);
		}
	}

	void MonsterOccurrence::setActivity(RenderWindow& app)
	{
		const View& view = app.GetDefaultView();

		if(_hitboxPosition.x > view.GetCenter().x + view.GetHalfSize().x
			|| _hitboxPosition.x + _hitboxSize.x < view.GetCenter().x - view.GetHalfSize().x
			|| _hitboxPosition.y > view.GetCenter().y + view.GetHalfSize().y
			|| _hitboxPosition.y + _hitboxSize.y < view.GetCenter().y - view.GetHalfSize().y)
		{
			
			if(this->_initialPosition.x < view.GetCenter().x - view.GetHalfSize().x
			|| this->_initialPosition.x + _hitboxSize.x < view.GetCenter().x + view.GetHalfSize().x
			|| this->_initialPosition.y > view.GetCenter().y + view.GetHalfSize().y
			|| this->_initialPosition.y + _hitboxSize.y < view.GetCenter().y - view.GetHalfSize().y)
			{
				/* If view pass monster's initial position, we put monster as the beginning of the level */
				_position = _previousPosition = _initialPosition;
				setState(M_WALK);
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
