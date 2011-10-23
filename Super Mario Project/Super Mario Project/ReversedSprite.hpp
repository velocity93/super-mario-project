////////////////////////////////////////////////////////////////////////
// ReversedSprite.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_REVERSED_SPRITE
#define HPP_REVERSED_SPRITE

#include <SFML/Graphics.hpp>

namespace Rendering {

    class ReversedSprite : public sf::Sprite
    {
    public:
        ReversedSprite();
        explicit ReversedSprite(const sf::Image& Img, 
            const sf::Vector2f& Position = sf::Vector2f(0, 0), 
            const sf::Vector2f& Scale = sf::Vector2f(1, 1), 
            float Rotation = 0.f, 
            const sf::Color& Col = sf::Color(255, 255, 255, 255));

        void Render(sf::RenderTarget&) const;
		void Render(sf::RenderTarget& target, sf::View& view);
        void FlipX(bool Flipped);
        void FlipY(bool Flipped);

        static void setWindowsHeight(int winHeight);

    private:
        bool _flippedX;
        bool _flippedY;

        static int _winHeight;
    };
}

#endif
