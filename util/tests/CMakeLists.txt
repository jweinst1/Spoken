# Tests for Util #

include_directories(${PROJECT_SOURCE_DIR}/util)

add_executable(CStrTests CStrTests.cpp)
target_link_libraries(CStrTests PUBLIC spokenutil)
add_test(CStrTests CStrTests)