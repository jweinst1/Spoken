#include "StrSeg.h"

#define ALLOC_CHARS(sz) (static_cast<char*>(malloc(sz * sizeof(char))))

StrSeg::StrSeg(size_t size): _size(size),
                             _data(ALLOC_CHARS(size))
{
    // null first char for safety
    _data[0] = '\0';
}

StrSeg::StrSeg(const char* data): _size(strlen(data)),
                                  _data(ALLOC_CHARS(_size))
{
    char* writer = _data;
    while(*data) *writer++ = *data++;
}

StrSeg::StrSeg(const char* data, size_t size):_size(size),
                                              _data(ALLOC_CHARS(size))
{
    char* writer = _data;
    while(*data) *writer++ = *data++;
}
    
StrSeg::~StrSeg()
{
    free(_data);
}

#undef ALLOC_CHARS
