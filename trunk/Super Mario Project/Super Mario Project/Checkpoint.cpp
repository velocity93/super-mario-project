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

namespace Collisions
{
	Checkpoint::Checkpoint(const string& textureName) : Collisionable("textures/objects/" + textureName), _state(NOT_PASSED)
	{
		loadCfgCheckpoint();
		_animation.setCurrentState(NOT_PASSED);
	}

	Checkpoint::Checkpoint(const string& textureName, Vector2f& position, State state) : Collisionable("textures/objects/" + textureName, position), _state(state)
	{
		loadCfgCheckpoint();
		_animation.setCurrentState(NOT_PASSED);
	}

	Checkpoint::State Checkpoint::getState()
	{
		return _state;
	}
	
	void Checkpoint::setState(const State &state)
	{
		_state = state;
	}

    void Checkpoint::updateGraphicData(RenderWindow& app)
    {
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

	void Checkpoint::setActivity(RenderWindow& app)
	{
		// TO DO
	}

	void Checkpoint::render(RenderWindow& app)
    {
		if(_isActive)
			_animation.render(_texture, app, _position, false);
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
				int found = word.find("nb_sprites_active=");
				if(found != string::npos)
                {
					int nbSpritesActive;
					istringstream nbActiveSprites(word.substr(found + 18));
					nbActiveSprites >> nbSpritesActive;
					_animation.addNbSpritesForGivenState(State::PASSED, nbSpritesActive);
					continue;
				}

				/* 'nb_sprites_inactive' keyword */
				found = word.find("nb_sprites_inactive=");
				if(found != string::npos)
                {
					int nbSpritesInactive;
					istringstream nbInactiveSprites(word.substr(found + 20));
					nbInactiveSprites >> nbSpritesInactive;
					_animation.addNbSpritesForGivenState(State::NOT_PASSED, nbSpritesInactive);
					continue;
				}

				/* 'v_anim' keyword */
				found = word.find("v_anim=");
                if(found != string::npos)
                {
					int vAnim;
                    istringstream vAnimStream(word.substr(found + 7));
					vAnimStream >> vAnim;
					_animation.addFrameDelayForGivenState(State::NOT_PASSED, vAnim);
					_animation.addFrameDelayForGivenState(State::PASSED, vAnim);
                }
			}
		}
		else
		{
			string exceptionName = "Exception occured while opening " + fileName;
			throw exception(exceptionName.c_str());
		}
	}


    Checkpoint::~Checkpoint()
    {
    }
} // namespace
