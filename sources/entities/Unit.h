#ifndef UNIT_H
#define UNIT_H
#include "Entity.h"

class Unit : public Entity
{
public:
	Unit(int id, const Vector2d & positon, const Vector2d & ray);
	Unit():Entity(-1, Vector2d(0,0)){}
	int GetCountOfVisible() const;
	Vector2d GetRay() const;

	void SetCountOfVisible(int countOfVisible);

	static float angle;
	static float distance;
	static Unit unit;
private:
	Vector2d m_ray;
	int m_countofVisible;
};


#endif