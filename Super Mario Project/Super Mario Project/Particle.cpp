////////////////////////////////////////////////////////////////////////
// Particle.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Particle.hpp"
#include <fstream>
#include <sstream>

namespace Collisions
{
	int Particle::getLife()
	{
		return _life;
	}

	void Particle::onCollision(Collisionable*, vector<bool>&)
	{
		// NOTHING TO DO !
	}

	void Particle::updatePhysicData(RenderWindow& app)
	{
		if(_isActive)
			update(app.GetFrameTime(), false);
	}

	void Particle::updateGraphicData(RenderWindow&)
	{
		if(_isActive)
			_animation.update();
	}

	void Particle::update(float time, bool hasGravity)
	{
		_life -= int(time);

		if(hasGravity)
		{
			/* Update physic position */
			/* Save actual position in previous position */
			_previousPosition = _position;

			/* Compute new position */
			_position.x = _position.x + _speed.x * time;
			_position.y = _position.y + _speed.y * time;
		}
	}

	void Particle::render(RenderWindow& app)
	{
		_animation.render(_texture, app, _position, _side == LEFT_SIDE);
	}

	void Particle::loadParticle(const string& textureName)
	{
		string fileName = textureName + ".obj";
		ifstream stream(fileName.c_str());

		if(stream)
		{
			string word;

			/* We read file to search the keyword and read his value */
			while(getline(stream, word))
			{
				unsigned int found = word.find("nb_sprites_normal=");
				if(found != string::npos)
				{
					int nb_sprites = 0;
					istringstream nbSprites(word.substr(found + 18));
					nbSprites >> nb_sprites;
					_animation.addNbSpritesForGivenState(NORMAL, nb_sprites);
					continue;
				}

				found = word.find("v_anim_normal=");
				if(found != string::npos)
				{
					int v_anim = 0;
					istringstream vAnim(word.substr(found + 14));
					vAnim >> v_anim;
					_animation.addFrameDelayForGivenState(NORMAL, v_anim);
				}
			}
		}
		else
		{
			string exceptionName = "Exception occured while opening " + fileName;
			throw exception(exceptionName.c_str());
		}
	}

	Particle::~Particle()
	{
	}
} // namespace
