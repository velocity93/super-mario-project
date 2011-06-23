////////////////////////////////////////////////////////////////////////
// Monster.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Monster.hpp"
#include <fstream>

namespace Collisions
{
	Monster::Monster(const string& textureName) : _textureName("textures\\monsters\\" + textureName), _canBeKilledByFire(false), 
		_canBeKilledByJump(false), _canBeJumpedOn(false), _stayOnPlateForm(false)
	{
		loadMonster();
	}

	Monster::Monster(const string& textureName, bool canBeKilledByFire, bool canBeKilledByJump, bool canBeJumpedOn, bool stayOnPlateForm) :
		_textureName("textures\\monsters\\" + textureName), _canBeKilledByFire(canBeKilledByFire), _canBeKilledByJump(canBeKilledByJump), _canBeJumpedOn(canBeJumpedOn), _stayOnPlateForm(stayOnPlateForm)
		{
			loadMonster();
		}

	void Monster::addMonsterOccurrence(MonsterOccurrence* monsterOccurrence)
	{
		_monsterOccurrences.push_back(monsterOccurrence);
	}

	vector<MonsterOccurrence*> Monster::getMonsterOccurrences()
	{
		return _monsterOccurrences;
	}
	
	void Monster::removeMonsterOccurrence(const MonsterOccurrence* monster)
	{
		vector<MonsterOccurrence*>::iterator itMonsterOccurrence;

		for(itMonsterOccurrence = _monsterOccurrences.begin(); itMonsterOccurrence < _monsterOccurrences.end(); ++itMonsterOccurrence)
		{
			if((*itMonsterOccurrence) == monster)
				_monsterOccurrences.erase(itMonsterOccurrence);
		}
	}

	void Monster::loadMonster()
	{
		string fileName = _textureName + ".item";
		ifstream stream(fileName.c_str());
		
		if(stream)
		{

		}
		else
		{
			string exceptionName = "Exception occured while opening " + fileName;
			throw exception(exceptionName.c_str());
		}
	}


	void Monster::update(RenderWindow& app)
	{
		vector<MonsterOccurrence*>::iterator itMonsters;

		/* MonsterOccurrences */
		for(itMonsters = this->_monsterOccurrences.begin(); itMonsters < this->_monsterOccurrences.end(); ++itMonsters)
		{
			(*itMonsters)->update(app);
		}
	}

	void Monster::render(RenderWindow& app)
	{
		vector<MonsterOccurrence*>::iterator itMonsters;

		/* MonsterOccurrences */
		for(itMonsters = this->_monsterOccurrences.begin(); itMonsters < this->_monsterOccurrences.end(); ++itMonsters)
		{
			(*itMonsters)->render(app);
		}
	}

    Monster::~Monster()
    {
		vector<MonsterOccurrence*>::iterator itMonsters;

		/* MonsterOccurrences */
		for(itMonsters = this->_monsterOccurrences.begin(); itMonsters < this->_monsterOccurrences.end(); ++itMonsters)
		{
			delete (*itMonsters);
		}
    }
} // namespace
