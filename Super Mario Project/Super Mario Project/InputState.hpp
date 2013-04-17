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

#include <SFML/Window.hpp>
#include <vector>

namespace smp
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
        static InputState* getInput();
        void update();
        KeyState operator[](Key k);
		static void killInput();

    private:
        std::vector<KeyState> _states;
		std::vector<sf::Keyboard::Key> _sfmlKeys;
		
		static InputState* _inputState;
		
		InputState();
		virtual ~InputState() { }
    };
} // namespace

#endif // HPP_INPUTSTATE
