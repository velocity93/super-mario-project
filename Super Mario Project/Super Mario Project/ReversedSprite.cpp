////////////////////////////////////////////////////////////////////////
// ReversedSprite.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#include "ReversedSprite.hpp"

namespace Rendering 
{
    ReversedSprite::ReversedSprite()
        : Sprite(),
        _flippedX(false),
        _flippedY(false)
    {
    }


    ReversedSprite::ReversedSprite(const sf::Image& Img, 
        const sf::Vector2f& Position, 
        const sf::Vector2f& Scale, 
        float Rotation, 
        const sf::Color& Col)
        :Sprite(Img, Position, Scale, Rotation, Col)
    {
    }


    void ReversedSprite::FlipX(bool Flipped)
    {
        _flippedX = Flipped;
        Sprite::FlipX(Flipped);
    }
        
    
    void ReversedSprite::FlipY(bool Flipped)
    {
        _flippedY = Flipped;
        Sprite::FlipY(Flipped);
    }


    void ReversedSprite::Render(sf::RenderTarget&) const
    {
        // Get the sprite size
        float Width  = static_cast<float>(GetSubRect().GetWidth());
        float Height = static_cast<float>(GetSubRect().GetHeight());

        // Check if the image is valid
        if (GetImage() && (GetImage()->GetWidth() > 0) && (GetImage()->GetHeight() > 0))
        {
            // Use the "offset trick" to get pixel-perfect rendering
            // see http://www.opengl.org/resources/faq/technical/transformations.htm#tran0030
            glTranslatef(0.375f, 0.375f, 0.f);

            // Bind the texture
            GetImage()->Bind();

            // Calculate the texture coordinates
            sf::FloatRect TexCoords = GetImage()->GetTexCoords(GetSubRect());
            sf::FloatRect Rect(_flippedX ? TexCoords.Right  : TexCoords.Left,
                _flippedY ? TexCoords.Bottom : TexCoords.Top,
                _flippedX ? TexCoords.Left   : TexCoords.Right,
                _flippedY ? TexCoords.Top    : TexCoords.Bottom);

            // Draw the sprite's triangles
            glBegin(GL_QUADS);
            glTexCoord2f(Rect.Left,  Rect.Top);    glVertex2f(0,     0);
            glTexCoord2f(Rect.Left,  Rect.Bottom); glVertex2f(0,     Height);
            glTexCoord2f(Rect.Right, Rect.Bottom); glVertex2f(Width, Height);
            glTexCoord2f(Rect.Right, Rect.Top);    glVertex2f(Width, 0) ;
            glEnd();
        }
        else
        {
            // Disable texturing
            glDisable(GL_TEXTURE_2D);

            // Draw the sprite's triangles
            glBegin(GL_QUADS);
            glVertex2f(0,     0);
            glVertex2f(0,     Height);
            glVertex2f(Width, Height);
            glVertex2f(Width, 0);
            glEnd();
        }
    }
}
