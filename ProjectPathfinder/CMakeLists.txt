project(ProjectPathfinder)

set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/ProjectPathfinder/src")
set(SOURCES
	"${SOURCE_DIR}/main.cpp"
)

include_directories(${CMAKE_SOURCE_DIR}/Spoon/src)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(ImGui-SFML CONFIG REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

add_dependencies(${PROJECT_NAME} Spoon)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-network sfml-graphics sfml-window Spoon )

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)