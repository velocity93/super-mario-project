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
    class ParticleGenerator : Collisionable
    {
    public:
		ParticleGenerator() : Collisionable(), nbMaxParticles(0), flow(0), hasGravity(false), 
			startColor(Color(0, 0, 0)), endColor(Color(0, 0, 0)) { }
		ParticleGenerator(Coord<float> Position, int NbMaxParticles, int Flow, bool HasGravity, Color StartColor, Color EndColor) 
			: Collisionable(Position), nbMaxParticles(NbMaxParticles), flow(Flow), hasGravity(HasGravity), startColor(StartColor), endColor(EndColor) { }

		Coord<int> GetParticleSize()
		{
			return particleSize;
		}

		int GetNbMaxParticles()
		{
			return nbMaxParticles;
		}

		int GetFlow()
		{
			return flow;
		}

		bool GetHasGravity()
		{
			return hasGravity;
		}

		Color GetStartColor()
		{
			return startColor;
		}

		Color GetEndColor()
		{
			return endColor;
		}

		void SetParticleSize(Coord<int> ParticleSize)
		{
			particleSize= ParticleSize;
		}

		void SetNbMaxParticles(int NbMaxParticles)
		{
			nbMaxParticles = NbMaxParticles;
		}

		void SetFlow(int Flow)
		{
			flow = Flow;
		}

		void SetHasGravity(bool HasGravity)
		{
			hasGravity = HasGravity;
		}

		void SetStartColor(Color StartColor)
		{
			startColor = StartColor;
		}

		void SetEndColor(Color EndColor)
		{
			endColor = EndColor;
		}

		void Update();
		void Render();
        ~ParticleGenerator();
		
    private:
		Coord<int> particleSize;
		//queue<Particle> particles;
		int nbMaxParticles;
		int flow;
		bool hasGravity;
		Color startColor;
		Color endColor;
    };
} // namespace

#endif // HPP_PARTICLEGENERATOR
