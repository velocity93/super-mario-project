////////////////////////////////////////////////////////////////////////
// Door.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Door.hpp"
#include "Exceptions.hpp"
#include <fstream>
#include <sstream>

using namespace std;
using sf::Vector2f;
using sf::RenderWindow;

namespace smp
{
	Door::Door(const string& textureName) : Collisionable(textureName), _indexDestination(-1), _state(CLOSED), _levelDestination(""), _animation(NB_STATES)
	{ 
		loadDoor(textureName);
	}

	Door::Door(const string& textureName, Vector2f position, int indexDestination, const string& levelDestination, State state) 
			: Collisionable(textureName, position),
			_indexDestination(indexDestination),
			_levelDestination(levelDestination),
			_state(state),
			_animation(NB_STATES)
	{
		loadDoor(textureName);
		_animation.setCurrentState(state);
	}

	int Door::getIndexDestination()
	{
		return _indexDestination;
	}

	string& Door::getLevelDestination()
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

	void Door::updateGraphicData(RenderWindow& app)
	{
		setActivity(app);

		if(_isActive)
			_animation.update();
	}

	void Door::render(RenderWindow& app)
	{
		if(_isActive)
			_animation.render(_texture, app, _position, false);
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
				unsigned int found = word.find("nb_sprites_open=");
				if(found != string::npos)
				{
					int nb_sprites = 0;
					istringstream nbSprites(word.substr(found + 16));
					nbSprites >> nb_sprites;
					_animation.addNbSpritesForGivenState(OPEN, nb_sprites);
					continue;
				}

				found = word.find("v_anim_open=");
				if(found != string::npos)
				{
					int v_anim = 0;
					istringstream vAnim(word.substr(found + 12));
					vAnim >> v_anim;
					_animation.addFrameDelayForGivenState(OPEN, v_anim);
					continue;
				}

				found = word.find("nb_sprites_closed=");
				if(found != string::npos)
				{
					int nb_sprites = 0;
					istringstream nbSprites(word.substr(found + 18));
					nbSprites >> nb_sprites;
					_animation.addNbSpritesForGivenState(CLOSED, nb_sprites);
					continue;
				}

				found = word.find("v_anim_closed=");
				if(found != string::npos)
				{
					int v_anim = 0;
					istringstream vAnim(word.substr(found + 14));
					vAnim >> v_anim;
					_animation.addFrameDelayForGivenState(CLOSED, v_anim);
				}
			}
		}
		else
		{
			throw FileNotFoundException(fileName);
		}
	}

	Door::~Door()
	{
	}
} // namespace
