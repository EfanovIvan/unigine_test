

// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <vector>
#include <game/GameWorld.h>
#include <random>
#include <entities/Unit.h>
#include <utils/Vector.h>

TEST_CASE("10000 Units") {
	std::random_device rd;  
	std::mt19937 gen(rd()); 
	std::normal_distribution<float> distrib_1(1, 100);
	std::normal_distribution<float> distrib_2(-1.0, 1.0);

	Unit::angle = 135.0;
	Unit::distance = 2;
	std::vector<Unit> units;
	for(int i = 0; i < 10000; i++)
	{
		units.emplace_back(i, Vector2d(distrib_1(gen), distrib_1(gen)), Vector2d(distrib_2(gen), distrib_2(gen)));
	}

   GameWorld world(units);
   world.Initialize();
   world.DetermineVisibility();
   auto data = world.GetSerializedData();
   
}


