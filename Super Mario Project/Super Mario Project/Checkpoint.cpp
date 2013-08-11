////////////////////////////////////////////////////////////////////////
// Checkpoint.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Checkpoint.hpp"
#include "XMLCheckpointParser.hpp"
#include <fstream>
#include <sstream>

using namespace std;
using namespace sf;

namespace smp
{
	Checkpoint::Checkpoint(const string& textureName) : 
		Collisionable("textures/objects/" + textureName), 
			_state(NOT_PASSED),
			_animation(NB_STATES)
	{
		loadCfgCheckpoint();
		_animation.setCurrentState(NOT_PASSED);

		/* Hitbox */
		_hitboxPosition.x = 0;
		_hitboxPosition.y = 0;
		_hitboxSize.x = _texture->getSize().x / _animation.getNbSpritesMax();
		_hitboxSize.y = _texture->getSize().y / NB_STATES;
	}

	Checkpoint::Checkpoint(const string& textureName, Vector2f& position, State state) : Collisionable("textures/objects/" + textureName, position),
		_state(state),
		_animation(NB_STATES)
	{
		loadCfgCheckpoint();
		_animation.setCurrentState(NOT_PASSED);

		/* Hitbox */
		_hitboxSize.x = _texture->getSize().x / _animation.getNbSpritesMax();
		_hitboxSize.y = _texture->getSize().y / NB_STATES;
		_hitboxPosition = Vector2f(position.x, position.y);
	}

	Checkpoint::State Checkpoint::getState()
	{
		return _state;
	}
	
	void Checkpoint::setState(const State &state)
	{
		_state = state;
		_animation.setCurrentState(state);
	}

	Animation<Checkpoint::State>& Checkpoint::getAnimation()
	{
		return _animation;
	}

    void Checkpoint::updateGraphicData(RenderWindow& app)
    {
		setActivity(app);

		if(_isActive)
			_animation.update();
    }

	void Checkpoint::serialize(ofstream& file, const string& tabs)
	{
		file << tabs << "<checkpoint ";
		file << "img=\"" << _texture->shorterName() << "\" ";
		file << "positionX=\"" << _position.x << "\" ";
		file << "positionY=\"" << _position.y << "\" ";
		file << "/>" << endl;
	}

	void Checkpoint::render(RenderWindow& app)
    {
		if(_isActive)
			_animation.render(_texture, app, _hitboxPosition, false);
    }

	void Checkpoint::loadCfgCheckpoint()
	{
		XMLCheckpointParser::getParser()->loadCheckpoint(_texture->name() + ".xml", this);
	}


    Checkpoint::~Checkpoint()
    {
    }
} // namespace
