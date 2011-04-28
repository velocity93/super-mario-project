////////////////////////////////////////////////////////////////////////
// Keystate.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Keystate.hpp"

using namespace sf;

namespace SuperMarioProject
{
    Keystate::Keystate()
    {
		int i = 0;
		_actual = vector<bool>();
		_previous = vector<bool>();

		while(i < NB_KEYS)
		{
			_actual.push_back(false);
			_previous.push_back(false);
			i++;
		}
    }

	vector<bool> Keystate::getActual()
	{
		return _actual;
	}

	vector<bool> Keystate::getPrevious()
	{
		return _previous;
	}

	void Keystate::update(RenderWindow& App)
	{
		const sf::Input& Input = App.GetInput();

		vector<bool>::iterator itActual;
		vector<bool>::iterator itPrevious;

		for(itActual = _actual.begin(), itPrevious = _previous.begin();
			itActual < _actual.end(); itActual++, itPrevious++)
		{
			(*itPrevious) = (*itActual);
		}

		_actual[LEFT] = Input.IsKeyDown(Key::Left);
		_actual[RIGHT] = Input.IsKeyDown(Key::Right);
		_actual[UP] = Input.IsKeyDown(Key::Up);
		_actual[DOWN] = Input.IsKeyDown(Key::Down);
		_actual[JUMP] = Input.IsKeyDown(Key::Space);
		_actual[RUN] = Input.IsKeyDown(Key::B);
		_actual[LEFT_CLICK] = Input.IsMouseButtonDown(Mouse::Left);
		_actual[RIGHT_CLICK] = Input.IsMouseButtonDown(Mouse::Right);
		_actual[ENTER] = Input.IsKeyDown(Key::Return);
		_actual[ESCAPE] = Input.IsKeyDown(Key::Escape);
		_actual[LEFT_CTRL] = Input.IsKeyDown(Key::LControl);
		_actual[SUPPR] = Input.IsKeyDown(Key::Delete);
		_actual[CUT] = Input.IsKeyDown(Key::LControl) && Input.IsKeyDown(Key::X);
		_actual[COPY] = Input.IsKeyDown(Key::LControl) && Input.IsKeyDown(Key::C);
		_actual[PASTE] = Input.IsKeyDown(Key::LControl) && Input.IsKeyDown(Key::V);
	}
} // namespace
