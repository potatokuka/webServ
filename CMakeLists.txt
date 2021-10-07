cmake_minimum_required(VERSION 3.1.0)
project(webserv VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# Update submodules
find_package(Git QUIET)
if (GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
	option(GIT_SUBMODULE "Check submodules during build" ON)
	if (GIT_SUBMODULE)
		message(STATUS "Submodule update")
		execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
			WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
			RESULT_VARIABLE GIT_SUBMOD_RESULT)
		if (NOT GIT_SUBMOD_RESULT EQUAL "0")
			message(FATAL_ERROR "git submodule update --init --recursive"
			"failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
		endif()
	endif()
endif()

# Check submodules exist
if (NOT EXISTS "${PROJECT_SOURCE_DIR}/googletest/CMakeLists.txt")
	message(FATAL_ERROR "The googletest submodules was not downloaded!"
		" GIT_SUBMODULE was turned off or failed.")
endif()

add_subdirectory(googletest)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wno-noexcept-type")

# Create binary
set(BINARY ${CMAKE_PROJECT_NAME})
set(SOURCES main.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_subdirectory(example_module)

add_executable(${BINARY}.run ${SOURCES})
