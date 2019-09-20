# cmake util #

set(SPOKEN_UTIL_SOURCES
    CStr.cpp
    FileStr.cpp
)

# Definitions
# This allows the CStr to grow exponentially
# This can be removed in memory constrained systems.
add_definitions(-DCSTR_GROW_EXP_FACTOR)

add_library(spokenutil STATIC "${SPOKEN_UTIL_SOURCES}")

add_subdirectory(tests)