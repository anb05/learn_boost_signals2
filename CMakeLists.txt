cmake_minimum_required(VERSION 3.16)

set(PR_NAME signal_hw)
set(PR_VERSION 0.0.0.1)

project(${PR_NAME} VERSION ${PR_VERSION} LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g")

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
# The boost library signals2 is a headers library.
#find_packege(boost COMPONENTS singals2 REQUIRED)

set (HEADERS 
    )

set (SRC
    ./main.cpp
    )

add_executable(${PROJECT_NAME} ${HEADERS} ${SRC})

