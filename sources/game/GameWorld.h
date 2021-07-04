#ifndef GAME_WORLD
#define GAME_WORLD
#include <memory>
#include <vector>
#include <utils/Vector.h>
#include <KDTree.hpp>
#include <entities/Unit.h>


class GameWorld
{
public:
	GameWorld(const std::vector<Unit> & entities);
	void Initialize();
	std::vector<std::vector<double>> GetNeighborhoodPoints(Vector2d point, float rad);

	const Unit & GetEntityById(int id);
	void DetermineVisibility();
	const std::string GetSerializedData();
	bool Visible(const Unit & looking, const Vector2d & objectPosition);
private:
	std::shared_ptr<KDTree> m_tree;
	std::vector<Unit>  m_entities;
	std::map<int, int> m_idCount;
};
#endif
