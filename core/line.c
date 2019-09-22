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
    unsigned count = SPOKEN_LINE_MAX_LENGTH;
    char * writer = line->data;
    while(*string) {
        *writer++ = *string++
        count--;
    }
    return 1;
}