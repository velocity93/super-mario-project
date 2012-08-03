////////////////////////////////////////////////////////////////////////
// Projectile.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Projectile.hpp"
#include <sstream>

namespace Collisions
{
    Projectile::Projectile(const string& textureName, Type type)
        : Resource("textures/projectiles/" + textureName),
        _type(type), _initialSpeed(Vector2f())
    {
        loadProjectile();
    }

    int Projectile::getSubmission()
    {
        return _submission;
    }

	int Projectile::getBottomLeft()
	{
		return _bottomLeft;
	}

	int Projectile::getTop()
	{
		return _top;
	}

	vector<ProjectileOccurrence*>& Projectile::getProjectileOccurrences()
	{
		return _projectileOccurences;
	}

	void Projectile::addNewProjectileOccurrence(const Vector2f& position, ProjectileOccurrence::State state, ProjectileOccurrence::Side side)
    {
		_projectileOccurences.push_back(new ProjectileOccurrence(this, name(), position, _initialSpeed, state, side, _nbSpritesByState, _frameDelayByState));
    }

    void Projectile::removeProjectileOccurrence(const ProjectileOccurrence* projectile)
    {
        vector<ProjectileOccurrence*>::iterator itProjectileOccurrence;

		for(itProjectileOccurrence = _projectileOccurences.begin(); itProjectileOccurrence != _projectileOccurences.end(); ++itProjectileOccurrence)
        {
            if((*itProjectileOccurrence) == projectile)
			{
                _projectileOccurences.erase(itProjectileOccurrence);
				break;
			}
        }
    }

    void Projectile::updatePhysicData(float time, RenderWindow& app)
    {
        unsigned int initSize = _projectileOccurences.size();

		for(unsigned int i = 0; i < initSize; ++i)
        {
            _projectileOccurences[i]->updatePhysicData(time, app);
        }
    }

	void Projectile::updateGraphicData(RenderWindow& app)
    {
        for(vector<ProjectileOccurrence*>::iterator itProjectiles = _projectileOccurences.begin(); itProjectiles != _projectileOccurences.end(); ++itProjectiles)
        {
			(*itProjectiles)->updateGraphicData(app);
        }
    }

    void Projectile::render(RenderWindow& app)
    {
		
        vector<ProjectileOccurrence*>::iterator itProjectiles;

        /* ProjectilesOccurrences */
        for(itProjectiles = this->_projectileOccurences.begin(); itProjectiles != this->_projectileOccurences.end(); ++itProjectiles)
        {
            (*itProjectiles)->render(app);
        }
    }

	void Projectile::serialize(ofstream& file, const string& tabs)
	{
		file << tabs << "<projectile ";
		file << "img=\"" << shorterName() << "\" />" << endl;
	}

	void Projectile::loadProjectile()
    {
        string fileName = name() + ".proj";
        ifstream stream(fileName.c_str());
		
		if(stream)
		{
			string word;

            /* We read file to search keywords and read his value */
            while(getline(stream, word))
            {
                unsigned int found = word.find("speed_x=");
                if(found != string::npos)
                {
                    istringstream InitialSpeedX(word.substr(found + 8));
                    InitialSpeedX >> _initialSpeed.x;
                }

                found = word.find("abscisse_bas=");
                if(found != string::npos)
                {
                    istringstream abscisseBas(word.substr(found + 13));
                    abscisseBas >> _bottomLeft;
                    continue;
                }

                found = word.find("ordonnee_haut=");
                if(found != string::npos)
                {
                    istringstream ordonneeHaut(word.substr(found + 14));
					ordonneeHaut >> _top;
                    continue;
                }

                found = word.find("submission=");
                if(found != string::npos)
                {
                    /* Read hexadecimal value */
                    istringstream submission(word.substr(found + 11));
                    submission >> hex >> _submission;
                    continue;
                }

                /* Manage sprites numbers here */
                found = word.find("nb_sprites_run=");
                if(found != string::npos)
                {
					int _nbWalkingSprites;
                    istringstream nbWalkingSprites(word.substr(found + 15));
					nbWalkingSprites >> _nbWalkingSprites;
					_nbSpritesByState.insert(pair<ProjectileOccurrence::State, int>(ProjectileOccurrence::LAUNCHED, _nbWalkingSprites));
                    continue;
                }

                /* Manage sprites numbers here */
                found = word.find("nb_sprites_dead=");
                if(found != string::npos)
                {
					int _nbDeadSprites;
                    istringstream nbDeadSprites(word.substr(found + 16));
					nbDeadSprites >> _nbDeadSprites;
					_nbSpritesByState.insert(pair<ProjectileOccurrence::State, int>(ProjectileOccurrence::DEAD, _nbDeadSprites));
                    continue;
                }

                /* Manage speed of animation numbers here */
                found = word.find("v_anim_run=");
                if(found != string::npos)
                {
					int _vWalkingAnim;
                    istringstream vWalkingAnim(word.substr(found + 11));
					vWalkingAnim >> _vWalkingAnim;
					_frameDelayByState.insert(pair<ProjectileOccurrence::State, int>(ProjectileOccurrence::LAUNCHED, _vWalkingAnim));
                    continue;
                }

                /* Manage speed of animation numbers here */
                found = word.find("v_anim_dead=");
                if(found != string::npos)
                {
					int _vDeadAnim;
					istringstream vDeadAnim(word.substr(found + 12));
                    vDeadAnim >> _vDeadAnim;
					_frameDelayByState.insert(pair<ProjectileOccurrence::State, int>(ProjectileOccurrence::DEAD, _vDeadAnim));
                }

                /* Add apparition_time and disappearing_time later */
            }
        }
        else
        {
            string exceptionName = "Exception occured while opening " + fileName;
            throw exception(exceptionName.c_str());
        }
    }

    Projectile::~Projectile()
    {
        vector<ProjectileOccurrence*>::iterator itProjectiles;

        /* ProjectilesOccurrences */
        for(itProjectiles = this->_projectileOccurences.begin(); itProjectiles != this->_projectileOccurences.end(); ++itProjectiles)
        {
            delete (*itProjectiles);
        }

		release();
    }
} // namespace
