////////////////////////////////////////////////////////////////////////
// Monster.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Monster.hpp"
#include <fstream>
#include <sstream>

namespace Collisions
{
    Monster::Monster(const string& textureName, bool canBeKilledByFire, bool canBeKilledByJump, bool canBeJumpedOn, bool stayOnPlateForm) 
        : Resource("textures\\monsters\\" + textureName),
        _canBeKilledByFire(canBeKilledByFire),
        _canBeKilledByJump(canBeKilledByJump),
        _canBeJumpedOn(canBeJumpedOn),
        _stayOnPlateForm(stayOnPlateForm)
    {
        loadMonster();
    }

	void Monster::addNewMonsterOccurrence(Vector2f& position, Vector2f& speed, MonsterOccurrence::State state, MonsterOccurrence::Side side)
    {
		_monsterOccurrences.push_back(new MonsterOccurrence(name(), position, speed, state, side, _nbSpritesByState, _vAnimByState));
    }

    void Monster::removeMonsterOccurrence(const MonsterOccurrence* monster)
    {
        vector<MonsterOccurrence*>::iterator itMonsterOccurrence;

        for(itMonsterOccurrence = _monsterOccurrences.begin(); itMonsterOccurrence != _monsterOccurrences.end(); ++itMonsterOccurrence)
        {
            if((*itMonsterOccurrence) == monster)
                _monsterOccurrences.erase(itMonsterOccurrence);
        }
    }

    void Monster::loadMonster()
    {
        string fileName = name() + ".mstr";
        int abscisse_bas = 0;
        ifstream stream(fileName.c_str());

        if(stream)
        {
            string word;

            /* We read file to search the keyword and read his value */
            while(getline(stream, word))
            {
                int found = word.find("abscisse_bas=");
                if(found != string::npos)
                {
                    istringstream abscisseBas(word.substr(found + 13));
                    abscisseBas >> abscisse_bas;
                    continue;
                }

                found = word.find("canBeJumpedOn=");
                if(found != string::npos)
                {
                    istringstream canBeJumpedOn(word.substr(found + 14));
                    canBeJumpedOn >> _canBeJumpedOn;
                    continue;
                }

                found = word.find("canBeKilledByJump=");
                if(found != string::npos)
                {
                    istringstream canBeKilledByJump(word.substr(found + 18));
                    canBeKilledByJump >> _canBeKilledByJump;
                    continue;
                }

                found = word.find("canBeKilledByFire=");
                if(found != string::npos)
                {
                    istringstream canBeKilledByFire(word.substr(found + 18));
                    canBeKilledByFire >> _canBeKilledByFire;
                }
            }

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
        for(itMonsters = this->_monsterOccurrences.begin(); itMonsters != this->_monsterOccurrences.end(); ++itMonsters)
        {
            (*itMonsters)->update(app);
        }
    }

    void Monster::render(RenderWindow& app)
    {
        vector<MonsterOccurrence*>::iterator itMonsters;

        /* MonsterOccurrences */
        for(itMonsters = this->_monsterOccurrences.begin(); itMonsters != this->_monsterOccurrences.end(); ++itMonsters)
        {
            (*itMonsters)->render(app);
        }
    }

    Monster::~Monster()
    {
        vector<MonsterOccurrence*>::iterator itMonsters;

        /* MonsterOccurrences */
        for(itMonsters = this->_monsterOccurrences.begin(); itMonsters != this->_monsterOccurrences.end(); ++itMonsters)
        {
            delete (*itMonsters);
        }

		release();
    }
} // namespace
