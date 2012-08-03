////////////////////////////////////////////////////////////////////////
// InverseRect.inl
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

template <typename T>
InverseRect<T>::InverseRect() :
left  (0),
bottom(0),
width (0),
height(0)
{

}

template <typename T>
InverseRect<T>::InverseRect(T rectLeft, T rectBottom, T rectWidth, T rectHeight) :
left  (rectLeft),
bottom(rectBottom),
width (rectWidth),
height(rectHeight)
{

}


template <typename T>
InverseRect<T>::InverseRect(const Vector2<T>& position, const Vector2<T>& size) :
left  (position.x),
bottom(position.y),
width (size.x),
height(size.y)
{

}

template <typename T>
template <typename U>
InverseRect<T>::InverseRect(const InverseRect<U>& rectangle) :
left  (static_cast<T>(rectangle.left)),
bottom(static_cast<T>(rectangle.bottom)),
width (static_cast<T>(rectangle.width)),
height(static_cast<T>(rectangle.height))
{
}


template <typename T>
bool InverseRect<T>::contains(T x, T y) const
{
    return (x >= left) && (x < left + width) && (y >= bottom) && (y < bottom + height);
}


template <typename T>
bool InverseRect<T>::contains(const Vector2<T>& point) const
{
    return contains(point.x, point.y);
}


template <typename T>
bool InverseRect<T>::intersects(const InverseRect<T>& rectangle) const
{
    InverseRect<T> intersection;
    return intersects(rectangle, intersection);
}


template <typename T>
bool InverseRect<T>::intersects(const InverseRect<T>& rectangle, InverseRect<T>& intersection) const
{
    // Compute the intersection boundaries
    T interLeft   = std::max(left,         rectangle.left);
    T interBottom = std::max(bottom,       rectangle.bottom);
    T interRight  = std::min(left + width, rectangle.left + rectangle.width);
    T interTop	  = std::min(bottom + height, rectangle.bottom + rectangle.height);

    // If the intersection is valid (positive non zero area), then there is an intersection
    if ((interLeft < interRight) && (interBottom < interTop))
    {
        intersection = InverseRect<T>(interLeft, interBottom, interRight - interLeft, interTop - interBottom);
        return true;
    }
    else
    {
        intersection = InverseRect<T>(0, 0, 0, 0);
        return false;
    }
}


template <typename T>
inline bool operator ==(const InverseRect<T>& left, const InverseRect<T>& right)
{
    return (left.left == right.left) && (left.width == right.width) &&
           (left.bottom == right.bottom) && (left.height == right.height);
}


template <typename T>
inline bool operator !=(const InverseRect<T>& left, const InverseRect<T>& right)
{
    return !(left == right);
}