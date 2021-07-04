cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(extenal/json)
add_subdirectory(extenal/KDTree)


set(game sources/game/GameWorld.cpp
         sources/game/GameWorld.h)

set(entities sources/entities/entity.cpp
             sources/entities/entity.h
             sources/entities/Unit.cpp
             sources/entities/Unit.h)    
             
             
set(resource sources/resource/ResourceEntity.cpp
             sources/resource/ResourceEntity.h)

set(utils sources/utils/Vector.h
             sources/utils/numbers.h)

source_group("game" FILES ${game})
source_group("entities" FILES ${entities})
source_group("utils" FILES ${utils})
source_group("resource" FILES ${resource})            
       

add_library(game STATIC ${game}
                        ${entities}
                        ${utils}
                        ${resource} )

target_include_directories(game PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/sources"
                                        "${CMAKE_CURRENT_SOURCE_DIR}/extenal/KDTree")

target_link_libraries(game PRIVATE nlohmann_json::nlohmann_json KDTree)
    

add_executable(${PROJECT_NAME} sources/main.cpp)



target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json KDTree game)

add_executable(test_cpp test/test.cpp)



target_link_libraries(test_cpp game)

enable_testing()

add_test(
  NAME catch_test
  COMMAND $<TARGET_FILE:test_cpp> --success
)