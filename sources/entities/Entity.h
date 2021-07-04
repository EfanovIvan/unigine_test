
#ifndef ENTITY_H
#define ENTITY_H

#include <utils/Vector.h>


class Entity
{
public:
	Entity() = delete;
	virtual ~Entity();
	Entity(int id, const Vector2d & positon); 
	Vector2d GetPosition() const;
	int GetId() const;

	Entity(const Entity&) = default;
	Entity(Entity&&) = default;
private:
	int m_id;
	Vector2d m_position;

};


#endif
