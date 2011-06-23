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
        _sfmlKeys[KEY_BACKWARD] = sf::Key::Left;
        _sfmlKeys[KEY_FORWARD] = sf::Key::Right;
        _sfmlKeys[KEY_UP] = sf::Key::Up;
        _sfmlKeys[KEY_DOWN] = sf::Key::Down;
        _sfmlKeys[KEY_JUMP] = sf::Key::Space;
        _sfmlKeys[KEY_RUN] = sf::Key::B;
        _sfmlKeys[KEY_ESCAPE] = sf::Key::Escape;
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
