#include "StrSeg.h"

#define ALLOC_CHARS(sz) (static_cast<char*>(malloc(sz * sizeof(char))))

StrSeg::StrSeg(size_t size): _size(size),
                             _data(ALLOC_CHARS(size))
{
    // null first char for safety
    _data[0] = '\0';
}

StrSeg::StrSeg(const char* data): _size(strlen(data)),
                                  _data(ALLOC_CHARS(_size + 1))
{
    char* writer = _data;
    while(*data) *writer++ = *data++;
    _data[_size] = '\0';
}

StrSeg::StrSeg(const char* data, size_t size):_size(size),
                                              _data(ALLOC_CHARS(size))
{
    char* writer = _data;
    while(*data) *writer++ = *data++;
    _data[_size] = '\0';
}
    
StrSeg::~StrSeg()
{
    free(_data);
}

StrSeg::StrSeg(const StrSeg& other): _size(other._size),
                                     _data(ALLOC_CHARS(_size))
{
    const char* reader = other._data;
    char* writer = _data;
    while(*reader) *writer++ = *reader++;
    _data[_size] = '\0';
}
    
StrSeg& StrSeg::operator=(const StrSeg& other)
{
    if(this != &other) {
        // If the current seg is large enough, reuse memory.
        if(_size < other._size) {
            free(_data);
            _size = other._size;
            _data = ALLOC_CHARS(_size);
        }
        const char* reader = other._data;
        char* writer = _data;
        while(*reader) *writer++ = *reader++; 
    }
    return *this;
}
    
StrSeg& StrSeg::operator=(const char* string)
{
    size_t slen = strlen(string);
    if(_size < slen) {
         free(_data);
        _size = slen;
        _data = ALLOC_CHARS(_size + 1);
    }
    char* writer = _data;
    while(*string) *writer++ = *string++;
    _data[_size] = '\0';
    return *this;
}

#undef ALLOC_CHARS
