# Core CMAKE #

########################
# Definitions ##########
# SPOKEN_LINE_MAX_LENGTH
# Determines max length of
# a read line
add_definitions(-DSPOKEN_LINE_MAX_LENGTH=1024)

SET(SPOKEN_CORE_LIB_SOURCES
     line.c
)