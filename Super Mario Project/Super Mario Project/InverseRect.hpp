////////////////////////////////////////////////////////////////////////
// InverseRect.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_INVERSE_RECT
#define HPP_INVERSE_RECT

namespace SuperMarioProject
{

	template <typename T>
	class InverseRect
	{
	public :

		InverseRect();

		InverseRect(T rectLeft, T rectBottom, T rectWidth, T rectHeight);

		InverseRect(const Vector2<T>& position, const Vector2<T>& size);

		template <typename U>
		explicit InverseRect(const InverseRect<U>& rectangle);

		bool contains(T x, T y) const;

		bool contains(const Vector2<T>& point) const;


		bool intersects(const InverseRect<T>& rectangle) const;


		bool intersects(const InverseRect<T>& rectangle, InverseRect<T>& intersection) const;

		////////////////////////////////////////////////////////////
		// Member data
		////////////////////////////////////////////////////////////
		T left;   ///< Left coordinate of the rectangle
		T bottom;    ///< Bottom coordinate of the rectangle
		T width;  ///< Width of the rectangle
		T height; ///< Height of the rectangle
	};

	template <typename T>
	bool operator ==(const InverseRect<T>& left, const InverseRect<T>& right);

	template <typename T>
	bool operator !=(const InverseRect<T>& left, const InverseRect<T>& right);

	#include "InverseRect.inl"

	// Create typedefs for the most common types
	typedef InverseRect<int>   InverseIntRect;
	typedef InverseRect<float> InverseFloatRect;

}
#endif