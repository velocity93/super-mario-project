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

#include "Coord.hpp"

#include <vector>


using namespace Utils;
using namespace std;

namespace Collisions
{
	class MonsterOccurrence;

	class Monster
    {
    public:
        Monster();
        virtual ~Monster();
		
    private:
		Coord<int> _size;
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
