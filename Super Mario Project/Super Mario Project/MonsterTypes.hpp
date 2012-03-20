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

		void serialize(ofstream& file, string& tabs);

	private :
		bool _stayOnPlateForm;

		void loadWalkingMonster();
	};

	class ShellMonster : public WalkingMonster
	{

	public :
		ShellMonster(const string& textureName, 
			bool canBeKilledByFire = false, 
			bool canBeJumpedOn = false,
			bool stayOnPlateForm = false);

		void serialize(ofstream& file, string& tabs);

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

		void serialize(ofstream& file, string& tabs);

	private:
		void loadFlyingMonster();
	};
}
#endif
