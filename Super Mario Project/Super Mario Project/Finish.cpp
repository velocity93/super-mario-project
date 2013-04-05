////////////////////////////////////////////////////////////////////////
// Finish.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Finish.hpp"
#include "Exceptions.hpp"
#include <fstream>
#include <sstream>

using namespace std;
using sf::Vector2f;
using sf::RenderWindow;

namespace smp
{
	Finish::Finish(const string& textureName, Vector2f& position) : Collisionable("textures/objects/" + textureName, position),
		_animation(NB_STATES)
	{
		loadFinish(textureName);
		_animation.setCurrentState(WAITING);

		/* Hitbox */
		_hitboxSize.x = _texture->getSize().x;
		_hitboxSize.y = _texture->getSize().y;

		_position = Vector2f(position.x, position.y - _hitboxSize.y);
		_hitboxPosition = _position;
	}

	void Finish::setState(const State& state)
	{
		_animation.setCurrentState(state);
	}

	void Finish::updateGraphicData(RenderWindow& app)
    {
		setActivity(app);

		if(_isActive)
			_animation.update();
    }

	void Finish::render(RenderWindow& app)
    {
		if(_isActive)
			_animation.render(_texture, app, _hitboxPosition, false);
    }

	void Finish::serialize(ofstream& file, const string& tabs)
	{
		file << tabs << "<finish ";
		file << "img=\"" << _texture->shorterName() << "\" ";
		file << "positionX=\"" << _position.x << "\" ";
		file << "positionY=\"" << _position.y << "\"/>" << endl;
	}

	void Finish::loadFinish(const string& textureName)
	{
		string fileName = "textures/objects/" + textureName + ".obj";
		ifstream stream(fileName.c_str());

		if(stream)
		{
			string word;

			/* We read file to search the keyword and read his value */
			while(getline(stream, word))
			{
				unsigned int found = word.find("nb_sprites_waiting=");
				if(found != string::npos)
				{
					int nb_sprites = 0;
					istringstream nbSprites(word.substr(found + 19));
					nbSprites >> nb_sprites;
					_animation.addNbSpritesForGivenState(WAITING, nb_sprites);
					continue;
				}

				found = word.find("v_anim_waiting=");
				if(found != string::npos)
				{
					int v_anim = 0;
					istringstream vAnim(word.substr(found + 15));
					vAnim >> v_anim;
					_animation.addFrameDelayForGivenState(WAITING, v_anim);
					continue;
				}

				found = word.find("nb_sprites_finish=");
				if(found != string::npos)
				{
					int nb_sprites = 0;
					istringstream nbSprites(word.substr(found + 18));
					nbSprites >> nb_sprites;
					_animation.addNbSpritesForGivenState(FINISH, nb_sprites);
					continue;
				}

				found = word.find("v_anim_finish=");
				if(found != string::npos)
				{
					int v_anim = 0;
					istringstream vAnim(word.substr(found + 14));
					vAnim >> v_anim;
					_animation.addFrameDelayForGivenState(FINISH, v_anim);
				}
			}
		}
		else
		{
			throw FileNotFoundException(fileName);
		}
	}

    Finish::~Finish()
    {
		//_texture->release();
    }
} // namespace
