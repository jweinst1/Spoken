#include "StrSeg.h"

static unsigned _failures = 0;

#define CHECK(cond) if(!(cond) && (++_failures)) \
                           fprintf(stderr, "FAILURE= cond '%s', line: %u\n", #cond, __LINE__)
                           
                           

class StrSegTests {
public:
    void testCons() const {
        StrSeg a("bat");
        CHECK(a.size() == 3);
        CHECK(strcmp(a.begin(), "bat") == 0);
    }
    
    void testAssign() const {
        StrSeg a("3333");
        StrSeg b = a;
        CHECK(a.size() == b.size());
        CHECK(strcmp(a.begin(), b.begin()) == 0);
    }
};                         

int main(int argc, char const* argv[]) {
    StrSegTests tests;
    
    tests.testCons();
    tests.testAssign();
    return _failures == 0 ? 0 : 3;
}