project(XLibTests)

InitExe()

set(G_INCLUDE_DIRS ${G_INCLUDE_DIRS} "${CMAKE_SOURCE_DIR}/XLib")
set(G_LINK_TARGETS ${G_LINK_TARGETS} XLib)

CreateTests(XLib_)