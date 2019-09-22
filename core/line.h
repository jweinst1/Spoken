#ifndef SPOKEN_CORE_LINE_H
#define SPOKEN_CORE_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef SPOKEN_LINE_MAX_LENGTH
#  if SPOKEN_LINE_MAX_LENGTH < 256
#      error SPOKEN_LINE_MAX_LENGTH must be set at 256 or greater
#  endif
#else
#  define SPOKEN_LINE_MAX_LENGTH 1024 
#endif

struct SpokenLine {
    char data[SPOKEN_LINE_MAX_LENGTH];
};

typedef struct SpokenLine SpokenLine;

int SpokenLine_read_file(SpokenLine* line, FILE* fp);

int SpokenLine_readStr(SpokenLine* line, const char* string);

#endif // SPOKEN_CORE_LINE_H