cmake_minimum_required(VERSION 3.12)
project(memory)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror)

add_library(memoryCore
        src/memoryModel.cpp
        src/memoryView.cpp
        src/memoryController.cpp
        src/memoryBoard.cpp
        src/tile.cpp
        src/infinityTile.cpp
        src/limitedTile.cpp
        src/threeRevealsTwoRemove.cpp)

target_include_directories(memoryCore PUBLIC include) 

add_executable(memory src/main.cpp)

target_link_libraries(memory memoryCore)
