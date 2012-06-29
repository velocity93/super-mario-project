////////////////////////////////////////////////////////////////////////
// Keystate.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_INPUTSTATE
#define HPP_INPUTSTATE

#include <vector>
#include <SFML/Window.hpp>

namespace SuperMarioProject
{
    enum KeyState {
        KEY_STATE_RELEASED,
        KEY_STATE_PRESSED,
        KEY_STATE_JUST_PRESSED
    };


    enum Key {
        KEY_NONE = -1,
        KEY_BACKWARD,
        KEY_FORWARD,
        KEY_UP,
        KEY_DOWN,
        KEY_JUMP,
        KEY_RUN,
        KEY_ESCAPE,

        KEY_NB_KEYS
    };


    class InputState
    {
    public:
        InputState(const sf::Window *window);
        void update();
        KeyState operator[](Key k);

    private:
        const sf::Window *_window;
        std::vector<KeyState> _states;
		std::vector<sf::Keyboard::Key> _sfmlKeys;
    };
} // namespace

#endif // HPP_INPUTSTATE
