////////////////////////////////////////////////////////////////////////
// World.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "World.hpp"

namespace SuperMarioProject
{
	World::World(const Window* window) :
		_levelNames(vector<string>()),
		_persos(vector<Perso*>()),
		_windowSize(Vector2i()),
		_fpsTime(0),
		_actualTime(0),
		_previousTime(0),
		_elapsedTime(0),
		_previousElapsedTime(0),
		_fps(0),
		_nbFramesCalculated(0),
		_clock(Clock()),
		_level(new Level()),
		_inputState(new InputState(window))
		{

		loadWorld();
		}

	Level* World::getLevel()
	{
		return _level;
	}

	float World::getElapsedTime()
	{
		return _clock.GetElapsedTime();
	}

	void World::update(RenderWindow& app)
	{
		this->_level->update(app);

		vector<Perso*>::iterator it;
		
		for (it= this->_persos.begin(); it < this->_persos.end(); ++it)
			(*it)->updatePerso(app, _inputState);

		updateTime();
	}

	void World::updateTime()
	{
		_previousTime = _actualTime;
		_actualTime = _clock.GetElapsedTime();
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
			_previousTime = _clock.GetElapsedTime();
            _actualTime = _previousTime;
           _elapsedTime = 0;
        }

		vector<Perso*>::iterator it;
		
		for (it = this->_persos.begin(); it < this->_persos.end(); it++)
		{
			if((*it)->getState() != Perso::FINISH && (*it)->getState() != Perso::FINISH_CASTLE && (*it)->getState() != Perso::DEAD
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
		vector<Perso*>::iterator it;

		this->_level->render(app);

		for (it = this->_persos.begin(); it < this->_persos.end(); ++it)
		{
			(*it)->render(app);
		}
	}

	void World::loadWorld()
	{
		ifstream file("world1.wld");

		if(file)
		{
			string line;

			while(getline(file, line))
			{
				_levelNames.push_back(line);
			}
		}
		else
		{
			throw exception("Unable to open file world1.wld");
		}
	}

    World::~World()
    {
		delete _level;
		vector<Perso*>::iterator itPersos;

		/* Persos */
		for(itPersos = this->_persos.begin(); itPersos < this->_persos.end(); ++itPersos)
		{
			delete (*itPersos);
		}

    }
} // namespace
