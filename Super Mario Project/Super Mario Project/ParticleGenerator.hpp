////////////////////////////////////////////////////////////////////////
// ParticleGenerator.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_PARTICLEGENERATOR
#define HPP_PARTICLEGENERATOR

#include "Coord.hpp"
#include "Particle.hpp"
#include "Collisionable.hpp"
#include <SFML\Graphics.hpp>
#include <queue>

using namespace Utils;
using namespace sf;

namespace Collisions
{
    class ParticleGenerator : public Collisionable
    {
    public:
		/* Constructors */ 
		ParticleGenerator() : Collisionable(), _nbMaxParticles(0), _flow(0), _hasGravity(false), 
			_startColor(Color(0, 0, 0)), _endColor(Color(0, 0, 0)) { }
		ParticleGenerator(Coord<float> position, int nbMaxParticles, int flow, bool hasGravity, Color startColor, Color endColor) 
			: Collisionable(position), _nbMaxParticles(nbMaxParticles), _flow(flow), _hasGravity(hasGravity), _startColor(startColor), _endColor(endColor) { }

		/* getters and setters */
		Coord<int> getParticleSize();
		int getNbMaxParticles();
		int getFlow();
		bool getHasGravity();
		Color getStartColor();
		Color getEndColor();
		void setParticleSize(Coord<int>& particleSize);
		void setNbMaxParticles(int nbMaxParticles);
		void setFlow(int flow);
		void setHasGravity(bool hasGravity);
		void setStartColor(Color& startColor);
		void setEndColor(Color& endColor);

		/* Methods */
		void update(float time);
		void render();

		/* Destructor */
        virtual ~ParticleGenerator();
		
    private:
		Coord<int> _particleSize;
		queue<Particle> _particles;
		int _nbMaxParticles;
		int _flow;
		bool _hasGravity;
		Color _startColor;
		Color _endColor;
    };
} // namespace

#endif // HPP_PARTICLEGENERATOR
