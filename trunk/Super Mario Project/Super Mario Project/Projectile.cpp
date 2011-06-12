////////////////////////////////////////////////////////////////////////
// Projectile.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Projectile.hpp"
#include <fstream>

namespace Collisions
{
	Projectile::Projectile(const string& textureName) : _type(FRAGMENT), _submission(0), _initialSpeed(Vector2f())
	{
		_textureName = "textures\\projectiles\\" + textureName;
		loadProjectile();
	}

	Projectile::Projectile(const string& textureName, Type type, int submission) : _type(type), _submission(submission), _initialSpeed(Vector2f())
	{
		_textureName = "textures\\projectiles\\" + textureName;
		loadProjectile();
	}

	int Projectile::getSubmission()
	{
		return _submission;
	}

	vector<ProjectileOccurrence*> Projectile::getProjectileOccurrences()
	{
		return _projectileOccurences;
	}

	void Projectile::addNewProjectileOccurrence()
	{
		_projectileOccurences.push_back(new ProjectileOccurrence(_textureName, this));
	}

	void Projectile::removeProjectileOccurrence(const ProjectileOccurrence* projectile)
	{
		vector<ProjectileOccurrence*>::iterator itProjectileOccurrence;

		for(itProjectileOccurrence = _projectileOccurences.begin(); itProjectileOccurrence < _projectileOccurences.end(); itProjectileOccurrence++)
		{
			if((*itProjectileOccurrence) == projectile)
				_projectileOccurences.erase(itProjectileOccurrence);
		}
	}

	void Projectile::loadProjectile()
	{
		int abscisse_bas = 0, ordonnee_haut = 0, nb_sprites_max = 0;
		string fileName = _textureName + ".proj";
		ifstream stream(fileName.c_str());
		vector<string> keywords;
		keywords.push_back("marche");
		keywords.push_back("mort");
		vector<string>::iterator itKeywords;
		
		if(stream)
		{
			string word, wordToCompare;
			int value = INT_MIN;

			stream >> word;
			if(word == "speed_x=")
			{
				stream >> _initialSpeed.x;
			}
			else
				throw exception(" \"speed_x=\" keyword is missing");

			/* Important keywords */
			stream >> word;
			if(word == "abscisse_bas=")
			{
				stream >> abscisse_bas;
			}
			else
				throw exception("\"abscisse_bas=\" keyword is missing");

			stream >> word;
			if(word == "ordonnee_haut=")
			{
				stream >> ordonnee_haut;
			}
			else
				throw exception("\"ordonnee_haut=\" keyword is missing");

			for(itKeywords = keywords.begin(); itKeywords < keywords.end(); ++itKeywords)
			{
				stream >> word;
				wordToCompare = "nb_sprites_" + *itKeywords + "=";
				if(word == wordToCompare)
				{
					stream >> value;

					// To compute Sprite size
					if(value > nb_sprites_max)
						nb_sprites_max = value;

					value = INT_MIN;
				}
				else
				{
					wordToCompare = "\"" + wordToCompare;
					wordToCompare += "\" keyword is missing";
					throw exception(wordToCompare.c_str());
				}

				stream >> word;
				wordToCompare = "v_anim_" + *itKeywords + "=";
				if(word == wordToCompare)
				{
					stream >> value;
					value = 0;
				}
				else
				{
					wordToCompare = "\"" + wordToCompare;
					wordToCompare += "\" keyword is missing";
					throw exception(wordToCompare.c_str());
				}
			}

			stream >> word;
			if(word == "submission=")
			{
				/* Read hexadecimal number with 'hex' manipulator */
				stream >> hex >> _submission;
			}
			else
				throw exception("\"submission=\" keyword is missing");

			
			
			/* Add apparition_time and disappearing_time later */


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
		for(itProjectiles = this->_projectileOccurences.begin(); itProjectiles < this->_projectileOccurences.end(); itProjectiles++)
		{
			(*itProjectiles)->update(app);
		}
	}

	void Projectile::render(RenderWindow& app)
	{
		vector<ProjectileOccurrence*>::iterator itProjectiles;
		
		/* ProjectilesOccurrences */
		for(itProjectiles = this->_projectileOccurences.begin(); itProjectiles < this->_projectileOccurences.end(); itProjectiles++)
		{
			(*itProjectiles)->render(app);
		}
	}


    Projectile::~Projectile()
    {
		vector<ProjectileOccurrence*>::iterator itProjectiles;
		
		/* ProjectilesOccurrences */
		for(itProjectiles = this->_projectileOccurences.begin(); itProjectiles < this->_projectileOccurences.end(); itProjectiles++)
		{
			delete (*itProjectiles);
		}
    }
} // namespace
