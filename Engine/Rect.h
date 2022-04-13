#pragma once

#include "Vec2.h"

template<typename T>
class Rect_
{
public:
	Rect_() = default;
	Rect_(T left_in, T right_in, T top_in, T bottom_in)
		:
		left(left_in),
		right(right_in),
		top(top_in),
		bottom(bottom_in)
	{
	}

	Rect_(const Vei2& topLeft, const Vei2& bottomRight)
		:
		Rect_(topLeft.x, bottomRight.x, topLeft.y, bottomRight.y)
	{
	}

	Rect_(const Vei2& topLeft, int width, int height)
		:
		Rect_(topLeft, topLeft + Vei2(width, height))
	{
	}

	bool IsOverlappingWith(const Rect_& other) const
	{
		return right > other.left && left < other.right
			&& bottom > other.top && top < other.bottom;
	}

	bool IsContainedBy(const Rect_& other) const
	{
		return left >= other.left && right <= other.right &&
			top >= other.top && bottom <= other.bottom;
	}

	bool Contains(const Vei2& point) const
	{
		return point.x >= left && point.x < right&& point.y >= top && point.y < bottom;
	}

	Rect_ FromCenter(const Vei2& center, int halfWidth, int halfHeight)
	{
		const Vei2 half(halfWidth, halfHeight);
		return Rect_(center - half, center + half);
	}

	Rect_ GetExpanded(int offset) const
	{
		return Rect_(left - offset, right + offset, top - offset, bottom + offset);
	}

	Vei2 GetCenter() const
	{
		return Vei2((left + right) / 2, (top + bottom) / 2);
	}

	int GetWidth() const
	{
		return right - left;
	}

	int GetHeight() const
	{
		return bottom - top;
	}

public:
	T left;
	T right;
	T top;
	T bottom;
};

typedef Rect_<int> RectI;
typedef Rect_<float> RectF;