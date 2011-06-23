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
		WalkingMonster(const string& textureName) : Monster(textureName) { }

	private :
		void loadWalkingMonster();
	}

	class ShellMonster : public WalkingMonster
	{

	public :
		ShellMonster(const string& textureName) : WalkingMonster(textureName) { }

	private :
		void loadShellMonster();
	}

	class FlyingMonster : public Monster
	{
	public :
		FlyingMonster(const string& textureName) : Monster(textureName) { }

	private:
		void loadFlyingMonster();
	}
}

#endif
