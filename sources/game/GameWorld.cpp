
#include <utils/numbers.h>
#include <utils/Vector.h>
#include <entities/Unit.h>

#include <map>
#include <ostream>
#include <iostream>
#include <sstream>
#include "GameWorld.h"


GameWorld::GameWorld(const std::vector<Unit> & entities)
	:m_entities(entities)
	, m_tree(nullptr)
{

}

void GameWorld::Initialize()
{
	std::vector<std::vector<double>> points;
	for (auto & entity : m_entities)
	{
		points.push_back({ entity.GetPosition().x, entity.GetPosition().y });
	}
	m_tree = std::make_shared<KDTree>(points);
}

std::vector<std::vector<double>> GameWorld::GetNeighborhoodPoints(Vector2d point, float rad)
{
	return m_tree->neighborhood_points({ point.x , point.y }, rad);

}

const Unit & GameWorld::GetEntityById(int id)
{
	for (auto & entity : m_entities)
	{
		if (entity.GetId() == id)
		{
			return entity;
		}
	}
	return Unit::unit;
}

void GameWorld::DetermineVisibility()
{
	std::map<int, std::vector<std::vector<double>>> nearestPoints;
	for (const auto & entity : m_entities)
	{
		nearestPoints[entity.GetId()] = GetNeighborhoodPoints(entity.GetPosition(), Unit::distance);
	}

	for (auto & currentPoints : nearestPoints)
	{
		auto & looking = GetEntityById(currentPoints.first);
		m_idCount[looking.GetId()] = 0;
		if (looking.GetId() != -1)
		{

			for (auto & objectPoints : currentPoints.second)
			{
				if (Visible(looking, Vector2d(objectPoints.at(0), objectPoints.at(1))))
				{
					m_idCount[looking.GetId()]++;
				}
			}
		}
	}
}


bool GameWorld::Visible(const Unit & looking, const Vector2d & objectPosition)
{
	if (looking.GetPosition() != objectPosition)
	{
		Vector2d v = objectPosition - looking.GetPosition();
		double dot = v.dot(looking.GetRay());

		if (dot <= numbers::epsilonE5)
		{
			return false;
		}

		double alpha = dot / (v.length() * looking.GetRay().length());

		alpha = acos(alpha) * 180 / numbers::pi;

		return (alpha <= Unit::angle / 2) && (v.length() <= Unit::distance);

	}
	return false;
}

const std::string  GameWorld::GetSerializedData()
{
	std::ostringstream stre;
	stre << "[";
	for (auto & item : m_idCount)
	{
		stre << "{\"id\": " << item.first << ", " << "\"visible\": " << item.second << "},";
	}

	auto str = stre.str();
	str[str.length() - 1] = ']';
	return str;
}

