cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

project(BreakOut)


MESSAGE("Search X11")
set(LIBS ${LIBS})
find_package(X11 REQUIRED)
if (X11_FOUND)
    include_directories(${X11_INCLUDE_DIR})
    link_libraries(${X11_LIBRARIES})
endif(X11_FOUND)

SET(SOURCE_FILES main.cpp headers/displayable.h src/displayable.cpp headers/texts.h src/texts.cpp headers/rectangle.h
        src/rectangle.cpp headers/drawer.h headers/config_loader.h config/game_settings.h headers/game.h headers/ball.h headers/paddle.h src/config_loader.cpp src/ball.cpp src/paddle.cpp src/game.cpp src/drawer.cpp)
SET(LINK_LIBRARIES ${X11_LIBRARIES})

add_executable(BreakOut ${SOURCE_FILES})






