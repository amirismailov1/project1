cmake_minimum_required(VERSION 3.27)
project(sokoban)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib CONFIG REQUIRED)
if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
elseif(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -fsanitize=address -fsanitize=undefined")
endif()

add_executable(sokoban sokoban.cpp globals.h levels.h player.h graphics.h images.h sounds.h level.cpp level.h player.cpp
        parser.cpp
)
target_link_libraries(sokoban PRIVATE raylib)
