////////////////////////////////////////////////////////////////////////
// Drawable.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_DRAWABLE
#define HPP_DRAWABLE

#include "Texture.hpp"
#include <vector>

using namespace std;

namespace Rendering
{

	enum Layer
	{
		BACKGROUND_LAYER,
		BACKGROUND_PARTICLES_LAYER,
		OBJECTS_LAYER,
		BLOC_LAYER_1,
		ITEM_LAYER,
		BLOC_LAYER_2,
		FOREGROUND_LAYER,
		FOREGROUND_PARTICLES_LAYER
	};

	enum Angle
	{
		ANGLE_0,
		ANGLE_90,
		ANGLE_180,
		ANGLE_270
	};

    class Drawable
    {
    public:
		Drawable() : texture(Texture()), spriteNumbers(vector<int>()), animationSpeeds(vector<int>()) { }
		Texture GetTexture()
		{
			return texture;
		}

		vector<int> GetSpriteNumbers()
		{
			return spriteNumbers;
		}

		vector<int> GetAnimationSpeeds()
		{
			return animationSpeeds;
		}

		void SetTexture(Texture Texture)
		{
			texture = Texture;
		}

		void GetSpriteNumbers(vector<int> SpriteNumbers)
		{
			spriteNumbers = SpriteNumbers;
		}

		void GetAnimationSpeeds(vector<int> AnimationSpeeds)
		{
			animationSpeeds = AnimationSpeeds;
		}

		/* It will be defined in subclasses */
		/* Update drawable object context */
		virtual void Update() { }

		/* Draw actual object state */
		virtual void Render() { }
        ~Drawable();
		
    private:
		Texture texture;
		vector<int> spriteNumbers;
		vector<int> animationSpeeds;
    };
} // namespace

#endif // HPP_DRAWABLE
