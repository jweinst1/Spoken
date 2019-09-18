#include "CStr.h"

#ifndef CSTR_DEFAULT_CAPACITY
#define CSTR_DEFAULT_CAPACITY 25
#endif

#ifndef CSTR_DEFAULT_GROWTH
#define CSTR_DEFAULT_GROWTH 3
#endif

CStr::CStr(): _cap(CSTR_DEFAULT_CAPACITY), 
              _len(0),
              _data(static_cast<char*>(calloc(1, CSTR_DEFAULT_CAPACITY)))
{
    
}

CStr::~CStr()
{
    free(_data);
}

void CStr::grow(size_t size)
{
    while((_cap - _len) > size) {
#ifdef CSTR_GROW_POLICY_FACTOR
    _cap *= CSTR_GROW_POLICY_FACTOR;
#else
    _cap *= CSTR_DEFAULT_GROWTH;
#endif
    _data = static_cast<char*>(realloc(_data, _cap));    
    }
}

CStrIter::CStrIter(const char* string): _string(string)
{
    
}

CStrIter::CStrIter(const CStrIter& other): _string(other._string)
{
    
}