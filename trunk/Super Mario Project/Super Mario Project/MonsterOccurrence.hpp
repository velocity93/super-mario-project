////////////////////////////////////////////////////////////////////////
// MonsterOccurrence.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_MONSTEROCCURRENCE
#define HPP_MONSTEROCCURRENCE

#include "EntityMovable.hpp"
#include "Monster.hpp"

namespace Collisions
{
	class MonsterOccurrence : public EntityMovable
	{

	public:
		enum State 
		{
			M_WALK,
			M_RETRACTED,
			M_GET_OUT_FROM_SHELL,
			M_NB_TEXTURE_STATES,
			M_DEAD_BY_PROJ,
			M_DEAD,
			M_DEAD_BY_JUMP_ON,
			M_RETRACTED_REVERSED,
			M_RETRACTED_INCLINED,
			M_GET_OUT_FROM_PIPE
		};

		enum Sound
		{
			SND_JUMP_ON,
			SND_PROJ_ON,
			SND_LEVEL_ON,
			NB_M_SOUNDS
		};

	
		MonsterOccurrence();
		virtual ~MonsterOccurrence();

		void update(float time);
		void render(RenderWindow& app);

	private:
		Monster* _monster;
		State _state;
	};
} // namespace

#endif // HPP_MONSTEROCCURRENCE
