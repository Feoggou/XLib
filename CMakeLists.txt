cmake_minimum_required (VERSION 3.1)

option(PROJ_LIB_TYPES "Use zSearch and XLib as static libs." "STATIC")
if (NOT PROJ_LIB_TYPES)
    set(PROJ_LIB_TYPES "STATIC")
endif()

enable_testing()

project(XLib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY    ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY    ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY    ${CMAKE_BINARY_DIR}/bin)

set(CFLAG CMAKE_CXX_FLAGS_DEBUG)
string(REPLACE "/MD" "/MT" ${CFLAG} "${${CFLAG}}")
message(STATUS "link flags: ${CMAKE_CXX_FLAGS_DEBUG}")

add_subdirectory(XLib)
add_subdirectory(Tests)