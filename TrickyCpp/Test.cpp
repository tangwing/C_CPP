#include "ClassA.h"
#include <iostream>
using namespace std;
void testConst()
{
    //A const object will automatically call the const method
    ClassA a1(5);
    cout << "-------------testConst-------------"<<endl;
    cout << "a1.getAge = "<<a1.getAge() << endl;
    const ClassA a2(6);
    cout << "const a2.getAge = "<<a2.getAge() << endl;
    //A const (reference) object can only
    //call a const method.a2.getAgeNoConst();will give an error

    return;
}
