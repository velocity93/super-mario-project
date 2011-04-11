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

	enum Perso_side {
		LEFT_SIDE,
		RIGHT_SIDE,
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

    class Perso
    {
    public:
        Perso();
        ~Perso();
		
    private:
    };
} // namespace

#endif // HPP_PERSO
