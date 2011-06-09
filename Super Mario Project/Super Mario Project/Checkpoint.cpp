////////////////////////////////////////////////////////////////////////
// Checkpoint.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Checkpoint.hpp"
#include <fstream>

namespace Collisions
{
	Checkpoint::Checkpoint(const string& textureName) : Collisionable(textureName), _state(NOT_PASSED)
	{
		loadCfgCheckpoint(textureName);
	}

	Checkpoint::Checkpoint(const string& textureName, Coordf& position, State state) : Collisionable(textureName, position), _state(state)
	{
		loadCfgCheckpoint(textureName);
	}

	Checkpoint::State Checkpoint::getState()
	{
		return _state;
	}
	
	void Checkpoint::setState(const State &state)
	{
		_state = state;
	}

    void Checkpoint::update(RenderWindow& app)
    {

    }

	void Checkpoint::render(RenderWindow& app)
    {
		Sprite sprite = _texture->getSprite();
		int right = _texture->getImage().GetWidth() / max(_spriteNumbersByState[NOT_PASSED], _spriteNumbersByState[PASSED]);

		if(_state == NOT_PASSED)
		{
			sprite.SetSubRect(IntRect(0, 0, right, _texture->getImage().GetHeight() / 2));
		}
		else
		{
			sprite.SetSubRect(IntRect(0, _texture->getImage().GetHeight() / 2, right, _texture->getImage().GetHeight()));
		}

		app.Draw(sprite);
    }

	void Checkpoint::loadCfgCheckpoint(const string& textureName)
	{
		string fileName = textureName + ".obj";
		
		ifstream stream(fileName.c_str());
		
		/* test if the stream is open*/
		if(stream)
		{
			try
			{
				string word;
				int value = 0;

				/* 'nb_sprites_active' keyword */
				stream >> word;
				if(word == "nb_sprites_active=")
				{
					stream >> value;
					_spriteNumbersByState.push_back(value);
					value = 0;
				}
				else
					throw exception(" \"nb_sprites_active=\" keyword is missing", 1);

				/* 'nb_sprites_inactive' keyword */
				stream >> word;
				if(word == "nb_sprites_inactive=")
				{
					stream >> value;
					_spriteNumbersByState.push_back(value);
					value = 0;
				}
				else
					throw exception(" \"nb_sprites_inactive=\" keyword is missing", 1);

				/* 'v_anim' keyword */
				stream >> word;
				if(word == "v_anim=")
				{
					stream >> value;
					_animationSpeeds.push_back(value);
				}
				else
					throw exception("\"v_anim=\" keyword is missing", 1);
			}
			catch(exception& e)
			{
				cout << "Exception occured while reading " << fileName << " : " << e.what() << endl;
				getchar();
				exit(1);
			}
		}
		else
		{
			cout << "Exception occured while opening " << fileName << " : file doesn't exist." << endl;
			getchar();
			exit(1);
		}
	}


    Checkpoint::~Checkpoint()
    {
    }
} // namespace
