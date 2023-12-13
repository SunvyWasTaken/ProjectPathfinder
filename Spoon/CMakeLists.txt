project (Spoon)

set (SOURCE_FILES 
	src/snpch.h
	src/snpch.cpp
)

file(GLOB_RECURSE PROJECT_SOURCE_FILES "*.h" "*.cpp")

include_directories(src)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)

macro(GroupSources curdir)
    file(GLOB children RELATIVE ${PROJECT_SOURCE_DIR}/${curdir}
    ${PROJECT_SOURCE_DIR}/${curdir}/* ${PROJECT_SOURCE_DIR}/${curdir}/${curdir}/*)

    foreach(child ${children})

        if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${curdir}/${child})
            GroupSources(${curdir}/${child})
        else()
            string(REPLACE "/" "\\" groupname ${curdir})
            # I would like to call the src root folder in a different name, only in visual studio (not mandatory requirement)
            source_group(${groupname} FILES
            ${PROJECT_SOURCE_DIR}/${curdir}/${child})
        endif()
    endforeach()
endmacro()

# Execute the macro
GroupSources(src)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(ImGui-SFML CONFIG REQUIRED)

add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCE_FILES})

add_compile_definitions(SN_BUILD_DLL)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-network sfml-graphics sfml-window
	    imgui::imgui
	    ImGui-SFML::ImGui-SFML
)

target_precompile_headers(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})

#set(PROJECT_TARGET "ProjectPathfinder")

#set(CMAKE_BUILD_TYPE "Debug")

#set(TARGET_FILE ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/${CMAKE_BUILD_TYPE}/${PROJECT_NAME}.dll)
#set(TARGET_FILE_DIR ${CMAKE_BINARY_DIR}/${PROJECT_TARGET}/${CMAKE_BUILD_TYPE})

#message("Target file : ${TARGET_FILE}")
#message("Target files dir : ${TARGET_FILE_DIR}")

#add_custom_command(TARGET Spoon POST_BUILD  COMMAND ${CMAKE_COMMAND} -E copy ${TARGET_FILE} ${TARGET_FILE_DIR} COMMAND_EXPAND_LISTS  )
