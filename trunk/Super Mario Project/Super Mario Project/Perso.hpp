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

#include "EntityMovable.hpp"
#include "Animation.hpp"

namespace smp
{
	// forward declaration
	class Pipe;
	class Checkpoint;
	class MonsterOccurrence;
	class ProjectileOccurrence;
	class BlockOccurrence;
	class ItemOccurrence;
	class InputState;
	class HUD;
	
	class Perso : public EntityMovable
    {

	public:
		typedef enum Environment
		{
			GROUND,
			AIR,
			WATER
		} Environment;

		typedef enum 
		{
			STANDING,
			WALK,
			RUN_2,
			SKID,
			JUMP,
			JUMP_FALLING,
			FLY,
			GET_OUT_FROM_PIPE_VERTICAL,
			BACK,
			LOOK_TOP,
			LOWERED,
			CLIMB_LADDER,
			STANDING_SHELL,
			WALK_SHELL,
			PUSH_SHELL,
			JUMP_SHELL,
			LOWERED_SHELL,
			LOOK_TOP_SHELL,
			DEAD,
			FINISH,
			ATTACK,
			SPECIAL_ATTACK,
			NB_STATE_TEXTURE,
			LOWERED_JUMP_SHELL,
			LOWERED_JUMP,
			SIT_DOWN,
			SLIDE,
			GET_OUT_FROM_PIPE_HORIZONTAL,
			GET_IN_FROM_PIPE_HORIZONTAL,
			GET_IN_FROM_PIPE_VERTICAL,
			SWIMMING,
			NB_STATES,
			GO_TO_CASTLE,
			RUN_1 = WALK
		} State;

		typedef enum Sound {
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
		} Sound;

		typedef enum Transformation
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
		} Transformation;

		/* Constructors */
		Perso(const std::string& textureName, const sf::Vector2f& position);

		/* getters and setters */
		HUD* getHUD();
		State getState();
		Environment getEnvironment();
		Transformation getTransformation();
		bool getCanClimb();
		sf::Vector2f& getAcceleration();
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
		Animation<State>& getAnimation();

		void setState(State state);
		void setEnvironment(const Environment &environment);
		void setTransformation(const Transformation &transformation);
		void setCanClimb(bool canClimb);
		void setBroughtMonster(MonsterOccurrence* monster);
		void setInsidePipe(Pipe* pipe);

		void updatePerso(float time, InputState& inputState);

		/* Methods */
		void initPerso(const std::string& textureName);
		void updateGraphicData(sf::RenderWindow& app);
		void updatePhysicData(float time, sf::RenderWindow&);
		void render(sf::RenderWindow& app);

		void onCollision(Collisionable* c, int collision_type);

		/* Loading character configuration */
		void loadPerso(const std::string& textureName);

		/* Destructor */
        virtual ~Perso();
		
    private:
		bool _canClimb;
		PausableClock _invincibleTime;
		PausableClock _invincibleStarTime;
		PausableClock _transformationTime;
		PausableClock _attackTime;
		PausableClock _specialAttackTime;
		PausableClock _throwShellTime;
		PausableClock _deathTime;
		PausableClock _finishTime;
		std::string _textureName;
		PausableClock _jumpTime;

		Animation<State> _animation;
		HUD* _hud;
		State _state;
		Environment _environment;
		Transformation _transformation;
		sf::Vector2f _acceleration;
		MonsterOccurrence* _broughtMonster;
		Pipe* _insidePipe;
		Checkpoint* _checkpointPassed;

		/* Move management */
		void lateral_move(float time, InputState& inputState);

		/* Compute acceleration */
		void solve_acc(InputState& inputState);

		/* Compute jumping */
		void jump();

		/* Frictions management */
		void frictions(float time);

		/* Perso Hurted */
		void hurted();

		/* Transform */
		void transform(Transformation nextTransformation);

		/* Update character state when he is inside a pipe */
		void updateInPipe();

		/* Resolve Collisions */
		void onCollision(BlockOccurrence* blockOccurrence, int collision_type);
		void onCollision(MonsterOccurrence* monsteroccurrence, int collision_type);
		void onCollision(ItemOccurrence* itemOccurrence);
		void onCollision(ProjectileOccurrence* projectile);
		void onCollision(Pipe* pipe, int collision_type);

    };
} // namespace

#endif // HPP_PERSO
