#pragma once

#include <cmath>

template<typename T>
class Vec2_
{
public:
	Vec2_() = default;

	Vec2_(T x_in, T y_in)
		:
		x(x_in),
		y(y_in)
	{
	}

	Vec2_ operator+(const Vec2_& rhs) const
	{
		return Vec2_(x + rhs.x, y + rhs.y);
	}

	Vec2_& operator+=(const Vec2_& rhs)
	{
		return *this = *this + rhs;
	}

	Vec2_ operator*(float rhs) const
	{
		return Vec2_(x * rhs, y * rhs);
	}

	Vec2_& operator*=(float rhs)
	{
		return *this = *this * rhs;
	}

	Vec2_ operator-(const Vec2_& rhs) const
	{
		return Vec2_(x - rhs.x, y - rhs.y);
	}

	Vec2_& operator-=(const Vec2_& rhs)
	{
		return *this = *this - rhs;
	}

	float GetLength() const
	{
		return std::sqrt(GetLengthSq());
	}

	float GetLengthSq() const
	{
		return x * x + y * y;
	}

	Vec2_& Normalize()
	{
		return *this = GetNormalized();
	}

	Vec2_ GetNormalized() const
	{
		const float len = GetLength();
		if (len != 0.0f)
		{
			return *this * (1.0f / len);
		}
		return *this;
	}
	template<typename S>
	explicit operator Vec2_<S>() const
	{
		return{ (S)x,(S)y };
	}

public:
	T x;
	T y;
};

typedef Vec2_<int> Vei2;

typedef Vec2_<float> Vec2;