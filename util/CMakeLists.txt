# cmake util #

set(SPOKEN_UTIL_SOURCES
    CStr.cpp
    FileStr.cpp
    StrSeg.cpp
)

# Definitions
# This allows the CStr to grow exponentially
# This can be removed in memory constrained systems.
add_definitions(-DCSTR_GROW_EXP_FACTOR)

add_library(spokenutil STATIC "${SPOKEN_UTIL_SOURCES}")

if(WITH_testing MATCHES ON)
    add_subdirectory(tests)
endif(WITH_testing MATCHES ON)