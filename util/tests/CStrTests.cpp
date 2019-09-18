#include "CStr.h"

static unsigned _failures = 0;

#define CHECK(cond) if(!(cond) && (++_failures)) \
                           fprintf(stderr, "FAILURE= cond '%s', line: %u\n", #cond, __LINE__)
                           
                           
                           
class CStrIterTests {
    static const char* TEST_STR1 = "hello!";
    
    void test_CStrIter_ind() const {
        CStrIter it(TEST_STR1);
        CHECK(*it);
    }
}

int main(int argc, char const* argv[])
{
    CStrIterTests iterTests;
    iterTests.test_CStrIter_ind();
    return _failures == 0 ? 0 : 3;
}