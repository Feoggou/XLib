project(XLibTests)

include_directories("${GTEST_INCLUDE_DIR}" "${GMOCK_INCLUDE_DIR}" "${CMAKE_SOURCE_DIR}/XLib")
link_directories("${GTEST_LIB_DIR}" "${GMOCK_LIB_DIR}")

CreateTestProj(XLib_test_1 test1.cpp)
CreateTestProj(XLib_test_2 test2.cpp)