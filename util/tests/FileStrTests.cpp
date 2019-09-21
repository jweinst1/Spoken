#include "FileStr.h"

static unsigned _failures = 0;

#define CHECK(cond) if(!(cond) && (++_failures)) \
                           fprintf(stderr, "FAILURE= cond '%s', line: %u\n", #cond, __LINE__)
                           


/**
 * We still need to close this when we are done using it.
 */
static FILE* __createTempFile(const char* content)
{
    FILE* tfile = tmpfile();
    fputs(content, tfile);
    rewind(tfile);
    return tfile;
}

class FileStrTests {
public:

   void testCons_1() const {
       FILE* f1 = __createTempFile("def a");
       FileStr s1(f1);
       CHECK(s1.getSize() == 5);
       CHECK(strcmp(s1.begin(), "def a") == 0);
   }  
   
   void testEq_1() const {
       FileStr s1(__createTempFile("foo"));
       FileStr s2(__createTempFile("foo"));
       CHECK(s1 == s2);
   }
};

int main(int argc, char const* argv[])
{
    FileStrTests tests;
    tests.testCons_1();
    tests.testEq_1();
    return _failures == 0 ? 0 : 3;
}