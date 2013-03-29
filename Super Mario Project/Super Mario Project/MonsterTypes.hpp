////////////////////////////////////////////////////////////////////////
// MonsterTypes.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_MONSTER_TYPES
#define HPP_MONSTER_TYPES

#include "Monster.hpp"

namespace smp
{
	class WalkingMonster : public Monster
	{
	public :
		WalkingMonster(const std::string& textureName, 
			bool canBeKilledByJump = false, 
			bool canBeKilledByFire = false, 
			bool canBeJumpedOn = false,
			bool stayOnPlateForm = false);

		void serialize(std::ofstream& file, std::string& tabs);

	private :
		bool _stayOnPlateForm;

		void loadWalkingMonster();
	};

	class ShellMonster : public WalkingMonster
	{

	public :
		ShellMonster(const std::string& textureName, 
			bool canBeKilledByFire = false, 
			bool canBeJumpedOn = false,
			bool stayOnPlateForm = false);

		void serialize(std::ofstream& file, std::string& tabs);

	private :
		void loadShellMonster();
	};

	class FlyingMonster : public Monster
	{
	public :
		FlyingMonster(const std::string& textureName, 
			bool canBeKilledByJump = false, 
			bool canBeKilledByFire = false, 
			bool canBeJumpedOn = false);

		void serialize(std::ofstream& file, std::string& tabs);

	private:
		void loadFlyingMonster();
	};
}
#endif
