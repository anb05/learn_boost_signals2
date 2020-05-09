cmake_minimum_required(VERSION 3.16)

set(PR_NAME signal_hw)
set(PR_VERSION 0.0.0.1)

project(${PR_NAME} VERSION ${PR_VERSION} LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g")

set (HEADERS 
    )

set (SRC
    ./main.cpp
    )

add_executable(${PROJECT_NAME} ${HEADERS} ${SRC})

