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

namespace Collisions
{
	class Monster;
	class Perso;
	class Pipe;
	class BlockOccurrence;
	class ProjectileOccurrence;
	class MonsterOccurrence : public EntityMovable
	{

	public:
		enum State 
		{
			WALK,
			DEAD_BY_JUMP_ON,
			DEAD_BY_PROJ,
			RETRACTED,
			GET_OUT_FROM_SHELL,
			NB_TEXTURE_STATES,
			DEAD,
			RETRACTED_REVERSED,
			RETRACTED_INCLINED, // monster brought
			GET_OUT_FROM_PIPE,
			NB_STATES
		};

		enum Sound
		{
			SND_JUMP_ON,
			SND_PROJ_ON,
			SND_LEVEL_ON,
			NB_M_SOUNDS
		};

		MonsterOccurrence(
			Monster* monster,
			const string& textureName, 
			const Vector2f& position,
			const Vector2f& speed,
			MonsterOccurrence::State state,
			MonsterOccurrence::Side side,
			map<MonsterOccurrence::State, int>& nbSpritesByState,
			map<MonsterOccurrence::State, int>& frameDelayByState);

		State getState();
		void setState(State state);
		Monster* getModel();
		void onCollision(Collisionable* c, int collision_type);

		void updateGraphicData(RenderWindow& app);
		void updatePhysicData(float time, RenderWindow& app);
		void render(RenderWindow& app);

		void setActivity(RenderWindow& app);

		virtual ~MonsterOccurrence();

	private:
		Animation<State> _animation;
		Monster* _monster;
		Vector2f _initialPosition;
		State _state;

		/* Collisions resolutions */
		void onCollision(Perso* perso, int collision_type);
		void onCollision(Pipe* pipe, int collision_type);
		void onCollision(ProjectileOccurrence* projectileOccurrence);
		void onCollision(BlockOccurrence* block, int collision_type);
		void onCollision(MonsterOccurrence* monsterOccurrence, int collision_type);
	};
} // namespace

#endif // HPP_MONSTEROCCURRENCE
