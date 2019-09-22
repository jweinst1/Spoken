#include "line.h"

int SpokenLine_read_file(SpokenLine* line, FILE* fp)
{
    if(NULL == fgets(line->data, SPOKEN_LINE_MAX_LENGTH, fp)) {
        return 0;
    }
    if (line->data[SPOKEN_LINE_MAX_LENGTH - 1] && line->data[SPOKEN_LINE_MAX_LENGTH - 1] != '\n') {
        return 0;
    }
    return 1;
}

int SpokenLine_readStr(SpokenLine* line, const char* string)
{
    char* writer = line->data;
    unsigned count = SPOKEN_LINE_MAX_LENGTH;
    while(*string && *string != '\n') {
        if(!count) {
            // line is longer than the limit.
            return 0;
        }
        count--;
        *writer++ = *string++;
    }
    return 1;
}