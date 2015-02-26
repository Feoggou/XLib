project (XLib VERSION 0.0.0.0)

# option (USE_MYMATH "Use tutorial provided math implementation" ON) 
        
configure_file ("${PROJECT_SOURCE_DIR}/Version.h.in" "${PROJECT_SOURCE_DIR}/Version.h")

add_library(XLib ${PROJ_LIB_TYPES} dllmain.cpp)
message(STATUS "building XLib libray as: ${PROJ_LIB_TYPES}")