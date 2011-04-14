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
    void Perso::Update(float time)
    {
		/* Save actual position as previous position */
		this->GetPreviousPosition().Set(this->GetPosition().GetX(), this->GetPosition().GetY());

    }

	void Perso::Render()
    {
    }


    Perso::~Perso()
    {
    }
} // namespace
