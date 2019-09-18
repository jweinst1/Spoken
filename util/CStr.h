#ifndef SPOKEN_CSTR_H
#define SPOKEN_CSTR_H

#include <cstdio>
#include <cstdlib>


class CStr {
public:
    CStr();
    ~CStr();
    const char& operator *() const { return *_data; }
    
    const char* getData() const { return _data; }
    size_t getLen() const { return _len; }
    size_t getCap() const { return _cap; }
  
private:
    void grow(size_t size);

private:
    size_t _cap;
    size_t _len;
    char* _data;
};

class CStrIter {
public:
    CStrIter(const char* string);
    CStrIter(const CStrIter& other);
    
    const char* getString() const { return _string; }
    
    void operator++()
    {
        if(*_string) _string++;
    }
    
    const char& operator *() const { return *_string; }
private:
   const char* _string;   
};

#endif // SPOKEN_CSTR_H