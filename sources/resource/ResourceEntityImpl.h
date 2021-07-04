
#ifndef RESOURCE_ENTITY_IMPL
#define RESOURCE_ENTITY_IMPL
#include <vector>

class Unit;

class ResourceEntity
{
public:

	void Deserealize(const std::string & filename);

	void Serialize(const std::string & filename, const std::string & data);

	const std::vector<Unit> & GetObjects() ;

private:
	std::vector<Unit>  m_units;
};

#endif