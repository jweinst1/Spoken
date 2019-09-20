#include "FileStr.h"

static void __getFileSize(FILE* fp, size_t* ds)
{
    fseek(fp, 0L, SEEK_END);
    *ds = ftell(fp);
    rewind(fp);
}


FileStr::FileStr(const char* pathname)
{
    FILE* fp;
    fp = fopen(pathname, "r");
    if(fp == NULL) {
        _contents = nullptr;
        _size = 0;
    } else {
        __getFileSize(fp, &_size);
        char* buf = new char[_size + 1]();
        fread(buf, _size, 1, fp);
        _contents = buf;
    }
}

FileStr::~FileStr()
{
    delete[] _contents;
}