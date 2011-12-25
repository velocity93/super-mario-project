////////////////////////////////////////////////////////////////////////
// Finish.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Finish.hpp"
#include <fstream>
#include <sstream>

namespace Collisions
{
	Finish::Finish(const string& textureName) : Collisionable(textureName) 
	{
		loadFinish(textureName);
	}
	
	Finish::Finish(const string& textureName,Vector2f& position) : Collisionable(textureName, position) 
	{
		loadFinish(textureName);
	}

	void Finish::update(RenderWindow&)
    {
		_animation.update();
    }

	void Finish::render(RenderWindow& app)
    {
		_animation.render(_texture, app, _position, false);
    }

	void Finish::serialize(ofstream& file, const string& tabs)
	{
		file << tabs << "<finish ";
		file << "img=\"" << _texture->shorterName() << "\" ";
		file << "positionX=\"" << _position.x << "\" ";
		file << "positionY=\"" << _position.y << "\"/>" << endl;
	}

	void Finish::setActivity(RenderWindow& app)
	{

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
				int found = word.find("nb_sprites_waiting=");
				if(found != string::npos)
				{
					int nb_sprites = 0;
					istringstream nbSprites(word.substr(found + 19));
					nbSprites >> nb_sprites;
					_animation.addNbSpritesForGivenState(State::WAITING, nb_sprites);
					continue;
				}

				found = word.find("v_anim_waiting=");
				if(found != string::npos)
				{
					int v_anim = 0;
					istringstream vAnim(word.substr(found + 15));
					vAnim >> v_anim;
					_animation.addFrameDelayForGivenState(State::WAITING, v_anim);
					continue;
				}

				found = word.find("nb_sprites_finish=");
				if(found != string::npos)
				{
					int nb_sprites = 0;
					istringstream nbSprites(word.substr(found + 18));
					nbSprites >> nb_sprites;
					_animation.addNbSpritesForGivenState(State::FINISH, nb_sprites);
					continue;
				}

				found = word.find("v_anim_finish=");
				if(found != string::npos)
				{
					int v_anim = 0;
					istringstream vAnim(word.substr(found + 14));
					vAnim >> v_anim;
					_animation.addFrameDelayForGivenState(State::FINISH, v_anim);
				}
			}
		}
		else
		{
			string exceptionName = "Exception occured while opening " + fileName;
			throw exception(exceptionName.c_str());
		}
	}

    Finish::~Finish()
    {
    }
} // namespace
