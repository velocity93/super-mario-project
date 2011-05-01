////////////////////////////////////////////////////////////////////////
// Level.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Level.hpp"

namespace SuperMarioProject
{
	Coord<int> Level::getSize()
	{
		return _size;
	}

	Coord<int> Level::getBlockSize()
	{
		return _blockSize;
	}

	vector<Object*> Level::getObjects()
	{
		return _objects;
	}

	void Level::update(float time)
	{

	}

	void Level::render(RenderWindow& app)
	{
		/* Iterators Declarations */
		vector<Object*>::iterator itObjects;
		vector<Checkpoint*>::iterator itCheckpoints;
		vector<Pipe*>::iterator itPipes;
		vector<Item*>::iterator itItems;
		vector<Projectile*>::iterator itProjectiles;
		vector<Monster*>::iterator itMonsters;
		
		/* Objects */
		for(itObjects = this->_objects.begin(); itObjects < this->_objects.end(); itObjects++)
		{
			(*itObjects)->render(app);
		}

		/* CheckPoints */
		for(itCheckpoints = this->_checkpoints.begin(); itCheckpoints < this->_checkpoints.end(); itCheckpoints++)
		{
			(*itCheckpoints)->render(app);
		}

		/* Pipes */
		for(itPipes = this->_pipes.begin(); itPipes < this->_pipes.end(); itPipes++)
		{
			(*itPipes)->render(app);
		}

		/* Items */
		for(itItems = this->_items.begin(); itItems < this->_items.end(); itItems++)
		{
			(*itItems)->render(app);
		}

		/* Projectiles */
		for(itProjectiles = this->_projectiles.begin(); itProjectiles < this->_projectiles.end(); itProjectiles++)
		{
			(*itProjectiles)->render(app);
		}
	}

    Level::~Level()
    {
		/* Iterators Declarations */
		vector<Object*>::iterator itObjects;
		vector<Checkpoint*>::iterator itCheckpoints;
		vector<Pipe*>::iterator itPipes;
		vector<Item*>::iterator itItems;
		vector<Projectile*>::iterator itProjectiles;
		vector<Monster*>::iterator itMonsters;

		/* Objects */
		for(itObjects = this->_objects.begin(); itObjects < this->_objects.end(); itObjects++)
		{
			delete (*itObjects);
		}

		/* CheckPoints */
		for(itCheckpoints = this->_checkpoints.begin(); itCheckpoints < this->_checkpoints.end(); itCheckpoints++)
		{
			delete (*itCheckpoints);
		}

		/* Pipes */
		for(itPipes = this->_pipes.begin(); itPipes < this->_pipes.end(); itPipes++)
		{
			delete (*itPipes);
		}

		/* Items */
		for(itItems = this->_items.begin(); itItems < this->_items.end(); itItems++)
		{
			delete (*itItems);
		}

		/* Projectiles */
		for(itProjectiles = this->_projectiles.begin(); itProjectiles < this->_projectiles.end(); itProjectiles++)
		{
			delete (*itProjectiles);
		}

    }
} // namespace
