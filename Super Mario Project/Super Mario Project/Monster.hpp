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
	class Monster
    {
    public:
		Monster() : _canBeKilledByFire(false), _canBeKilledByJump(false), _canBeJumpedOn(false), _stayOnPlateForm(false) { }
		Monster(bool canBeKilledByFire, bool canBeKilledByJump, bool canBeJumpedOn, bool stayOnPlateForm) :
		_canBeKilledByFire(canBeKilledByFire), _canBeKilledByJump(canBeKilledByJump), _canBeJumpedOn(canBeJumpedOn), _stayOnPlateForm(stayOnPlateForm) { }

		/* List of all occurrences */
		vector<MonsterOccurrence*> getMonsterOccurrences();

		/* Add Occurrence */
		void addMonsterOccurrence(MonsterOccurrence* monster);

		/* Remove occurrence */
		void removeMonsterOccurrence(MonsterOccurrence* monster);

		/* Update data */
		void update(RenderWindow& app);

		/* render all occurrence */
		void render(RenderWindow& app);

		/* Destructor */
		virtual ~Monster();
		
    private:		
		bool _canBeKilledByFire;
		bool _canBeKilledByJump;
		bool _canBeJumpedOn;
		bool _stayOnPlateForm;
		int _disappearingTime;
		vector<MonsterOccurrence*> _monsterOccurrences;

    };
} // namespace

#endif // HPP_MONSTER
