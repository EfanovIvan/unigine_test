#include <nlohmann/json.hpp>
#include <iostream>

#include "resource/ResourceEntityImpl.h"
#include "game/GameWorld.h"


int main() 
{
	try
	{
		ResourceEntity entityLoader = ResourceEntity();
		entityLoader.Deserealize("../resources/Entities.json");
		
		const auto & entities = entityLoader.GetObjects();
		GameWorld world(entities);
		world.Initialize();
		world.DetermineVisibility();

		entityLoader.Serialize("../resources/Visible.json", world.GetSerializedData());
	}
	catch (std::exception & e)
	{
		std::cerr << e.what();
	}
	
	
	return 0;

}
