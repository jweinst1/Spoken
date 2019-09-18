#include "CStr.h"

static unsigned _failures = 0;

#define CHECK(cond) if(!(cond) && (++_failures)) \
                           fprintf(stderr, "FAILURE= cond '%s', line: %u\n", #cond, __LINE__)
                           
                           
                           
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
    iterTests.test_CStrIter_ind();
    return _failures == 0 ? 0 : 3;
}