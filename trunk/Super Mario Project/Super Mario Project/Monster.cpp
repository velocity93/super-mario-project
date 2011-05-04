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

	void Monster::update(float time)
	{
		vector<MonsterOccurrence*>::iterator itMonsters;

		/* MonsterOccurrences */
		for(itMonsters = this->_monsterOccurrences.begin(); itMonsters < this->_monsterOccurrences.end(); itMonsters++)
		{
			(*itMonsters)->update(time);
		}
	}

	void Monster::render(RenderWindow& app)
	{
		vector<MonsterOccurrence*>::iterator itMonsters;

		/* MonsterOccurrences */
		for(itMonsters = this->_monsterOccurrences.begin(); itMonsters < this->_monsterOccurrences.end(); itMonsters++)
		{
			(*itMonsters)->render(app);
		}
	}

    Monster::~Monster()
    {
		vector<MonsterOccurrence*>::iterator itMonsters;

		/* MonsterOccurrences */
		for(itMonsters = this->_monsterOccurrences.begin(); itMonsters < this->_monsterOccurrences.end(); itMonsters++)
		{
			delete (*itMonsters);
		}
    }
} // namespace
