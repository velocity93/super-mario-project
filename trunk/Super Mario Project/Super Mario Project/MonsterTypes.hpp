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
		WalkingMonster(const std::string& textureName);

		void serialize(std::ofstream& file, std::string& tabs);
	};

	class ShellMonster : public WalkingMonster
	{

	public :
		ShellMonster(const std::string& textureName);

		void serialize(std::ofstream& file, std::string& tabs);
	};

	class FlyingMonster : public Monster
	{
	public :
		FlyingMonster(const std::string& textureName);

		void serialize(std::ofstream& file, std::string& tabs);
	};
}
#endif
