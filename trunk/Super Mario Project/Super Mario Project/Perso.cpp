////////////////////////////////////////////////////////////////////////
// Perso.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "Perso.hpp"

namespace Collisions
{
	HUD Perso::getHUD()
	{
		return _hud;
	}

	Perso::Environment Perso::getEnvironment()
	{
		return _environment;
	}

	Perso::Transformations Perso::getTransformation()
	{
		return _transformation;
	}

	bool Perso::getCanClimb()
	{
		return _canClimb;
	}

	Vect<float> Perso::getAcceleration()
	{
		return _acceleration;
	}

	MonsterOccurrence Perso::getBroughtMonster()
	{
		return _broughtMonster;
	}

	Pipe Perso::getInsidePipe()
	{
		return _insidePipe;
	}

	Checkpoint Perso::getCheckPointPassed()
	{
		return _checkpointPassed;
	}

	int Perso::getInvincibleTime()
	{
		return _invincibleTime;
	}

	int Perso::getInvincibleStarTime()
	{
		return _invincibleStarTime;
	}

	int Perso::getTransformationTime()
	{
		return _transformationTime;
	}

	int Perso::getAttackTime()
	{
		return _attackTime;
	}

	int Perso::getSpecialAttackTime()
	{
		return _specialAttackTime;
	}

	int Perso::getThrowShellTime()
	{
		return _throwShellTime;
	}

	int Perso::getDeathTime()
	{
		return _deathTime;
	}

	int Perso::getFinishTime()
	{
		return _finishTime;
	}

	int Perso::getJumpTime()
	{
		return _jumpTime;
	}

	void Perso::setHUD(HUD& hud)
	{
		_hud = hud;
	}

	void Perso::setEnvironment(Environment environment)
	{
		_environment = environment;
	}

	void Perso::setTransformation(Transformations transformation)
	{
		_transformation = transformation;
	}

	void Perso::setCanClimb(bool canClimb)
	{
		_canClimb = canClimb;
	}

	void Perso::setBroughtMonster(MonsterOccurrence& monster)
	{
		_broughtMonster = monster;
	}

	void Perso::setInsidePipe(Pipe& pipe)
	{
		_insidePipe = pipe;
	}

	void Perso::setCheckPointPassed(Checkpoint& checkpoint)
	{
		_checkpointPassed = checkpoint;
	}

	void Perso::setInvincibleTime(int invincibleTime)
	{
		_invincibleTime = invincibleTime;
	}

	void Perso::setInvincibleStarTime(int invincibleStarTime)
	{
		_invincibleStarTime = invincibleStarTime;
	}

	void Perso::setTransformationTime(int transformationTime)
	{
		_transformationTime = transformationTime;
	}

	void Perso::setAttackTime(int attackTime)
	{
		_attackTime = attackTime;
	}

	void Perso::setSpecialAttackTime(int specialAttackTime)
	{
		_specialAttackTime = specialAttackTime;
	}

	void Perso::setThrowShellTime(int throwShellTime)
	{
		_throwShellTime = throwShellTime;
	}

	void Perso::setDeathTime(int deathTime)
	{
		_deathTime = deathTime;
	}

	void Perso::setFinishTime(int finishTime)
	{
		_finishTime = finishTime;
	}

	void Perso::setJumpTime(int jumpTime)
	{
		_jumpTime = jumpTime;
	}


	void Perso::update(float time)
	{
		/* Save actual position as previous position */
		this->Perso::getPreviousPosition().set(this->Perso::getPosition().getX(), this->Perso::getPosition().getY());

	}

	void Perso::render()
	{
	}


	Perso::~Perso()
	{
	}
} // namespace
