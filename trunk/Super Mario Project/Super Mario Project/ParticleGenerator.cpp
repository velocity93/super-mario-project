////////////////////////////////////////////////////////////////////////
// ParticleGenerator.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ParticleGenerator.hpp"

namespace Collisions
{
	Coord<int> ParticleGenerator::getParticleSize()
	{
		return _particleSize;
	}

	int ParticleGenerator::getNbMaxParticles()
	{
		return _nbMaxParticles;
	}

	int ParticleGenerator::getFlow()
	{
		return _flow;
	}

	bool ParticleGenerator::getHasGravity()
	{
		return _hasGravity;
	}

	Color ParticleGenerator::getStartColor()
	{
		return _startColor;
	}

	Color ParticleGenerator::getEndColor()
	{
		return _endColor;
	}

	void ParticleGenerator::setParticleSize(Coord<int>& particleSize)
	{
		_particleSize= particleSize;
	}

	void ParticleGenerator::setNbMaxParticles(int nbMaxParticles)
	{
		_nbMaxParticles = nbMaxParticles;
	}

	void ParticleGenerator::setFlow(int flow)
	{
		_flow = flow;
	}

	void ParticleGenerator::setHasGravity(bool hasGravity)
	{
		_hasGravity = hasGravity;
	}

	void ParticleGenerator::setStartColor(Color& startColor)
	{
		_startColor = startColor;
	}

	void ParticleGenerator::setEndColor(Color& endColor)
	{
		_endColor = endColor;
	}

	void ParticleGenerator::update(float time)
	{
	}

	void ParticleGenerator::render()
	{
	}

	ParticleGenerator::~ParticleGenerator()
	{
	}
} // namespace
