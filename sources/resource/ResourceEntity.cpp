#include "ResourceEntityImpl.h"
#include <utils/Vector.h>
#include <entities/Unit.h>

#include <fstream>
#include <string>
#include <nlohmann/json.hpp>


void ResourceEntity::Deserealize(const std::string & filename)
{
	std::ifstream istrm(filename, std::ios::binary);
	if (!istrm.is_open())
	{
		throw std::runtime_error("ResourceEntityImpl::Deserealize - Failed to load " + filename);
	}
	nlohmann::json json;
	istrm >> json;

	if (json.contains("angle"))
	{
		Unit::angle = json["angle"].get<float>();
	}

	if (json.contains("distance"))
	{
		Unit::distance = json["distance"].get<float>();
	}

	if (json.contains("Entities"))
	{
		for (auto & unit : json["Entities"])
		{
			int id = unit.at("id").get<int>();
			Vector2d position(unit.at("position").at(0).get<float>(), unit.at("position").at(1).get<float>());
			Vector2d ray(unit.at("ray").at(0).get<float>(), unit.at("ray").at(1).get<float>());
			m_units.emplace_back(id, position, ray);
		}

	}
}


void ResourceEntity::Serialize(const std::string & filename, const std::string & data)
{
	std::ofstream ostrm(filename, std::ios::binary);
	
	nlohmann::json json = nlohmann::json::parse(data);
	ostrm << json;
}

const std::vector<Unit> & ResourceEntity::GetObjects()
{
	return m_units;
}