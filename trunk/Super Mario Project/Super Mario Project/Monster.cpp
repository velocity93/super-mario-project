////////////////////////////////////////////////////////////////////////
// Monster.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Monster.hpp"

namespace Collisions
{
	vector<MonsterOccurrence*> Monster::getMonsterOccurrences()
	{
		return _monsterOccurrences;
	}

    Monster::~Monster()
    {
    }
} // namespace
