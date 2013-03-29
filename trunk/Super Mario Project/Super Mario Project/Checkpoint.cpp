////////////////////////////////////////////////////////////////////////
// Checkpoint.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Checkpoint.hpp"
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
		_hitboxPosition = Vector2f(position.x, position.y - _hitboxSize.y);
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
		string fileName = _texture->name() + ".obj";		
		ifstream stream(fileName.c_str());
		
		/* test if the stream is open*/
		if(stream)
		{
			string word;

			/* We read file to search keywords and read his value */
			while(getline(stream, word))
			{
				unsigned int found = word.find("nb_sprites_active=");
				if(found != string::npos)
                {
					int nbSpritesActive;
					istringstream nbActiveSprites(word.substr(found + 18));
					nbActiveSprites >> nbSpritesActive;
					_animation.addNbSpritesForGivenState(PASSED, nbSpritesActive);
					continue;
				}

				/* 'nb_sprites_inactive' keyword */
				found = word.find("nb_sprites_inactive=");
				if(found != string::npos)
                {
					int nbSpritesInactive;
					istringstream nbInactiveSprites(word.substr(found + 20));
					nbInactiveSprites >> nbSpritesInactive;
					_animation.addNbSpritesForGivenState(NOT_PASSED, nbSpritesInactive);
					continue;
				}

				/* 'v_anim_active' keyword */
				found = word.find("v_anim_active=");
                if(found != string::npos)
                {
					int vAnim;
                    istringstream vAnimStream(word.substr(found + 14));
					vAnimStream >> vAnim;
					_animation.addFrameDelayForGivenState(PASSED, vAnim);
                }

				/* 'v_anim_inactive' keyword */
				found = word.find("v_anim_inactive=");
                if(found != string::npos)
                {
					int vAnim;
                    istringstream vAnimStream(word.substr(found + 16));
					vAnimStream >> vAnim;
					_animation.addFrameDelayForGivenState(NOT_PASSED, vAnim);
                }
			}
		}
		else
		{
			throw "Exception occured while opening " + fileName;
		}
	}


    Checkpoint::~Checkpoint()
    {
    }
} // namespace
