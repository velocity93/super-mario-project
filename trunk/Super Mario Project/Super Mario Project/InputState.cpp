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
		_sfmlKeys.push_back(sf::Keyboard::Left);	// KEY_BACKWARD
		_sfmlKeys.push_back(sf::Keyboard::Right);	// KEY_FORWARD
		_sfmlKeys.push_back(sf::Keyboard::Up);		// KEY_UP
		_sfmlKeys.push_back(sf::Keyboard::Down);	// KEY_DOWN
		_sfmlKeys.push_back(sf::Keyboard::Space);	// KEY_JUMP
		_sfmlKeys.push_back(sf::Keyboard::B);		// KEY_RUN
		_sfmlKeys.push_back(sf::Keyboard::Escape);	// KEY_ESCAPE
    }


    void InputState::update()
    {
        for(size_t i = 0; i < _sfmlKeys.size(); i++)
        {
            if(sf::Keyboard::isKeyPressed(_sfmlKeys[i]))
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
