project (XLib VERSION 0.0.0.0)

configure_file ("${PROJECT_SOURCE_DIR}/Version.h.in" "${PROJECT_BINARY_DIR}/Generated/Version.h")
include_directories("${PROJECT_BINARY_DIR}/Generated")

file(GLOB_RECURSE CPP_FILES "${CMAKE_CURRENT_SOURCE_DIR}" "*.cpp")
file(GLOB_RECURSE H_FILES "${CMAKE_CURRENT_SOURCE_DIR}" "*.h")
source_group("Code" FILES ${CPP_FILES} ${H_FILES})

add_library(XLib ${PROJ_LIB_TYPES} ${CPP_FILES} ${H_FILES})
message(STATUS "building XLib libray as: ${PROJ_LIB_TYPES}")