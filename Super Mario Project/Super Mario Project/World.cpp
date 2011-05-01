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
	Level* World::getLevel()
	{
		return _level;
	}

	void World::update(RenderWindow& app)
	{
		this->_level->update(app.GetFrameTime());

		vector<Perso*>::iterator it;
		
		for (it= this->_persos.begin(); it < this->_persos.end(); it++)
			(*it)->update(app.GetFrameTime());

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

		/* Si la différence de temps entre deux images est supérieure à 0.5s
                alors on remet le temps précédent en temps actuel
                pour qu'il n'y ait pas de collisions (il n'y a pas eu de déplacement) */
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

		for (it = this->_persos.begin(); it < this->_persos.end(); it++)
		{
			(*it)->render(app);
		}
	}

	void World::updateScreen()
	{
		/* General Case */
        /* horizontal */
		if((_persos.front()->getPosition().getX() - _screen.getScrolling().getX()) > _screen.getSize().getX() * SCROLLING_AV)
			_screen.getScrolling().set(_persos.front()->getPosition().getX() - _screen.getSize().getX() * SCROLLING_AV, _screen.getScrolling().getY());

        else if((_persos.front()->getPosition().getX() - _screen.getScrolling().getX()) < _screen.getSize().getX() * SCROLLING_AR)
			_screen.getScrolling().set(_persos.front()->getPosition().getX() - _screen.getSize().getX() * SCROLLING_AR, _screen.getScrolling().getY());

        /* vertical */
        if((_persos.front()->getPosition().getY() - _screen.getScrolling().getY()) > _screen.getSize().getY() * SCROLLING_HAUT)
			_screen.getScrolling().set(_screen.getScrolling().getX(), _persos.front()->getPosition().getY() - _screen.getSize().getY() * SCROLLING_HAUT);

        else if((_persos.front()->getPosition().getY() - _screen.getScrolling().getY()) < _screen.getSize().getY() * SCROLLING_BAS)
			_screen.getScrolling().set(_screen.getScrolling().getX(), _persos.front()->getPosition().getY() - _screen.getSize().getY() * SCROLLING_BAS);

		/* particular case for level limits and if level is smaller than screen */
        /* horizontal */
		if(_screen.getScrolling().getX() > (_level->getSize().getX() * _level->getBlockSize().getX() - _screen.getSize().getX()))
			_screen.getScrolling().set(_level->getSize().getX() * _level->getBlockSize().getX() - _screen.getSize().getX(), _screen.getScrolling().getY());
        if(_screen.getScrolling().getX() < 0)
                _screen.getScrolling().set(0, _screen.getScrolling().getY());

        /* vertical */
       if(_screen.getScrolling().getY() > (_level->getSize().getY() * _level->getBlockSize().getY() - _screen.getSize().getY()))
			_screen.getScrolling().set(_screen.getScrolling().getX(), _level->getSize().getY() * _level->getBlockSize().getY() - _screen.getSize().getY());
        if(_screen.getScrolling().getY() < 0)
            _screen.getScrolling().set( _screen.getScrolling().getY(), 0);
	}

    World::~World()
    {
		delete _level;
		vector<Perso*>::iterator itPersos;

		/* Persos */
		for(itPersos = this->_persos.begin(); itPersos < this->_persos.end(); itPersos++)
		{
			delete (*itPersos);
		}

    }
} // namespace
