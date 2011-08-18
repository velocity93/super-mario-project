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

using namespace std;

namespace Collisions
{
	class WalkingMonster : public Monster
	{
	public :
		WalkingMonster(const string& textureName, 
			bool canBeKilledByJump = false, 
			bool canBeKilledByFire = false, 
			bool canBeJumpedOn = false,
			bool stayOnPlateForm = false);

	private :
		bool _stayOnPlateForm;

		void loadWalkingMonster();
	};

	class ShellMonster : public WalkingMonster
	{

	public :
		ShellMonster(const string& textureName, 
			bool canBeKilledByJump = false, 
			bool canBeKilledByFire = false, 
			bool canBeJumpedOn = false,
			bool stayOnPlateForm = false);

	private :
		void loadShellMonster();
	};

	class FlyingMonster : public Monster
	{
	public :
		FlyingMonster(const string& textureName, 
			bool canBeKilledByJump = false, 
			bool canBeKilledByFire = false, 
			bool canBeJumpedOn = false);

	private:
		void loadFlyingMonster();
	};
}
#endif
