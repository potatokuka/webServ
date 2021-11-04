set(MODULE_NAME HTTPParse)

include_directories(src)
include_directories(../Util/src/)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true src/*.hpp src/*.cpp)

set(SOURCES ${SOURCES})

add_executable(${MODULE_NAME}.run ${SOURCES} main.cpp)

add_subdirectory(src)
add_subdirectory(tst)
