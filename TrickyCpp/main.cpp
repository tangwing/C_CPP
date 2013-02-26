#include "ClassA.h"
#include "TemplateA.h"
#include "Test.h"
#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    //
    //testConst();
    //testOverload();
    //testConstructorCallOrder();
    //testNewDelete();
    testCasts();
    string s = "qdsf";
        cout<<typeid(s).name();
    return 0;
}
