////////////////////////////////////////////////////////////////////////
// Keystate.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "InputState.hpp"

using sf::Keyboard;
using sf::Window;

namespace smp
{
	InputState* InputState::_inputState = nullptr;

	InputState* InputState::getInput()
	{
		if(_inputState == nullptr)
		{
			_inputState = new InputState();
		}

		return _inputState;
	}

	void InputState::killInput()
	{
		delete _inputState;
	}

    InputState::InputState()
        : _states(KEY_NB_KEYS, KEY_STATE_RELEASED),
        _sfmlKeys()
    {
		_sfmlKeys.push_back(Keyboard::Left);	// KEY_BACKWARD
		_sfmlKeys.push_back(Keyboard::Right);	// KEY_FORWARD
		_sfmlKeys.push_back(Keyboard::Up);		// KEY_UP
		_sfmlKeys.push_back(Keyboard::Down);	// KEY_DOWN
		_sfmlKeys.push_back(Keyboard::Space);	// KEY_JUMP
		_sfmlKeys.push_back(Keyboard::B);		// KEY_RUN
		_sfmlKeys.push_back(Keyboard::Escape);	// KEY_ESCAPE
    }


    void InputState::update()
    {
        for(size_t i = 0; i < _sfmlKeys.size(); i++)
        {
            if(Keyboard::isKeyPressed(_sfmlKeys[i]))
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
