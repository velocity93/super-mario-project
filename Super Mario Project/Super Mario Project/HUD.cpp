////////////////////////////////////////////////////////////////////////
// Hud.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "HUD.hpp"

namespace Rendering
{
    HUD::HUD()
    {
		 idPerso = -1;
		 nbLives = 0;
		 score = 0;
		 time = 0;
		 levelName = "";
		 nbMonstersKilled = 0;
		 nbMonstersKilledByShell = 0;

		 /* Initialization of points tab  */
		 points[0] = 200;
		 points[1] = 400;
		 points[2] = 800;
		 points[3] = 1000;
		 points[4] = 2000;
		 points[5] = 4000;
		 points[6] = 8000;
    }


    HUD::~HUD()
    {
    }
} // namespace
