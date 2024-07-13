cmake_minimum_required(VERSION 3.5)

project(platformer-game-sdl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED SDL2_image>=2.0.0)

add_executable(platformer-game-sdl
    main.cpp
    game.h game.cpp
    ECS.h
    texturemanager.h texturemanager.cpp
    SpriteComponent.h
    TransformComponent.h
    vector2d.h
    SpriteSystem.h
    PlayerMovementSystem.h
    ColliderComponent.h
    PhysicsComponent.h
    PhysicsSystem.h
    CollisionDetectionSystem.h
)

include(GNUInstallDirs)
install(TARGETS platformer-game-sdl
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
target_link_libraries(platformer-game-sdl  SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image)
