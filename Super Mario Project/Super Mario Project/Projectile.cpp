////////////////////////////////////////////////////////////////////////
// Projectile.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Projectile.hpp"
#include <fstream>
#include <sstream>

namespace Collisions
{
    Projectile::Projectile(const string& textureName, Type type)
        : Resource("textures\\projectiles\\" + textureName),
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

	void Projectile::addNewProjectileOccurrence(Vector2f& position, Vector2f& speed, ProjectileOccurrence::State state, ProjectileOccurrence::Side side)
    {
		_projectileOccurences.push_back(new ProjectileOccurrence(name(), position, speed, state, side, _nbSpritesByState, _vAnimByState));
    }

    void Projectile::removeProjectileOccurrence(const ProjectileOccurrence* projectile)
    {
        vector<ProjectileOccurrence*>::iterator itProjectileOccurrence;

        for(itProjectileOccurrence = _projectileOccurences.begin(); itProjectileOccurrence < _projectileOccurences.end(); ++itProjectileOccurrence)
        {
            if((*itProjectileOccurrence) == projectile)
                _projectileOccurences.erase(itProjectileOccurrence);
        }
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
                int found = word.find("speed_x=");
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
                    istringstream ordonneeHaut(word.substr(found + 13));
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
                found = word.find("nb_sprites_marche=");
                if(found != string::npos)
                {
					int _nbWalkingSprites;
                    istringstream nbWalkingSprites(word.substr(found + 18));
					nbWalkingSprites >> _nbWalkingSprites;
					_nbSpritesByState.insert(pair<ProjectileOccurrence::State, int>(ProjectileOccurrence::State::LAUNCHED, _nbWalkingSprites));
                    continue;
                }

                /* Manage sprites numbers here */
                found = word.find("nb_sprites_mort=");
                if(found != string::npos)
                {
					int _nbDeadSprites;
                    istringstream nbDeadSprites(word.substr(found + 16));
					nbDeadSprites >> _nbDeadSprites;
					_nbSpritesByState.insert(pair<ProjectileOccurrence::State, int>(ProjectileOccurrence::State::DEAD, _nbDeadSprites));
                    continue;
                }

                /* Manage speed of animation numbers here */
                found = word.find("v_anim_marche=");
                if(found != string::npos)
                {
					int _vWalkingAnim;
                    istringstream vWalkingAnim(word.substr(found + 14));
					vWalkingAnim >> _vWalkingAnim;
					_vAnimByState.insert(pair<ProjectileOccurrence::State, int>(ProjectileOccurrence::State::LAUNCHED, _vWalkingAnim));
                    continue;
                }

                /* Manage speed of animation numbers here */
                found = word.find("v_anim_mort=");
                if(found != string::npos)
                {
					int _vDeadAnim;
					istringstream vDeadAnim(word.substr(found + 12));
                    vDeadAnim >> _vDeadAnim;
					_vAnimByState.insert(pair<ProjectileOccurrence::State, int>(ProjectileOccurrence::State::DEAD, _vDeadAnim));
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

    void Projectile::update(RenderWindow& app)
    {
        vector<ProjectileOccurrence*>::iterator itProjectiles;

        /* ProjectilesOccurrences */
        for(itProjectiles = this->_projectileOccurences.begin(); itProjectiles < this->_projectileOccurences.end(); ++itProjectiles)
        {
            (*itProjectiles)->update(app);
        }
    }

    void Projectile::render(RenderWindow& app)
    {
        vector<ProjectileOccurrence*>::iterator itProjectiles;

        /* ProjectilesOccurrences */
        for(itProjectiles = this->_projectileOccurences.begin(); itProjectiles < this->_projectileOccurences.end(); ++itProjectiles)
        {
            (*itProjectiles)->render(app);
        }
    }


    Projectile::~Projectile()
    {
        vector<ProjectileOccurrence*>::iterator itProjectiles;

        /* ProjectilesOccurrences */
        for(itProjectiles = this->_projectileOccurences.begin(); itProjectiles < this->_projectileOccurences.end(); ++itProjectiles)
        {
            delete (*itProjectiles);
        }

		release();
    }
} // namespace
