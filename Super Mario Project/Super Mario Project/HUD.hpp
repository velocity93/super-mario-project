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
#include <vector>
#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;

namespace Rendering
{
    class HUD
    {
    public:
		HUD();

		int getTime();
		int getNbLives();
		void setTime(float time);
		void setNbLives(int nbLives);
		void setNbMonstersKilled(int NbMonstersKilled);
		void setNbMonstersKilledByShell(int NbMonstersKilledByShell);

		void update(RenderWindow& app);
		void render(RenderWindow& app);

        virtual ~HUD();
		
    private:
		int _idPerso;
		int _nbLives;
		int _score;
		float _time;
		string _levelName;
		//Item* item;
		int _nbMonstersKilled;
		int _nbMonstersKilledByShell;
		vector<int> _points; 
		vector<int> _queue_points;

    };
} // namespace

#endif // HPP_HUD
