cmake_minimum_required(VERSION 2.8)
project(DungeonFight)
# config
set(DUNGEONFIGHT_VERSION_MAJOR 0)
set(DUNGEONFIGHT_VERSION_MINOR 0)
configure_file(
  ${PROJECT_SOURCE_DIR}/DungeonFightConfig.h.in
  ${PROJECT_BINARY_DIR}/DungeonFightConfig.h
)
# compiler flags
set(DUNGEONFIGHT_CXX_FLAGS)
set(DUNGEONFIGHT_CXX_FLAGS "${DF_CXX_FLAGS} -std=c++1y -g")
# source code
set(DUNGEONFIGHT_SOURCES
  # Main
  ${PROJECT_SOURCE_DIR}/src/Main.cpp
  ${PROJECT_SOURCE_DIR}/src/Game.cpp
  ${PROJECT_SOURCE_DIR}/src/Game.h
  # src
  ${PROJECT_SOURCE_DIR}/src/Constants.cpp
  ${PROJECT_SOURCE_DIR}/src/Constants.h
  ${PROJECT_SOURCE_DIR}/src/Room.cpp
  ${PROJECT_SOURCE_DIR}/src/Room.h
  ${PROJECT_SOURCE_DIR}/src/Stage.cpp
  ${PROJECT_SOURCE_DIR}/src/Stage.h
  # libraries
  ${PROJECT_SOURCE_DIR}/include/ngraph.hpp
  ${PROJECT_SOURCE_DIR}/include/set_ops.hpp
)
foreach(file ${DUNGEONFIGHT_SOURCES})
    set_source_files_properties(
        ${file} PROPERTIES
        COMPILE_FLAGS "${DUNGEONFIGHT_CXX_FLAGS}"
    )
endforeach()
# directories
include_directories(
  .
  ${PROJECT_BINARY_DIR}
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/src
  ${PROJECT_SOURCE_DIR}/include
)
# objects
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 COMPONENTS system window graphics audio system REQUIRED)
include_directories(${SFML_INCLUDE_DIR})
set(DUNGEONFIGHTEXE DungeonFight.exe)
add_executable(${DUNGEONFIGHTEXE} ${DUNGEONFIGHT_SOURCES})
target_link_libraries(${DUNGEONFIGHTEXE} ${SFML_LIBRARIES})
