////////////////////////////////////////////////////////////////////////
// Monster.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Monster.hpp"
#include <sstream>

namespace Collisions
{
    Monster::Monster(const string& textureName, bool canBeKilledByFire, bool canBeKilledByJump, bool canBeJumpedOn) 
        : Resource("textures/monsters/" + textureName),
        _canBeKilledByFire(canBeKilledByFire),
        _canBeKilledByJump(canBeKilledByJump),
        _canBeJumpedOn(canBeJumpedOn),
		_points(0)
    {
        loadMonster();
    }

	int Monster::getBottomLeft()
	{
		return _bottomLeft;
	}

	bool Monster::getCanBeKilledByJump()
	{
		return _canBeKilledByJump;
	}

	bool Monster::getCanBeKilledByFire()
	{
		return _canBeKilledByFire;
	}

	bool Monster::getCanBeJumpedOn()
	{
		return _canBeJumpedOn;
	}

	vector<MonsterOccurrence*>& Monster::getMonsterOccurrences()
	{
		return _monsterOccurrences;
	}

	void Monster::addNewMonsterOccurrence(Vector2f& position, Vector2f& speed, MonsterOccurrence::State state, MonsterOccurrence::Side side)
    {
		_monsterOccurrences.push_back(new MonsterOccurrence(this, name(), position, speed, state, side, _nbSpritesByState, _frameDelayByState));
    }

    void Monster::removeMonsterOccurrence(const MonsterOccurrence* monster)
    {
        vector<MonsterOccurrence*>::iterator itMonsterOccurrence;

        for(itMonsterOccurrence = _monsterOccurrences.begin(); itMonsterOccurrence != _monsterOccurrences.end(); ++itMonsterOccurrence)
        {
            if((*itMonsterOccurrence) == monster)
			{
                _monsterOccurrences.erase(itMonsterOccurrence);
				if(_monsterOccurrences.size() == 0)
				break;
			}
        }
    }

    void Monster::updatePhysicData(RenderWindow& app)
    {
        for(vector<MonsterOccurrence*>::iterator itMonsters = this->_monsterOccurrences.begin(); itMonsters != this->_monsterOccurrences.end(); ++itMonsters)
        {
            (*itMonsters)->updatePhysicData(app);

			if(_monsterOccurrences.size() == 0)
				break;
        }
    }

	void Monster::updateGraphicData(RenderWindow& app)
    {
        /* MonsterOccurrences */
        for(vector<MonsterOccurrence*>::iterator itMonsters = this->_monsterOccurrences.begin(); itMonsters != this->_monsterOccurrences.end(); ++itMonsters)
        {
            (*itMonsters)->updateGraphicData(app);
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

	void Monster::loadMonster()
    {
        string fileName = name() + ".mstr";
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
                    abscisseBas >> _bottomLeft;
                    continue;
                }

                found = word.find("can_be_jumped_on=");
                if(found != string::npos)
                {
                    istringstream canBeJumpedOn(word.substr(found + 17));
                    canBeJumpedOn >> _canBeJumpedOn;
                    continue;
                }

                found = word.find("can_be_killed_by_jump=");
                if(found != string::npos)
                {
                    istringstream canBeKilledByJump(word.substr(found + 22));
                    canBeKilledByJump >> _canBeKilledByJump;
                    continue;
                }

				found = word.find("can_be_killed_by_fire=");
                if(found != string::npos)
                {
                    istringstream canBeKilledByFire(word.substr(found + 22));
                    canBeKilledByFire >> _canBeKilledByFire;
					continue;
                }

				found = word.find("nb_sprites_walk=");
                if(found != string::npos)
                {
					int nbSpritesWalk;
                    istringstream nbSpritesWalkStream(word.substr(found + 16));
                    nbSpritesWalkStream >> nbSpritesWalk;
					_nbSpritesByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::State::M_WALK, nbSpritesWalk));
					continue;
                }

				found = word.find("nb_sprites_dead_by_jump=");
                if(found != string::npos)
                {
					int nbSpritesDeadByJump;
                    istringstream nbSpritesWalkStream(word.substr(found + 24));
                    nbSpritesWalkStream >> nbSpritesDeadByJump;
					_nbSpritesByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::State::M_DEAD_BY_JUMP_ON, nbSpritesDeadByJump));
					continue;
                }

				found = word.find("nb_sprites_dead_by_proj=");
                if(found != string::npos)
                {
					int nbSpritesDeadByProj;
                    istringstream nbSpritesWalkStream(word.substr(found + 24));
                    nbSpritesWalkStream >> nbSpritesDeadByProj;
					_nbSpritesByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::State::M_DEAD_BY_PROJ, nbSpritesDeadByProj));
					continue;
                }
				
				found = word.find("nb_sprites_retracted=");
                if(found != string::npos)
                {
					int nbSpritesRetracted;
                    istringstream nbSpritesRetractedStream(word.substr(found + 21));
                    nbSpritesRetractedStream >> nbSpritesRetracted;
					_nbSpritesByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::State::M_RETRACTED, nbSpritesRetracted));
					continue;
                }

				
				found = word.find("nb_sprites_get_out_from_shell=");
                if(found != string::npos)
                {
					int nbSpritesGetOutFromShell;
                    istringstream nbSpritesGetOutFromShellStream(word.substr(found + 30));
                    nbSpritesGetOutFromShellStream >> nbSpritesGetOutFromShell;
					_nbSpritesByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::State::M_GET_OUT_FROM_SHELL, nbSpritesGetOutFromShell));
					continue;
                }

				found = word.find("v_anim_walk=");
                if(found != string::npos)
                {
					int vAnimWalk;
                    istringstream vAnimWalkStream(word.substr(found + 12));
                    vAnimWalkStream >> vAnimWalk;
					_frameDelayByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::State::M_WALK, vAnimWalk));
					continue;
                }

				found = word.find("v_anim_retracted=");
                if(found != string::npos)
                {
					int vAnimRetracted;
                    istringstream vAnimRetractedStream(word.substr(found + 17));
                    vAnimRetractedStream >> vAnimRetracted;
					_frameDelayByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::State::M_RETRACTED, vAnimRetracted));
					continue;
                }

				found = word.find("v_anim_dead_by_jump=");
                if(found != string::npos)
                {
					int vAnimDeadByJump;
                    istringstream vAnimDeadByJumpStream(word.substr(found + 20));
                    vAnimDeadByJumpStream >> vAnimDeadByJump;
					_frameDelayByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::State::M_DEAD_BY_JUMP_ON, vAnimDeadByJump));
					continue;
                }

				found = word.find("v_anim_dead_by_proj=");
                if(found != string::npos)
                {
					int vAnimDeadByProj;
                    istringstream vAnimDeadByProjStream(word.substr(found + 20));
                    vAnimDeadByProjStream >> vAnimDeadByProj;
					_frameDelayByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::State::M_DEAD_BY_PROJ, vAnimDeadByProj));
					continue;
                }

				found = word.find("v_anim_get_out_from_shell=");
                if(found != string::npos)
                {
					int vAnimGetOutFromShell;
                    istringstream vAnimGetOutFromShellStream(word.substr(found + 26));
                    vAnimGetOutFromShellStream >> vAnimGetOutFromShell;
					_frameDelayByState.insert(pair<MonsterOccurrence::State, int>(MonsterOccurrence::State::M_GET_OUT_FROM_SHELL, vAnimGetOutFromShell));
					continue;
                }

				found = word.find("points=");
                if(found != string::npos)
                {
                    istringstream points(word.substr(found + 7));
                    points >> _points;
                }
            }
        }
        else
        {
            string exceptionName = "Exception occured while opening " + fileName;
            throw exception(exceptionName.c_str());
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
