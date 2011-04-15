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
	class Perso : public EntityMovable
    {
		enum Environment
		{
			GROUND,
			AIR,
			WATER
		};

		enum State
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

		enum Sounds {
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

		enum Transformations
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


    public:
		/* Constructors */
		Perso() : EntityMovable(), _environment(GROUND), _transformation(SMALL_MARIO), _state(STANDING),
			_hud(HUD()), _canClimb(false), _acceleration(Vect<float>()), _invincibleTime(0), _invincibleStarTime(0),
			_transformationTime(0), _attackTime(0), _specialAttackTime(0), _throwShellTime(0), _deathTime(0), _finishTime(0),
			_jumpTime(0) { }
		Perso(Coord<float> Position) : EntityMovable(Position), _environment(GROUND), _transformation(SMALL_MARIO), _state(STANDING),
			_hud(HUD()), _canClimb(false), _acceleration(Vect<float>()), _invincibleTime(0), _invincibleStarTime(0),
			_transformationTime(0), _attackTime(0), _specialAttackTime(0), _throwShellTime(0), _deathTime(0), _finishTime(0),
			_jumpTime(0) { }

		/* getters and setters */
		HUD getHUD();
		State getState();
		Environment getEnvironment();
		Transformations getTransformation();
		bool getCanClimb();
		Vect<float> getAcceleration();
		MonsterOccurrence getBroughtMonster();
		Pipe getInsidePipe();
		Checkpoint getCheckPointPassed();
		int getInvincibleTime();
		int getInvincibleStarTime();
		int getTransformationTime();
		int getAttackTime();
		int getSpecialAttackTime();
		int getThrowShellTime();
		int getDeathTime();
		int getFinishTime();
		int getJumpTime();
		void setHUD(HUD& HUD);
		void setEnvironment(Environment environment);
		void setTransformation(Transformations transformation);
		void setCanClimb(bool canClimb);
		void setBroughtMonster(MonsterOccurrence& monster);
		void setInsidePipe(Pipe& pipe);
		void setCheckPointPassed(Checkpoint& checkpoint);
		void setInvincibleTime(int invincibleTime);
		void setInvincibleStarTime(int invincibleStarTime);
		void setTransformationTime(int transformationTime);
		void setAttackTime(int attackTime);
		void setSpecialAttackTime(int specialAttackTime);
		void setThrowShellTime(int throwShellTime);
		void setDeathTime(int deathTime);
		void setFinishTime(int finishTime);
		void setJumpTime(int jumpTime);

		/* Methods */
		void update(float time);
		void render();

		/* Destructor */
        ~Perso();
		
    private:
		HUD _hud;
		State _state;
		Environment _environment;
		Transformations _transformation;
		bool _canClimb;
		Vect<float> _acceleration;
		MonsterOccurrence _broughtMonster;
		Pipe _insidePipe;
		Checkpoint _checkpointPassed;
		//sounds
		int _invincibleTime;
		int _invincibleStarTime;
		int _transformationTime;
		int _attackTime;
		int _specialAttackTime;
		int _throwShellTime;
		int _deathTime;
		int _finishTime;
		int _jumpTime;
    };
} // namespace

#endif // HPP_PERSO
