#ifndef SPOKEN_CSTR_H
#define SPOKEN_CSTR_H

#include <cstdio>
#include <cstdlib>
#include <cstring>


class CStr {
public:
    CStr();
    CStr(const char* string);
    CStr(const CStr& other);
    
    CStr& operator=(const CStr& other);
    ~CStr();
    const char& operator *() const { return *_data; }
    
    const char* getData() const { return _data; }
    size_t getLen() const { return _len; }
    size_t getCap() const { return _cap; }
    
    const char operator[](size_t index) const
    {
        return (index < _cap) ? _data[index] : '\0';
    }
    
    void reserve(size_t size);
    
    CStr& operator<<(const char* string)
    {
        append(string, strlen(string));
        return *this;
    }
    
private:
    void append(const char* string, size_t size);
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
    
    void next()
    {
        if(*_string) _string++;
    }
    
    const char& peek () const
    {
        if(*_string)
            return _string[1];
    }
    
    bool done() const { return *_string == '\0'; }
    
    const char& operator *() const { return *_string; }
private:
   const char* _string;   
};

#endif // SPOKEN_CSTR_H