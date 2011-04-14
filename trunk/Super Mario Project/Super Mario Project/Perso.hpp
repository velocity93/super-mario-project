////////////////////////////////////////////////////////////////////////
// Perso.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_PERSO
#define HPP_PERSO

#include "HUD.hpp"
#include "EntityMovable.hpp"
#include "MonsterOccurrence.hpp"
#include "Pipe.hpp"
#include "Checkpoint.hpp"

using namespace Rendering;

namespace Collisions
{
	enum Environment
	{
		GROUND,
		AIR,
		WATER
	};

	enum Perso_State
	{
		WALK,
		RUN_2,
		JUMP,
		STANDING,
		CLIMB_LADDER,
		WALK_SHELL,
		PUSH_SHELL,
		ATTACK,
		SPECIAL_ATTACK,
		NB_STATE_TEXTURE, // Nombre d'états max en hauteur pour la texture du personnage
		STANDING_SHELL,
		JUMP_SHELL,
		LOWERED_SHELL,
		LOWERED_JUMP_SHELL,
		LOOK_TOP,
		LOOK_TOP_SHELL,
		LOWERED,
		LOWERED_JUMP,
		SIT_DOWN,
		SAUT_DESCENDANT,
		RUN_1,
		SKID,
		SLIDE,
		DEAD,
		GET_OUT_FROM_PIPE_HORIZONTAL,
		GET_IN_FROM_PIPE_HORIZONTAL,
		GET_OUT_FROM_PIPE_VERTICAL,
		GET_IN_FROM_PIPE_VERTICAL,
		FINISH,
		FINISH_CASTLE,
		NB_STATE
	};

	enum Perso_sounds {
		SND_JUMP,
		SND_HURT,
		SND_FIRE_TRANSFORMATION,
		SND_LIFE,
		SND_FIREBALL,
		SND_THUNDER_BALL,
		SND_SKID,
		SND_COIN,
		SND_BREAK_BLOCK,
		SND_ITEM_BLOCK,
		SND_UNBREAKABLE_BLOCK, 
		SND_INVINCIBLE,
		SND_DIE,
		SND_PIPE,
		SND_CLEAR,
		SND_CHECKPOINT,
		SND_FINAL_POINTS,
		NB_SONS
	};

	enum Perso_transformations
	{
		MINI_MARIO,
		SMALL_MARIO,
		SUPER_MARIO,
		FIRE_MARIO,
		ICE_MARIO,
		ELECTRIC_MARIO,
		WAR_MARIO,
		SHELL_MARIO,
		SUPER_FIRE_MARIO,
		NINJA_MARIO,
		NB_TRANSFORMATIONS
	};

	class Perso : EntityMovable
    {
    public:
		/* Constructors */
		Perso() : EntityMovable(), environment(GROUND), transformation(SMALL_MARIO),
			hud(HUD()), canClimb(false), acceleration(Vect<float>()), invincibleTime(0), invincibleStarTime(0),
			transformationTime(0), attackTime(0), specialAttackTime(0), throwShellTime(0), deathTime(0), finishTime(0),
			jumpTime(0) { }
		Perso(Coord<float> Position) : EntityMovable(Position), environment(GROUND), transformation(SMALL_MARIO),
			hud(HUD()), canClimb(false), acceleration(Vect<float>()), invincibleTime(0), invincibleStarTime(0),
			transformationTime(0), attackTime(0), specialAttackTime(0), throwShellTime(0), deathTime(0), finishTime(0),
			jumpTime(0) { }

		/* Getters and setters */
		HUD GetHUD()
		{
			return hud;
		}

		Environment GetEnvironment()
		{
			return environment;
		}

		Perso_transformations GetTransformation()
		{
			return transformation;
		}

		bool GetCanClimb()
		{
			return canClimb;
		}

		Vect<float> GetAcceleration()
		{
			return acceleration;
		}

		MonsterOccurrence GetBroughtMonster()
		{
			return broughtMonster;
		}

		Pipe GetInsidePipe()
		{
			return insidePipe;
		}

		Checkpoint GetCheckPointPassed()
		{
			return checkpointPassed;
		}

		int GetInvincibleTime()
		{
			return invincibleTime;
		}

		int GetInvincibleStarTime()
		{
			return invincibleStarTime;
		}

		int GetTransformationTime()
		{
			return transformationTime;
		}

		int GetAttackTime()
		{
			return attackTime;
		}

		int GetSpecialAttackTime()
		{
			return specialAttackTime;
		}

		int GetThrowShellTime()
		{
			return throwShellTime;
		}

		int GetDeathTime()
		{
			return deathTime;
		}

		int GetFinishTime()
		{
			return finishTime;
		}

		int GetJumpTime()
		{
			return jumpTime;
		}

		void SetHUD(HUD HUD)
		{
			hud = HUD;
		}

		void SetEnvironment(Environment Environment)
		{
			environment = Environment;
		}

		void SetTransformation(Perso_transformations Transformation)
		{
			transformation = Transformation;
		}

		void SetCanClimb(bool CanClimb)
		{
			canClimb = CanClimb;
		}

		void SetBroughtMonster(MonsterOccurrence Monster)
		{
			broughtMonster = Monster;
		}

		void SetInsidePipe(Pipe Pipe)
		{
			insidePipe = Pipe;
		}

		void SetCheckPointPassed(Checkpoint Checkpoint)
		{
			checkpointPassed = Checkpoint;
		}

		void SetInvincibleTime(int InvincibleTime)
		{
			invincibleTime = InvincibleTime;
		}

		void SetInvincibleStarTime(int InvincibleStarTime)
		{
			invincibleStarTime = InvincibleStarTime;
		}

		void SetTransformationTime(int TransformationTime)
		{
			transformationTime = TransformationTime;
		}

		void SetAttackTime(int AttackTime)
		{
			attackTime = AttackTime;
		}

		void SetSpecialAttackTime(int SpecialAttackTime)
		{
			specialAttackTime = SpecialAttackTime;
		}

		void SetThrowShellTime(int ThrowShellTime)
		{
			throwShellTime = ThrowShellTime;
		}

		void SetDeathTime(int DeathTime)
		{
			deathTime = DeathTime;
		}

		void SetFinishTime(int FinishTime)
		{
			finishTime = FinishTime;
		}

		void SetJumpTime(int JumpTime)
		{
			jumpTime = JumpTime;
		}

		/* Methods */
		void Update(float time);
		void Render();

		/* Destructor */
        ~Perso();
		
    private:
		HUD hud;
		Environment environment;
		Perso_transformations transformation;
		bool canClimb;
		Vect<float> acceleration;
		MonsterOccurrence broughtMonster;
		Pipe insidePipe;
		Checkpoint checkpointPassed;
		//sounds
		int invincibleTime;
		int invincibleStarTime;
		int transformationTime;
		int attackTime;
		int specialAttackTime;
		int throwShellTime;
		int deathTime;
		int finishTime;
		int jumpTime;
    };
} // namespace

#endif // HPP_PERSO
