////////////////////////////////////////////////////////////////////////
// World.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "World.hpp"
#include "XMLParser.hpp"
#include "CollisionManager.hpp"
#include "HUD.hpp"
#include <fstream>
#include <iostream>

namespace SuperMarioProject
{
	World::World(const Window* window) : _inputState(InputState(window)),
		_level(new Level()),
		_actualTime(0),
		_previousTime(0),
		_elapsedTime(0)
		{
			loadWorld();

			if(_levelNames.size() > 0)
			{
				_level->loadLevel(_levelNames[0]);
				_levelTree = new QuadTree(Vector2f(_level->getSize().x / 2.0f,
					_level->getSize().y / 2.0f), _level->getSize(), 0);
				_levelTree->buildTree(_level->getBlocksOccurrences());
			}

			/* Add default perso */
			_persos.push_back(new Perso("small_mario", _level->getSpawn()));
		}

	Level* World::getLevel()
	{
		return _level;
	}

	float World::getElapsedTime()
	{
		return _clock.getElapsedTime().asMilliseconds();
	}

	void World::addLevelName(string levelName)
	{
		_levelNames.push_back("levels/" + levelName);
	}

	void World::update(RenderWindow& app, View* view)
	{
		_inputState.update();
		
		for (vector<Perso*>::iterator itPerso = this->_persos.begin(); itPerso != this->_persos.end(); ++itPerso)
		{
			/* Update Physic */
			(*itPerso)->updatePerso(_elapsedTime, _inputState);
			
			/* Search in level QuadTree, all blocks will be able to have a collision with him */
			Vector2f position = Vector2f((*itPerso)->getHitboxPosition().x, (*itPerso)->getHitboxPosition().y);
			vector<BlockOccurrence*> blocks;
			_levelTree->getBlocks(position, (*itPerso)->getHitboxSize(), &blocks);

			/* Resolve collisions with Blocks if able*/
			for (vector<BlockOccurrence*>::iterator itBlocks = blocks.begin(); itBlocks != blocks.end(); ++itBlocks)
			{
				Collisions::CollisionManager::solveCollisions((*itPerso), (*itBlocks));
			}

			/* Resolve collisions with Items if able */
			vector<Item*>& items = _level->getItems();
			for (vector<Item*>::iterator itItems = items.begin(); itItems != items.end(); ++itItems)
			{
				vector<ItemOccurrence*>& itemsOccurrences = (*itItems)->getItemOccurrences();
				for (vector<ItemOccurrence*>::iterator itItemOcc = itemsOccurrences.begin(); itItemOcc != itemsOccurrences.end(); ++itItemOcc)
				{
					if((*itItemOcc)->isActive())
					{
						Collisions::CollisionManager::solveCollisions((*itPerso), (*itItemOcc));
						if((*itItemOcc)->getState() == ItemOccurrence::TAKEN)
						{
							itItemOcc = (*itItems)->getItemOccurrences().erase(itItemOcc);

							/* If there is anyone item, we exit the loop */
							if(itemsOccurrences.empty())
								break;
						}
					}
				}
			}

			/* Resolve collisions with Monsters if able */
			vector<Monster*>& monsters = _level->getMonsters();
			for (vector<Monster*>::iterator itMonsters = monsters.begin(); itMonsters != monsters.end(); ++itMonsters)
			{
				vector<MonsterOccurrence*>& monstersOccurrences = (*itMonsters)->getMonsterOccurrences();
				for (vector<MonsterOccurrence*>::iterator itMonsterOcc = monstersOccurrences.begin(); itMonsterOcc != monstersOccurrences.end(); ++itMonsterOcc)
				{
					if((*itMonsterOcc)->isActive() 
						&& (*itMonsterOcc)->getState() != MonsterOccurrence::DEAD
						&& (*itMonsterOcc)->getState() != MonsterOccurrence::DEAD_BY_JUMP_ON
						&& (*itMonsterOcc)->getState() != MonsterOccurrence::DEAD_BY_PROJ)
					{
						Collisions::CollisionManager::solveCollisions((*itPerso), (*itMonsterOcc));
						if((*itMonsterOcc)->getState() == MonsterOccurrence::DEAD)
						{
							//itMonsterOcc = (*itMonsters)->getMonsterOccurrences().erase(itMonsterOcc);

							/* If there is anyone item, we exit the loop */
							if(monstersOccurrences.empty())
								break;
						}
					}
				}
			}

			/* Resolve collisions with Monsters if able */
			vector<Projectile*>& projectiles = _level->getProjectiles();
			for (vector<Projectile*>::iterator itProjectile = projectiles.begin(); itProjectile != projectiles.end(); ++itProjectile)
			{
				vector<ProjectileOccurrence*>& projectileOccurrences = (*itProjectile)->getProjectileOccurrences();
				for (vector<ProjectileOccurrence*>::iterator itPojectileOcc = projectileOccurrences.begin(); itPojectileOcc != projectileOccurrences.end(); ++itPojectileOcc)
				{
					if((*itPojectileOcc)->isActive())
					{
						Collisions::CollisionManager::solveCollisions((*itPerso), (*itPojectileOcc));
						if((*itPojectileOcc)->getState() == ProjectileOccurrence::DEAD)
						{
							itPojectileOcc = (*itProjectile)->getProjectileOccurrences().erase(itPojectileOcc);

							/* If there is anyone item, we exit the loop */
							if(projectileOccurrences.empty())
								break;
						}
					}
				}
			}

			/* Resolve collisions with Pipes if able */
			vector<Pipe*>& pipes = _level->getPipes();
			for (vector<Pipe*>::iterator itPipes = pipes.begin(); itPipes != pipes.end(); ++itPipes)
			{
				if((*itPipes)->isActive())
				{
					Collisions::CollisionManager::solveCollisions((*itPerso), (*itPipes));
				}
			}

			/* Resolve collisions with Finishes if able */
			vector<Finish*>& finishes = _level->getFinishes();
			for (vector<Finish*>::iterator itFinish = finishes.begin(); itFinish != finishes.end(); ++itFinish)
			{
				if((*itFinish)->isActive())
				{
					Collisions::CollisionManager::solveCollisions((*itPerso), (*itFinish));
				}
			}

			/* Resolve collisions with Checkpoints if able */
			vector<Checkpoint*>& checkpoints = _level->getCheckpoints();
			for (vector<Checkpoint*>::iterator itCheckpoint = checkpoints.begin(); itCheckpoint != checkpoints.end(); ++itCheckpoint)
			{
				if((*itCheckpoint)->isActive())
				{
					Collisions::CollisionManager::solveCollisions((*itPerso), (*itCheckpoint));
				}
			}

			view->setCenter((*itPerso)->getHitboxPosition());

			/* Update Graphic */
			(*itPerso)->updateGraphicData(app);
		}

		_level->update(_elapsedTime, _levelTree, app); 

		updateTime();
	}

	void World::updateTime()
	{
		_previousTime = _actualTime;
		_actualTime = _clock.getElapsedTime().asSeconds();
		_previousElapsedTime = _elapsedTime;
		_elapsedTime = (_actualTime - _previousTime);

		/* FPS */
		if(_actualTime - _fpsTime >= 250)
		{
			_fpsTime = _actualTime;
			_fps = _nbFramesCalculated * 4;
			_nbFramesCalculated = 0;
		}

		/* If difference beetween actual and previous frame is greater than 0.5s, 
			then we assign previousTime to actual time*/
        if(_elapsedTime > 500)
        {
			_previousTime = _clock.getElapsedTime().asMilliseconds();
            _actualTime = _previousTime;
           _elapsedTime = 0;
        }

		vector<Perso*>::iterator it;
		
		for (it = this->_persos.begin(); it < this->_persos.end(); ++it)
		{
			if((*it)->getState() != Perso::FINISH && (*it)->getState() != Perso::GO_TO_CASTLE && (*it)->getState() != Perso::DEAD
				&& (*it)->getHUD()->getTime() > 0)
			{
				(*it)->getHUD()->setTime((*it)->getHUD()->getTime() - _elapsedTime / 10);
				if((*it)->getHUD()->getTime() < 0)
					(*it)->getHUD()->setTime(0);
			}
		}

		_nbFramesCalculated++;
	}

	void World::render(RenderWindow& app)
	{
		_level->render(app);

		//_levelTree->render(app);

		for (vector<Perso*>::iterator it = this->_persos.begin(); it < this->_persos.end(); ++it)
		{
			(*it)->render(app);
		}
	}

	void World::loadWorld()
	{
		XMLParser::loadWorld("worlds/world1.xml", this);
	}

    World::~World()
    {
		if(_level != nullptr)
			delete _level;

		/* Persos */
		for(vector<Perso*>::iterator itPersos = _persos.begin(); itPersos < _persos.end(); ++itPersos)
		{
			delete (*itPersos);
		}

    }
} // namespace
