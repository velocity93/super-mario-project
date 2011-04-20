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
		for(int i = 0; i < NB_KEYS; i++)
		{
			_actual[i] = false;
			_previous[i] = false;
		}
    }

	bool* Keystate::getActual()
	{
		return _actual;
	}

	bool* Keystate::getPrevious()
	{
		return _previous;
	}

	void Keystate::update(RenderWindow& App)
	{
		const sf::Input& Input = App.GetInput();

		for(int i = 0; i < NB_KEYS; i++)
		{
			_previous[i] = _actual[i];
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
