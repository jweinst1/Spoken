# cmake util #

set(SPOKEN_UTIL_SOURCES
    CStr.cpp
)

add_library(spokenutil STATIC "${SPOKEN_UTIL_SOURCES}")

add_subdirectory(tests)