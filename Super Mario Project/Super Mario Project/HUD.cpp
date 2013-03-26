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
		_nbCoins = 0;
		_score = 0;
		_time = 0;
		_levelName = "";
		_nbMonstersKilled = 0;
		_nbMonstersKilledByShell = 0;

		/* Initialization of points tab  */
		_points.push_back(200);
		_points.push_back(400);
		_points.push_back(800);
		_points.push_back(1000);
		_points.push_back(2000);
		_points.push_back(4000);
		_points.push_back(8000);
	}

	float HUD::getTime()
	{
		return _time;
	}

	int HUD::getNbLives()
	{
		return _nbLives;
	}

	void HUD::setTime(float time)
	{
		_time = time;
	}

	void HUD::setNbMonstersKilled(int nbMonstersKilled)
	{
		_nbMonstersKilled = nbMonstersKilled;
	}

	void HUD::setNbMonstersKilledByShell(int nbMonstersKilledByShell)
	{
		_nbMonstersKilledByShell = nbMonstersKilledByShell;
	}

	void HUD::addPoints(int nbPoints)
	{
		_score += nbPoints;
	}

	void HUD::addCoin()
	{
		_nbCoins++;
		if(_nbCoins == 100)
		{
			_nbCoins = 0;
			addLife();
		}
	}

	void HUD::addLife()
	{
		_nbLives++;
	}

	void HUD::removeLife()
	{
		_nbLives--;
	}

	void HUD::updateGraphicData(RenderWindow& )
	{
		//_time -= app.GetFrameTime();
	}

	void HUD::render(RenderWindow&/*app*/)
	{
		/*sf::String Text;
		sf::Unicode::Text txt;
		Text.SetText("Lives x" + _nbLives);
		Text.SetFont(sf::Font::GetDefaultFont());
		Text.SetSize(50);*/
	}


	HUD::~HUD()
	{
	}
} // namespace
