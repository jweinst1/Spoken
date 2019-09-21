#ifndef SPOKEN_FILE_STR_H
#define SPOKEN_FILE_STR_H

#include <cstdio>
#include <cstdlib>
#include <cstring>




class FileStr {
public:
    /**
     * In the future, this will handle wide char paths
     */
    FileStr(const char* pathname);
    /**
     * This closes the fp passed into it.
     */
    FileStr(FILE* fp);
    ~FileStr();
    
    const char* begin() const { return _contents; }
    const char* end() const { return _contents + _size; }
    
    size_t getSize() const { return _size; }
    
    const char operator[](size_t index) const 
    {
        return ( index >= _size) ? '\0' : _contents[index];
    }
    /**
     * Does not compare based off file path, only the contents
     */
    bool operator==(const FileStr& other) const
    {
        return (_size == other._size) && (strcmp(_contents, other._contents) == 0);
    }
    
    bool operator!=(const FileStr& other) const
    {
        return !(*this == other);
    }
    
private:
    size_t _size;
    const char* _contents;
};

#endif // SPOKEN_FILE_STR_H