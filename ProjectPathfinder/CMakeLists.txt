project(ProjectPathfinder)

set(DLL_NAME "Spoon")

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)

set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/ProjectPathfinder/src")
set(SOURCES
	"${SOURCE_DIR}/main.cpp"
	"${SOURCE_DIR}/AStar.h"
	"${SOURCE_DIR}/AStar.cpp"
	"${SOURCE_DIR}/SNode.h"
	"${SOURCE_DIR}/SNode.cpp"
)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(ImGui-SFML CONFIG REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/${DLL_NAME}/src)

add_executable(${PROJECT_NAME} ${SOURCES})

target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:DEBUG>)

add_dependencies(${PROJECT_NAME} ${DLL_NAME})

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-network sfml-graphics sfml-window Spoon )

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

set(TARGET_FILE ${CMAKE_BINARY_DIR}/${DLL_NAME}/$<CONFIG>/${DLL_NAME}.dll)
set(TARGET_FILE_DIR ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/$<CONFIG>)

message("Target file : ${TARGET_FILE}")
message("Target files dir : ${TARGET_FILE_DIR}")

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy  ${TARGET_FILE}  ${TARGET_FILE_DIR} COMMAND_EXPAND_LISTS )
