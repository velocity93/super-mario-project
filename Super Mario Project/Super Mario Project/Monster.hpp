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
#include <fstream>
#include "MonsterOccurrence.hpp"
#include "Resource.hpp"

namespace smp
{
	class MonsterConstants
	{
	public:
		static const float MONSTER_SPEED_X;
		static const float MONSTER_EXIT_PIPE_SPEED_Y;
	};

    class Monster : public Resource
    {
    public:
		Monster(const std::string& textureName, 
			bool canBeKilledByJump = false, 
			bool canBeKilledByFire = false, 
			bool canBeJumpedOn = false);

		/* Add Occurrence */
		void addNewMonsterOccurrence(const sf::Vector2f& position = sf::Vector2f(0,0), const sf::Vector2f& speed = sf::Vector2f(MonsterConstants::MONSTER_SPEED_X,0), 
			MonsterOccurrence::State state = MonsterOccurrence::WALK,
			MonsterOccurrence::Side side = MonsterOccurrence::LEFT_SIDE);

		/* Getters/Setters */
		int getBottomLeft();
		bool canBeKilledByJump();
		bool canBeKilledByFire();
		bool canBeJumpedOn();
		std::vector<MonsterOccurrence*>& getMonsterOccurrences();

		/* render all occurrence */
		void render(sf::RenderWindow& app);

		/* Serialize data */
		void serialize(std::ofstream& file, const std::string& tabs);

		/* Destructor */
		virtual ~Monster();
		
	protected :
		int _bottomLeft;
		int _points;
		bool _canBeKilledByFire;
		bool _canBeKilledByJump;
		bool _canBeJumpedOn;
		std::vector<MonsterOccurrence*> _monsterOccurrences;
		std::map<MonsterOccurrence::State, int> _nbSpritesByState;
		std::map<MonsterOccurrence::State, int> _frameDelayByState;

    private:
		/* Load monster configuration */
		void loadMonster();

    };
} // namespace

#endif // HPP_MONSTER
