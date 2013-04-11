////////////////////////////////////////////////////////////////////////
// Monster.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Monster.hpp"
#include "XMLMonsterParser.hpp"
#include <sstream>

using namespace std;
using sf::Vector2f;
using sf::RenderWindow;

namespace smp
{
    Monster::Monster(const string& textureName) 
        : Resource("textures/monsters/" + textureName),
		_points(0)
    {
        loadMonster();
    }

	int Monster::getBottomLeft()
	{
		return _bottomLeft;
	}

	bool Monster::checkFeature(MonsterConstants::Feature feature)
	{
		return _features[feature];
	}	

	void Monster::setFeature(const string& bits)
	{
		_features.reset();
		_features = bitset<MonsterConstants::NB_FEATURES>(bits);
	}

	void Monster::setDeltaX(int x)
	{
		_bottomLeft = x;
	}

	vector<MonsterOccurrence*>& Monster::getMonsterOccurrences()
	{
		return _monsterOccurrences;
	}

	void Monster::addNewMonsterOccurrence(const Vector2f& position, const Vector2f& speed, MonsterOccurrence::State state, MonsterOccurrence::Side side)
    {
		_monsterOccurrences.push_back(new MonsterOccurrence(this, name(), position, speed, state, side, _nbSpritesByState, _frameDelayByState));
    }

	void Monster::addNbSpritesForState(MonsterOccurrence::State state, int nbSprites)
	{
		_nbSpritesByState.insert(pair<MonsterOccurrence::State, int>(state, nbSprites));
	}

	void Monster::addFrameDelayForState(MonsterOccurrence::State state, int frameDelay)
	{
		_frameDelayByState.insert(pair<MonsterOccurrence::State, int>(state, frameDelay));
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
		XMLMonsterParser::getParser()->loadMonster(name() + ".xml", this);
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


	/* Initialize Monster Constants */
	const float MonsterConstants::MONSTER_SPEED_X = -30.0F;
	const float MonsterConstants::MONSTER_EXIT_PIPE_SPEED_Y = 5.0F;
} // namespace
