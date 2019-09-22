#ifndef SPOKEN_STR_SEG_H
#define SPOKEN_STR_SEG_H

#include <cstdio>
#include <cstdlib>
#include <cstring>


class StrSeg {
public:
    explicit StrSeg(size_t size);
    StrSeg(const char* data);
    StrSeg(const char* data, size_t size);
    ~StrSeg();
    
    StrSeg(const StrSeg& other);
    
    StrSeg& operator=(const StrSeg& other);
    StrSeg& operator=(const char* string);
    
    size_t size() const { return _size; }
    const char* begin() const { return _data; }
    const char* end() const { return _data + _size; }
    
    bool operator==(const StrSeg& other) const
    {
        return (_size == other._size) && (memcmp(_data, other._data, _size) == 0);
    }
    
    bool operator!=(const StrSeg& other) const
    {
        
        return !(*this == other);
    }
    
private:
    size_t _size; // includes null char
    char* _data;    
};

#endif // SPOKEN_STR_SEG_H