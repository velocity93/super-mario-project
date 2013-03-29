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

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

namespace smp
{
    class HUD
    {
    public:
		HUD();

		float getTime();
		int getNbLives();
		void setTime(float time);
		void setNbMonstersKilled(int NbMonstersKilled);
		void setNbMonstersKilledByShell(int NbMonstersKilledByShell);

		void addLife();
		void removeLife();
		void addCoin();
		void addPoints(int nbPoints);
		void updateGraphicData(sf::RenderWindow& app);
		void render(sf::RenderWindow& app);

        virtual ~HUD();
		
    private:
		int _idPerso;
		int _nbLives;
		int _nbCoins;
		int _score;
		float _time;
		std::string _levelName;
		//Item* item;
		int _nbMonstersKilled;
		int _nbMonstersKilledByShell;
		std::vector<int> _points; 
		std::vector<int> _queue_points;

    };
} // namespace

#endif // HPP_HUD
