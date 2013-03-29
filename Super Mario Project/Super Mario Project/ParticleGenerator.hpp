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


namespace smp
{
    class ParticleGenerator : public Collisionable
    {
    public:
		/* Constructors */ 
		ParticleGenerator(const std::string& textureName) : Collisionable(textureName), _flow(0), _hasGravity(false), 
			_startColor(sf::Color(0, 0, 0)), _endColor(sf::Color(0, 0, 0)) , _particleLife(0), _nbMaxParticles((_particleLife / 1000) * _flow + 1),
			_eTBeforeCreatingParticles(0) { }
		ParticleGenerator(const std::string& textureName, sf::Vector2f position, int particleLife, int flow, bool hasGravity, sf::Color startColor, sf::Color endColor) 
			: Collisionable(textureName, position), _flow(flow), _hasGravity(hasGravity), _startColor(startColor), _endColor(endColor), _particleLife(particleLife),
			_eTBeforeCreatingParticles(0), _nbMaxParticles((_particleLife / 1000) * _flow + 1) { }

		/* getters and setters */
		sf::Vector2i& getParticleSize();
		int getNbMaxParticles();
		int getFlow();
		bool getHasGravity();
		sf::Color& getStartColor();
		sf::Color& getEndColor();
		void setParticleSize(sf::Vector2i& particleSize);
		void setNbMaxParticles(int nbMaxParticles);
		void setFlow(int flow);
		void setHasGravity(bool hasGravity);
		void setStartColor(sf::Color& startColor);
		void setEndColor(sf::Color& endColor);

		/* Methods */
		void updateGraphicData(sf::RenderWindow& app);
		void render(sf::RenderWindow& app);

		/* Destructor */
        virtual ~ParticleGenerator();
		
    private:
		sf::Vector2i _particleSize;
		std::vector<Particle> _particles;
		int _particleLife;
		int _nbMaxParticles;
		int _eTBeforeCreatingParticles;
		int _flow;
		bool _hasGravity;
		sf::Color _startColor;
		sf::Color _endColor;
    };
} // namespace

#endif // HPP_PARTICLEGENERATOR
