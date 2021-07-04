
add_library(KDTree STATIC KDTree.cpp KDTree.hpp)

set_target_properties(
    KDTree PROPERTIES
		CXX_STANDART 14
		CXX_STANDART_REQUIRED ON
		)


target_include_directories(
    KDTree
    PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}
)