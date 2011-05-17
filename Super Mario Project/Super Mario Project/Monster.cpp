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
	void Monster::addMonsterOccurrence(MonsterOccurrence* monster)
	{
		_monsterOccurrences.push_back(monster);
	}

	vector<MonsterOccurrence*> Monster::getMonsterOccurrences()
	{
		return _monsterOccurrences;
	}
	
	void Monster::removeMonsterOccurrence(MonsterOccurrence* monster)
	{
		vector<MonsterOccurrence*>::iterator itMonsterOccurrence;

		for(itMonsterOccurrence = _monsterOccurrences.begin(); itMonsterOccurrence < _monsterOccurrences.end(); itMonsterOccurrence++)
		{
			if((*itMonsterOccurrence) == monster)
				_monsterOccurrences.erase(itMonsterOccurrence);
		}
	}

	void Monster::update(RenderWindow& app)
	{
		vector<MonsterOccurrence*>::iterator itMonsters;

		/* MonsterOccurrences */
		for(itMonsters = this->_monsterOccurrences.begin(); itMonsters < this->_monsterOccurrences.end(); itMonsters++)
		{
			(*itMonsters)->update(app);
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
