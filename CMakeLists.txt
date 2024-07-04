cmake_minimum_required(VERSION 3.5)

project(Platformer_Game_SDL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED SDL2_image>=2.0.0)

add_executable(Platformer_Game_SDL
    main.cpp
    game.h game.cpp
    ECS.h
)

include(GNUInstallDirs)
install(TARGETS Platformer_Game_SDL
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
target_link_libraries(Platformer_Game_SDL  SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image)
