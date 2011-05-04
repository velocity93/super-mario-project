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

#include "Particle.hpp"
#include "Collisionable.hpp"


namespace Collisions
{
    class ParticleGenerator : public Collisionable
    {
    public:
		/* Constructors */ 
		ParticleGenerator(const string& textureName) : Collisionable(textureName), _nbMaxParticles(0), _flow(0), _hasGravity(false), 
			_startColor(Color(0, 0, 0)), _endColor(Color(0, 0, 0)) { }
		ParticleGenerator(const string& textureName, Coord<float> position, int nbMaxParticles, int flow, bool hasGravity, Color startColor, Color endColor) 
			: Collisionable(textureName, position), _nbMaxParticles(nbMaxParticles), _flow(flow), _hasGravity(hasGravity), _startColor(startColor), _endColor(endColor) { }

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
		void render(RenderWindow& app);

		/* Destructor */
        virtual ~ParticleGenerator();
		
    private:
		Coord<int> _particleSize;
		vector<Particle> _particles;
		int _nbMaxParticles;
		int _flow;
		bool _hasGravity;
		Color _startColor;
		Color _endColor;
    };
} // namespace

#endif // HPP_PARTICLEGENERATOR
