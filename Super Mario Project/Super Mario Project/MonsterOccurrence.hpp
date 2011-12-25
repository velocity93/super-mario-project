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
#include "Animation.hpp"

#define MONSTER_EXIT_SPEED			0.05F
#define M_SPEED_WALK_MIN			0.008F

namespace Collisions
{
	class Monster;
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
			M_RETRACTED_INCLINED, // monster brought
			M_GET_OUT_FROM_PIPE,
			M_NB_STATES
		};

		enum Sound
		{
			SND_JUMP_ON,
			SND_PROJ_ON,
			SND_LEVEL_ON,
			NB_M_SOUNDS
		};

		MonsterOccurrence(
			const string& textureName, 
			Vector2f& position,
			Vector2f& speed,
			MonsterOccurrence::State state,
			MonsterOccurrence::Side side,
			map<MonsterOccurrence::State, int>& nbSpritesByState,
			map<MonsterOccurrence::State, int>& frameDelayByState);

		State getState();
		void setState(State state);

		void update(RenderWindow& app);
		void render(RenderWindow& app);

		virtual ~MonsterOccurrence();

	private:
		Animation<State> _animation;
		Monster* _monster;
		Vector2f _initialPosition;
		State _state;

		void setActivity(RenderWindow& app);
	};
} // namespace

#endif // HPP_MONSTEROCCURRENCE
