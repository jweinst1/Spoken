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
    if(_cap < size)
        _data = static_cast<char*>(realloc(_data, size));
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