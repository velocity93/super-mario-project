////////////////////////////////////////////////////////////////////////
// Monster.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_MONSTER
#define HPP_MONSTER

#include "MonsterOccurrence.hpp"
#include <vector>

using namespace std;

namespace Collisions
{
	class MonsterOccurrence;

	class Monster
    {
    public:
        Monster();
        virtual ~Monster();

		vector<MonsterOccurrence*> getMonsterOccurrences();

		void update(float time);
		void render(RenderWindow& app, Screen& screen);
		
    private:		
		int _canBeKilledByFire;
		int _canBeKilledByJump;
		int _canBeJumpedOn;
		int _stayOnPlateForm;
		int _disappearingTime;
		vector<MonsterOccurrence*> _monsterOccurrences;
		// sounds
		// Texture ????
    };
} // namespace

#endif // HPP_MONSTER
