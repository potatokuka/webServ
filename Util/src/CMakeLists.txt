file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.hpp *.cpp)

set(SOURCES ${SOURCES})

add_library(${MODULE_NAME}_lib STATIC ${SOURCES})

# target_include_directories(${MODULE_NAME}_lib
# 	PUBLIC //DIR HERE
#     )

# target_link_libraries(${MODULE_NAME}_lib
# 	PUBLIC //LIBHERE
#   )
