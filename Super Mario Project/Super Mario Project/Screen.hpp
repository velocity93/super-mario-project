////////////////////////////////////////////////////////////////////////
// Screen.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_SCREEN
#define HPP_SCREEN

#include "Coord.hpp"

using namespace Utils;

namespace Rendering
{
    class Screen
    {
    public:
		Screen() : origine(Coord<int>()), size(Coord<int>()), scrolling(Coord<float>()) { }
		Screen(Coord<int> Origine, Coord<int> Size, Coord<float> Scrolling) : origine(Origine), size(Size), scrolling(Scrolling) { }
        Coord<int> GetOrigine()
		{
			return origine;
		}

		Coord<int> GetSize()
		{
			return size;
		}

		Coord<float> GetScrolling()
		{
			return scrolling;
		}

		void SetOrigine(Coord<int> Origine)
		{
			origine = Origine;
		}

		void SetSize(Coord<int> Size)
		{
			size = Size;
		}

		void SetScrolling(Coord<float> Scrolling)
		{
			scrolling = Scrolling;
		}

		
    private:
		Coord<int> origine;
		Coord<int> size;
		Coord<float> scrolling;
    };
} // namespace

#endif // HPP_SCREEN
