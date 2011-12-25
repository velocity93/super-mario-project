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
	}

	Checkpoint::Checkpoint(const string& textureName, Vector2f& position, State state) : Collisionable("textures/objects/" + textureName, position), _state(state)
	{
		loadCfgCheckpoint();
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

	}

	void Checkpoint::render(RenderWindow& app)
    {
        ReversedSprite sprite = _texture->getSprite();
		/*int right = _texture->getImage()->GetWidth() / max(_spriteNumbersByState[NOT_PASSED], _spriteNumbersByState[PASSED]);

		if(_state == NOT_PASSED)
		{
			sprite.SetSubRect(IntRect(0, 0, right, _texture->getImage()->GetHeight() / 2));
		}
		else
		{
			sprite.SetSubRect(IntRect(0, _texture->getImage()->GetHeight() / 2, right, _texture->getImage()->GetHeight()));
		}*/

		app.Draw(sprite);
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
					istringstream nbActiveSprites(word.substr(found + 18));
					//nbActiveSprites >> ??;
					continue;
				}

				/* 'nb_sprites_inactive' keyword */
				found = word.find("nb_sprites_inactive=");
				if(found != string::npos)
                {
					istringstream nbInactiveSprites(word.substr(found + 20));
					//nbInactiveSprites >> ??;
					continue;
				}

				/* 'v_anim' keyword */
				found = word.find("v_anim=");
                if(found != string::npos)
                {
                    istringstream vAnim(word.substr(found + 7));
                    // vAnim >> ??;
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
