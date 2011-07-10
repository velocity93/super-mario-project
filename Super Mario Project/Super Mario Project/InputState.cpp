////////////////////////////////////////////////////////////////////////
// Keystate.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "InputState.hpp"

namespace SuperMarioProject
{
    InputState::InputState(const sf::Window *window)
        : _window(window),
        _states(KEY_NB_KEYS, KEY_STATE_RELEASED),
        _sfmlKeys()
    {
		_sfmlKeys.push_back(sf::Key::Left);		// KEY_BACKWARD
		_sfmlKeys.push_back(sf::Key::Right);	// KEY_FORWARD
		_sfmlKeys.push_back(sf::Key::Up);		// KEY_UP
		_sfmlKeys.push_back(sf::Key::Down);		// KEY_DOWN
		_sfmlKeys.push_back(sf::Key::Space);	// KEY_JUMP
		_sfmlKeys.push_back(sf::Key::B);		// KEY_RUN
		_sfmlKeys.push_back(sf::Key::Escape);	// KEY_ESCAPE
    }


    void InputState::update()
    {
        const sf::Input &input = _window->GetInput();

        for(size_t i = 0; i < _sfmlKeys.size(); i++)
        {
            if(input.IsKeyDown(_sfmlKeys[i]))
            {
                if(_states[i] == KEY_STATE_RELEASED)
                    _states[i] = KEY_STATE_JUST_PRESSED;
                else
                    _states[i] = KEY_STATE_PRESSED;
            }
            else
                _states[i] = KEY_STATE_RELEASED;
        }
    }


    KeyState InputState::operator[](Key k)
    {
        return _states[k];
    }
} // namespace
