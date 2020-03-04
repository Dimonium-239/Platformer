#ifndef TESTME_H
#define TESTME_H
#include <iostream>

class TestMe
{
    std::string str;
public:
    TestMe() = default;
    TestMe(std::string write);
    int test1(int a, float b);
    std::string test2(int a, std::string b);
    std::string retString(){return str;}
};

#endif // TESTME_H
