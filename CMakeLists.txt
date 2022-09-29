cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)

project(BreakOut)

set(CMAKE_CXX_STANDARD 17)

#------libs settings ------------------#
MESSAGE("Search X11")
set(LIBS ${LIBS})
find_package(X11 REQUIRED)
find_package(GTest REQUIRED)

if (X11_FOUND)
    include_directories(${X11_INCLUDE_DIR})
    link_libraries(${X11_LIBRARIES})
endif(X11_FOUND)

if (GTest_FOUND)
    include_directories(${GTest_INCLUDE_DIR})
    link_libraries(${GTest_LIBRARIES})
endif(GTest_FOUND)

SET(LINK_LIBRARIES ${X11_LIBRARIES})
#-------------------------------------------#

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_subdirectory(config)
add_subdirectory(headers)
add_subdirectory(src)
#add_subdirectory(tests)

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lX11 -lXtst")

#Game
add_executable(BreakOut main.cpp ${headers} ${config} headers/test_helper.h src/test_helper.cpp)
target_link_libraries(BreakOut src_lib pthread)



#Tests
add_executable(test_runner tests/google_greeting_tests.cpp headers/test_helper.h tests/keyboard_simulator.cpp src/test_helper.cpp)
target_link_libraries(test_runner  src_lib ${GTEST_LIBRARIES} pthread gtest gtest_main)
target_include_directories(test_runner PRIVATE ${CMAKE_INCLUDE_CURRENT_DIR}/src)
