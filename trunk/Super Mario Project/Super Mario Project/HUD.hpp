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

#include "Item.hpp"
#include <string>

using namespace std;
using namespace Collisions;

namespace Rendering
{
    class HUD
    {
    public:
		HUD();

        ~HUD();
		
    private:
		int idPerso;
		int nbLives;
		int score;
		int time;
		string levelName;
		//Item item;
		//font_2d* font;
		int nbMonstersKilled;
		int nbMonstersKilledByShell;
		int points[NB_POINTS]; // pour les points à la suite
		//int file_points; pour la file des points affiches à l'écran

    };
} // namespace

#endif // HPP_HUD
