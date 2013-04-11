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
#include <bitset>
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

		/* Monster features */
		typedef enum {
			CAN_BE_JUMP_ON,
			CAN_BE_KILL_BY_JUMP,
			CAN_BE_KILL_BY_PROJ,
			STAY_ON_PLATFORM,
			NB_FEATURES
		} Feature;
	};

    class Monster : public Resource
    {
    public:
		Monster(const std::string& textureName);

		/* Add Occurrence */
		void addNewMonsterOccurrence(const sf::Vector2f& position = sf::Vector2f(0,0), const sf::Vector2f& speed = sf::Vector2f(MonsterConstants::MONSTER_SPEED_X,0), 
			MonsterOccurrence::State state = MonsterOccurrence::WALK,
			MonsterOccurrence::Side side = MonsterOccurrence::LEFT_SIDE);

		/* Getters/Setters */
		int getBottomLeft();
		void setDeltaX(int x);
		void setDeltaY(int y);
		std::vector<MonsterOccurrence*>& getMonsterOccurrences();
		
		/* To determine if monster can be jumped for example */
		void setFeature(const std::string& bits);
		bool checkFeature(MonsterConstants::Feature feature);

		/* render all occurrence */
		void render(sf::RenderWindow& app);

		/* Animation data Management */
		void addNbSpritesForState(MonsterOccurrence::State state, int nbSprites);
		void addFrameDelayForState(MonsterOccurrence::State state, int frame_delay);

		/* Serialize data */
		void serialize(std::ofstream& file, const std::string& tabs);

		/* Destructor */
		virtual ~Monster();
		
	protected :
		int _bottomLeft;
		int _points;
		std::bitset<MonsterConstants::NB_FEATURES> _features;
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
