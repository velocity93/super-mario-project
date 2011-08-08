////////////////////////////////////////////////////////////////////////
// Door.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Door.hpp"
#include <fstream>
#include <sstream>

namespace Collisions
{
	Door::Door(const string& textureName) : Collisionable(textureName), _indexDestination(-1), _state(CLOSED), _levelDestination("") 
	{ 
		loadDoor(textureName);
	}

	Door::Door(const string& textureName, Vector2f position, int indexDestination, const string& levelDestination, State state) 
			: Collisionable(textureName, position),
			_indexDestination(indexDestination),
			_levelDestination(levelDestination),
			_state(state)
	{
		loadDoor(textureName);
	}

	int Door::getIndexDestination()
	{
		return _indexDestination;
	}

	string Door::getLevelDestination()
	{
		return _levelDestination;
	}

	Door::State Door::getState()
	{
		return _state;
	}

	void Door::setState(State state)
	{
		_state = state;
	}

	void Door::update(RenderWindow& app)
	{
		_animation.update(_texture, app);
	}

	void Door::render(RenderWindow& app)
	{
		_animation.render(_texture, app, _position);
	}

	void Door::loadDoor(const string& textureName)
	{
		string fileName = textureName + ".obj";
		ifstream stream(fileName.c_str());

		if(stream)
		{
			string word;

			/* We read file to search the keyword and read his value */
			while(getline(stream, word))
			{
				int found = word.find("nb_sprites_open=");
				if(found != string::npos)
				{
					int nb_sprites = 0;
					istringstream nbSprites(word.substr(found + 16));
					nbSprites >> nb_sprites;
					_animation.addNbSpritesForGivenState(State::OPEN, nb_sprites);
					continue;
				}

				found = word.find("v_anim_open=");
				if(found != string::npos)
				{
					int v_anim = 0;
					istringstream vAnim(word.substr(found + 12));
					vAnim >> v_anim;
					_animation.addVAnimForGivenState(State::OPEN, v_anim);
					continue;
				}

				found = word.find("nb_sprites_closed=");
				if(found != string::npos)
				{
					int nb_sprites = 0;
					istringstream nbSprites(word.substr(found + 18));
					nbSprites >> nb_sprites;
					_animation.addNbSpritesForGivenState(State::CLOSED, nb_sprites);
					continue;
				}

				found = word.find("v_anim_closed=");
				if(found != string::npos)
				{
					int v_anim = 0;
					istringstream vAnim(word.substr(found + 14));
					vAnim >> v_anim;
					_animation.addVAnimForGivenState(State::CLOSED, v_anim);
				}
			}
		}
		else
		{
			string exceptionName = "Exception occured while opening " + fileName;
			throw exception(exceptionName.c_str());
		}
	}

	Door::~Door()
	{
	}
} // namespace
