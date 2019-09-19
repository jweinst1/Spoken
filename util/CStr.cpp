#include "CStr.h"

#ifndef CSTR_DEFAULT_CAPACITY
#define CSTR_DEFAULT_CAPACITY 25
#endif

#ifndef CSTR_DEFAULT_GROWTH
#define CSTR_DEFAULT_GROWTH 3
#endif

CStr::CStr(): _cap(CSTR_DEFAULT_CAPACITY), 
              _len(0),
              _data(static_cast<char*>(calloc(1, CSTR_DEFAULT_CAPACITY + 1)))
{
    
}

CStr::CStr(const char* string)
{
    _len = 0;
    _cap = strlen(string) + 5;
    _data = static_cast<char*>(calloc(1, _cap + 1));
    while(*string)
        _data[_len++] = *string++;
}

CStr::CStr(const CStr& other): _cap(other._cap),
                               _len(other._len),
                               _data(static_cast<char*>(calloc(1, _cap + 1)))
{
    char* writer = _data;
    const char* reader = other._data;
    while(*reader) *writer++ = *reader++;
}

CStr& CStr::operator=(const CStr& other)
{
    if(this != &other) {
        // Avoid free call and reuse memory.
        char* writer = nullptr;
        const char* reader = other._data;
        _len = other._len;
        reserve(other._cap);
        writer = _data;
        memset(_data, 0, _cap);
        while(*reader) *writer++ = *reader++;
    }
    return *this; 
}

CStr::~CStr()
{
    free(_data);
}

void CStr::grow(size_t size)
{
    size++; // null safety
    while((_cap - _len) > size) {
#ifdef CSTR_GROW_EXP_FACTOR
    _cap *= _cap;
#else
    _cap *= CSTR_DEFAULT_GROWTH;
#endif
    _data = static_cast<char*>(realloc(_data, _cap));    
    }
}

void CStr::reserve(size_t size)
{
    size++; // null safety
    if(_cap < size) {
        _data = static_cast<char*>(realloc(_data, size));
        _cap = size;
    }
}

void CStr::append(const char* string, size_t size)
{
    reserve(size);
    while(*string && size--)
        _data[_len++] = *string++;
}

CStrIter::CStrIter(const char* string): _string(string)
{
    
}

CStrIter::CStrIter(const CStrIter& other): _string(other._string)
{
    
}