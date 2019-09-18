#include "CStr.h"
#include <cstring>

static unsigned _failures = 0;

#define CHECK(cond) if(!(cond) && (++_failures)) \
                           fprintf(stderr, "FAILURE= cond '%s', line: %u\n", #cond, __LINE__)
                           
    


struct CStrTests {
    
    void test_CStr() const {
        CStr a();
        CHECK(a.getLen() == 0);
        CHECK(a[0] == '\0');
    }
    
    void test_CStr2(const char* input) const {
        CStr a(input);
        CHECK(a.getLen() == strlen(input));
        CHECK(strcomp(input, a.getData()) == 0);
    }
}; 
                           
struct CStrIterTests {

    void test_CStrIter_ind() const {
        static const char* TEST_STR1 = "hello!";
        CStrIter it(TEST_STR1);
        CHECK(*it);
    }
};

int main(int argc, char const* argv[])
{
    CStrIterTests iterTests;
    CStrTests strTests;
    
    strTests.test_CStr();
    strTests.test_CStr2();
    iterTests.test_CStrIter_ind();
    return _failures == 0 ? 0 : 3;
}