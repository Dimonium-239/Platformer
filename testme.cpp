#include "testme.h"

TestMe::TestMe(std::string write)
{
    str = write;
}

int TestMe::test1(int a, float b){
    return a + int(b);
}

std::string TestMe::test2(int a, std::string b){
    std::string m;
    for (int i = 0; i < a; i++) {
        m += b;
    }
    return m;
}
