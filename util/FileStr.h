#ifndef SPOKEN_FILE_STR_H
#define SPOKEN_FILE_STR_H

#include <cstdio>
#include <cstdlib>
#include <exception>



class FileStr {
public:
    /**
     * In the future, this will handle wide char paths
     */
    FileStr(const char* pathname);
    ~FileStr();
    
    const char* getContents() const { return _contents; }
private:
    size_t _size;
    const char* _contents;
};

#endif // SPOKEN_FILE_STR_H