#include  "Entity.h"
#include <utils/Vector.h>


Entity::Entity(int id, const Vector2d & positon)
	: m_id(id)
	, m_position(positon)
{}

Entity::~Entity()
{}

Vector2d Entity::GetPosition() const
{
	return m_position;
}

int Entity::GetId() const
{
	return m_id;
}