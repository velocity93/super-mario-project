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
			actual[i] = false;
			previous[i] = false;
		}
    }

	void Keystate::Update(RenderWindow App)
	{
		const sf::Input& Input = App.GetInput();

		for(int i = 0; i < NB_KEYS; i++)
		{
			previous[i] = actual[i];
		}

		actual[LEFT] = Input.IsKeyDown(Key::Left);
		actual[RIGHT] = Input.IsKeyDown(Key::Right);
		actual[UP] = Input.IsKeyDown(Key::Up);
		actual[DOWN] = Input.IsKeyDown(Key::Down);
		actual[JUMP] = Input.IsKeyDown(Key::Space);
		actual[RUN] = Input.IsKeyDown(Key::B);
		actual[LEFT_CLICK] = Input.IsMouseButtonDown(Mouse::Left);
		actual[RIGHT_CLICK] = Input.IsMouseButtonDown(Mouse::Right);
		actual[ENTER] = Input.IsKeyDown(Key::Return);
		actual[ESCAPE] = Input.IsKeyDown(Key::Escape);
		actual[LEFT_CTRL] = Input.IsKeyDown(Key::LControl);
		actual[SUPPR] = Input.IsKeyDown(Key::Delete);
		actual[CUT] = Input.IsKeyDown(Key::LControl) && Input.IsKeyDown(Key::X);
		actual[COPY] = Input.IsKeyDown(Key::LControl) && Input.IsKeyDown(Key::C);
		actual[PASTE] = Input.IsKeyDown(Key::LControl) && Input.IsKeyDown(Key::V);



	}
} // namespace
