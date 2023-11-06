﻿project(ProjectPathfinder)

set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/ProjectPathfinder/src")
set(SOURCES
	"${SOURCE_DIR}/main.cpp"
)

include_directories(${CMAKE_SOURCE_DIR}/Spoon/src)

add_executable(${PROJECT_NAME} ${SOURCES})

add_dependencies(${PROJECT_NAME} Spoon)

#target_link_libraries(	Spoon )

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)