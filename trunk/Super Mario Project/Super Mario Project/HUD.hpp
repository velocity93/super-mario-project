////////////////////////////////////////////////////////////////////////
// HUD.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_HUD
#define HPP_HUD

#define NB_POINTS 7

#include <string>
#include <queue>

using namespace std;

namespace Rendering
{
    class HUD
    {
    public:
		HUD();

		int getTime();
		void setTime(float time);

        virtual ~HUD();
		
    private:
		int _idPerso;
		int _nbLives;
		int _score;
		float _time;
		string _levelName;
		//Item item;
		//font_2d* font;
		int _nbMonstersKilled;
		int _nbMonstersKilledByShell;
		int _points[NB_POINTS]; // pour les points à la suite
		queue<int> _queue_points;

    };
} // namespace

#endif // HPP_HUD
