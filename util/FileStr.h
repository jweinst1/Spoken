#ifndef SPOKEN_FILE_STR_H
#define SPOKEN_FILE_STR_H

#include <cstdio>
#include <cstdlib>


class FileStr {
private:
    size_t _size;
    const char* _contents;
};

#endif // SPOKEN_FILE_STR_H