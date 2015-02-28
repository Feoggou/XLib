project(XLibTests)

include_directories("${GTEST_INCLUDE_DIR}" "${GMOCK_INCLUDE_DIR}" "${CMAKE_SOURCE_DIR}/XLib")
link_directories("${GTEST_LIB_DIR}" "${GMOCK_LIB_DIR}")

file(GLOB_RECURSE CPP_FILES "${CMAKE_CURRENT_SOURCE_DIR}" "*.cpp")
source_group("Test" FILES ${CPP_FILES})

foreach(curItem ${CPP_FILES})
    get_filename_component(displayName "${curItem}" NAME_WE)
    CreateTestProj("XLib_${displayName}" ${curItem})
endforeach()