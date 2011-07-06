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

/* Physic constant */
#define SPEED_X_MIN						0.008F

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

	public:
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
			STANDING_SHELL,
			JUMP_SHELL,
			LOWERED_SHELL,
			LOWERED_JUMP_SHELL,
			LOOK_TOP,
			LOOK_TOP_SHELL,
			LOWERED,
			LOWERED_JUMP,
			SIT_DOWN,
			JUMP_FALLING,
			RUN_1,
			SKID,
			SLIDE,
			DEAD,
			GET_OUT_FROM_PIPE_HORIZONTAL,
			GET_IN_FROM_PIPE_HORIZONTAL,
			GET_OUT_FROM_PIPE_VERTICAL,
			GET_IN_FROM_PIPE_VERTICAL,
			BACK,
			FINISH,
			FINISH_CASTLE,
			SWIMMING,
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

		/* Constructors */
		Perso(const string& textureName, Vector2f& position);

		/* getters and setters */
		HUD* getHUD();
		State getState();
		Environment getEnvironment();
		Transformations getTransformation();
		bool getCanClimb();
		Vector2f getAcceleration();
		MonsterOccurrence* getBroughtMonster();
		Pipe* getInsidePipe();
		Checkpoint* getCheckPointPassed();
		int getInvincibleTime();
		int getInvincibleStarTime();
		int getTransformationTime();
		int getAttackTime();
		int getSpecialAttackTime();
		int getThrowShellTime();
		int getDeathTime();
		int getFinishTime();
		int getJumpTime();
		void setState(State state);
		void setEnvironment(const Environment &environment);
		void setTransformation(const Transformations &transformation);
		void setCanClimb(bool canClimb);
		void setBroughtMonster(MonsterOccurrence* monster);
		void setInsidePipe(Pipe* pipe);
		void setCheckPointPassed(Checkpoint* checkpoint);
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
		void update(const RenderWindow& app);
		void render(const RenderWindow& app);

		/* Loading character configuration */
		void loadPerso(const string& textureName);

		/* Destructor */
        virtual ~Perso();
		
    private:
		HUD* _hud;
		State _state;
		Environment _environment;
		Transformations _transformation;
		bool _canClimb;
		Vector2f _acceleration;
		MonsterOccurrence* _broughtMonster;
		Pipe* _insidePipe;
		Checkpoint* _checkpointPassed;
		int _invincibleTime;
		int _invincibleStarTime;
		int _transformationTime;
		int _attackTime;
		int _specialAttackTime;
		int _throwShellTime;
		int _deathTime;
		int _finishTime;
		int _jumpTime;
		map<Perso::State, int> _nbSpritesByState;
		map<Perso::State, int> _vAnimByState;

		/* Move management */
		void lateral_move(const RenderWindow& app);

		/* Frictions management */
		void frictions(float time);

		/* Perso Hurted */
		void hurted();

		/* Transform */
		void transform(Transformations nextTransformation);

		/* Update character state when he is inside a pipe */
		void updateInPipe();

    };
} // namespace

#endif // HPP_PERSO
