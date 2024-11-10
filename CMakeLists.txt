cmake_minimum_required(VERSION 3.16)

project(ScreenCreator)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    screens/*.cpp
    screens/*.hpp
    screens/*.h
    interfaces/*.cpp
    interfaces/*.hpp
    interfaces/*.h
    )

set(INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/interfaces/)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDES})
