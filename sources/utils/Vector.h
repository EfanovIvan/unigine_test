#ifndef __VECTOR2D_H__
#define __VECTOR2D_H__

#include <cmath>

class Vector2d {
public:
	float x, y;
	Vector2d() : x(0.0f), y(0.0f) {};
	Vector2d(float f) : x(f), y(f) {};
	Vector2d(float x, float y) :x(x), y(y) {};

	void operator += (const Vector2d & v) { x += v.x; y += v.y; };
	void operator -= (const Vector2d & v) { x -= v.x; y -= v.y; };
	void operator *= (float f) { x *= f; y *= f; };
	void operator /= (float f) { x /= f; y /= f; };
	void operator = (const Vector2d & v) { x = v.x; y = v.y; }

	Vector2d operator +(const Vector2d & v) const { return Vector2d(x + v.x, y + v.y); };
	Vector2d operator -(const Vector2d & v) const { return Vector2d(x - v.x, y - v.y); };
	Vector2d operator *(float f) const { return Vector2d(x*f, y*f); };
	Vector2d operator /(float f) const { return Vector2d(x / f, y / f); };

	Vector2d operator -() const { return Vector2d(-x, -y); };
	float length() const { return sqrt(x*x + y * y); }

	float dot(const Vector2d & v) const { return x * v.x + y * v.y; }
	bool operator == (const Vector2d & v) const { return (x == v.x) && (y == v.y); }
	bool operator != (const Vector2d & v) const { return (x != v.x) || (y != v.y); }

};


inline float dot(const Vector2d &v1, const Vector2d &v2)
{
	return v1.dot(v2);
}

inline Vector2d operator * (const Vector2d & v1, const Vector2d & v2)
{
	return Vector2d(v1.x*v2.x, v1.y*v2.y);
}

inline Vector2d operator / (const Vector2d & v1, const Vector2d & v2)
{
	return Vector2d(v1.x / v2.x, v1.y / v2.y);
}

#endif
