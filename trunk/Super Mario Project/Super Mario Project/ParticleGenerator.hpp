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
		ParticleGenerator(const string& textureName) : Collisionable(textureName), _flow(0), _hasGravity(false), 
			_startColor(Color(0, 0, 0)), _endColor(Color(0, 0, 0)) , _particleLife(0), _nbMaxParticles((_particleLife / 1000) * _flow + 1),
			_eTBeforeCreatingParticles(0) { }
		ParticleGenerator(const string& textureName,Vector2f position, int particleLife, int flow, bool hasGravity, Color startColor, Color endColor) 
			: Collisionable(textureName, position), _flow(flow), _hasGravity(hasGravity), _startColor(startColor), _endColor(endColor), _particleLife(particleLife),
			_eTBeforeCreatingParticles(0), _nbMaxParticles((_particleLife / 1000) * _flow + 1) { }

		/* getters and setters */
		Vector2i& getParticleSize();
		int getNbMaxParticles();
		int getFlow();
		bool getHasGravity();
		Color& getStartColor();
		Color& getEndColor();
		void setParticleSize(Vector2i& particleSize);
		void setNbMaxParticles(int nbMaxParticles);
		void setFlow(int flow);
		void setHasGravity(bool hasGravity);
		void setStartColor(Color& startColor);
		void setEndColor(Color& endColor);

		/* Methods */
		void updateGraphicData(RenderWindow& app);
		void render(RenderWindow& app);

		/* Destructor */
        virtual ~ParticleGenerator();
		
    private:
		Vector2i _particleSize;
		vector<Particle> _particles;
		int _particleLife;
		int _nbMaxParticles;
		int _eTBeforeCreatingParticles;
		int _flow;
		bool _hasGravity;
		Color _startColor;
		Color _endColor;
    };
} // namespace

#endif // HPP_PARTICLEGENERATOR
