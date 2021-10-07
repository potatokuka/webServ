cmake_minimum_required(VERSION 3.1.0)
project(webserv VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
# googletest setup

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wno-noexcept-type")

set(BINARY ${CMAKE_PROJECT_NAME})
set(SOURCES simplesocket.cpp)

add_executable(${BINARY}.run ${SOURCES})
