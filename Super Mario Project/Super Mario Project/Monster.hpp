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
		Monster(const string& textureName, 
			bool canBeKilledByJump = false, 
			bool canBeKilledByFire = false, 
			bool canBeJumpedOn = false);

		/* Add Occurrence */
		void addNewMonsterOccurrence(Vector2f& position = Vector2f(0,0), Vector2f& speed = Vector2f(0,0), 
			MonsterOccurrence::State state = MonsterOccurrence::State::M_WALK,
			MonsterOccurrence::Side side = MonsterOccurrence::Side::LEFT_SIDE);

		/* Getters/Setters */
		int getBottomLeft();
		bool getCanBeKilledByJump();
		bool getCanBeKilledByFire();
		bool getCanBeJumpedOn();

		/* Remove occurrence */
		void removeMonsterOccurrence(const MonsterOccurrence* monster);

		/* Update data */
		void update(RenderWindow& app);

		/* render all occurrence */
		void render(RenderWindow& app);

		/* Destructor */
		virtual ~Monster();
		
	protected :
		map<MonsterOccurrence::State, int> _nbSpritesByState;
		map<MonsterOccurrence::State, int> _frameDelayByState;

    private:
		int _bottomLeft;
		int _points;
		bool _canBeKilledByFire;
		bool _canBeKilledByJump;
		bool _canBeJumpedOn;		
		vector<MonsterOccurrence*> _monsterOccurrences;

		/* Load monster configuration */
		void loadMonster();

    };
} // namespace

#endif // HPP_MONSTER
