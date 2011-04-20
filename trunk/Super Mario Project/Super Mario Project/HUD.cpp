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
		_idPerso = -1;
		_nbLives = 0;
		_score = 0;
		_time = 0;
		_levelName = "";
		_nbMonstersKilled = 0;
		_nbMonstersKilledByShell = 0;

		/* Initialization of points tab  */
		_points[0] = 200;
		_points[1] = 400;
		_points[2] = 800;
		_points[3] = 1000;
		_points[4] = 2000;
		_points[5] = 4000;
		_points[6] = 8000;
	}

	int HUD::getTime()
	{
		return _time;
	}

	void HUD::setTime(float time)
	{
		_time = time;
	}


	HUD::~HUD()
	{
	}
} // namespace
