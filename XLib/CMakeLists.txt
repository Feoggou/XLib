project (XLib VERSION 0.0.0.0)

configure_file ("${PROJECT_SOURCE_DIR}/Version.h.in" "${PROJECT_BINARY_DIR}/Generated/Version.h")
include_directories("${PROJECT_BINARY_DIR}/Generated")

add_library(XLib ${PROJ_LIB_TYPES} dllmain.cpp)
message(STATUS "building XLib libray as: ${PROJ_LIB_TYPES}")