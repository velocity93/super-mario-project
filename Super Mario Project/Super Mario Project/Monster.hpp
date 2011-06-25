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

#include <vector>
#include "MonsterOccurrence.hpp"
#include "Resource.hpp"

using namespace std;

namespace Collisions
{
    class Monster : public SuperMarioProject::Resource
    {
    public:
		Monster(const string& textureName, bool canBeKilledByFire = false, bool canBeKilledByJump = false, bool canBeJumpedOn = false, bool stayOnPlateForm = false);

		/* List of all occurrences */
		vector<MonsterOccurrence*> getMonsterOccurrences();

		/* Add Occurrence */
		void addMonsterOccurrence(MonsterOccurrence* monster);

		/* Remove occurrence */
		void removeMonsterOccurrence(const MonsterOccurrence* monster);

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
		//int _disappearingTime;
		vector<MonsterOccurrence*> _monsterOccurrences;

		/* Load monster configuration */
		void loadMonster();

    };
} // namespace

#endif // HPP_MONSTER
