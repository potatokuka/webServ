file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.hpp *.cpp)

set(SOURCES ${SOURCES})

add_library(${MODULE_NAME}_lib STATIC ${SOURCES})

target_include_directories(${MODULE_NAME}_lib
	PUBLIC ../../Util/src/
    )

target_link_libraries(${MODULE_NAME}_lib
	PUBLIC util_lib
  )
