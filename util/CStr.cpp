#include "CStr.h"

CStrIter::CStrIter(const char* string): _string(string)
{
    
}

CStrIter::CStrIter(const CStrIter& other): _string(other._string)
{
    
}