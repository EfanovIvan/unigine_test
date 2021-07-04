#include "Unit.h"
float Unit::angle;
float Unit::distance;
 Unit Unit::unit;

Unit::Unit(int id, const Vector2d & positon, const Vector2d & ray)
	:Entity(id, positon)
	,m_ray(ray)
{}

int Unit::GetCountOfVisible() const
{
	return m_countofVisible;
}

void Unit::SetCountOfVisible(int countOfVisible)
{
	m_countofVisible = countOfVisible;
}

Vector2d Unit::GetRay() const
{
	return m_ray;
}