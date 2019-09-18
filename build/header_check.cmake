# Header Check Script #

# This file is meant to be run as part of a CMakeLists.txt
# Do not run this directly

find_file(HAVE_STDINT_HEADER stdint.h)
if(HAVE_STDINT_HEADER)
   message("** stdint.h found")
   add_definitions(-DHAVE_STDINT)
else(HAVE_STDINT_HEADER)
   message("** stdint.h not found")
endif(HAVE_STDINT_HEADER)

find_file(HAVE_WCHAR_HEADER wchar.h)
if(HAVE_WCHAR_HEADER)
   message("** wchar.h founnd")
   add_definitions(-DHAVE_WCHAR_H)
else(HAVE_WCHAR_HEADER)
   message("** wchar.h not found")
endif(HAVE_WCHAR_HEADER)