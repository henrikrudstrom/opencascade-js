cmake_minimum_required(VERSION 2.8)

# Name of the project (will be the name of the plugin)
project("opencascade-js")

include_directories("./inc")
include_directories("/usr/local/include/opencascade")
include_directories("./node_modules/nan")
link_directories("/usr/local/lib")

SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage -O0 -fPIC")
SET(GCC_COVERAGE_LINK_FLAGS    "-lgcov")

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )


# common runtime
file(GLOB COMMON_SOURCE_FILES "./src/common/*.cc")
add_library(common SHARED ${COMMON_SOURCE_FILES})
set_target_properties(common PROPERTIES PREFIX "" SUFFIX ".node")
target_include_directories(common PRIVATE ${CMAKE_JS_INC})
target_link_libraries(common ${CMAKE_JS_LIB})

# Module TestModule
file(GLOB TESTMODULE_SOURCE_FILES "./src/TestModule/*.cc")
add_library(TestModule SHARED ${TESTMODULE_SOURCE_FILES})
set_target_properties(TestModule PROPERTIES PREFIX "" SUFFIX ".node")
target_include_directories(TestModule PRIVATE ${CMAKE_JS_INC})
target_link_libraries(TestModule ${CMAKE_JS_LIB})
target_link_libraries(TestModule common TKernel TKG2d TKG3d TKGeomBase TKMath)
  