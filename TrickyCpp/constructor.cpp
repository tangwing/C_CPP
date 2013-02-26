#include <stdio.h>
class C_G1{
public:
    C_G1(){printf("I'm in C_G1().\n");}
    C_G1(C_G1 & o){printf("I'm in C_G1(C_G1 &).\n");}
    C_G1(int i){printf("I'm in C_G1(int).\n");}
    operator int()
    {
        printf("I'm in C_G1 operator  int().\n");
        return 4;
    }
};

class C_G2 : public C_G1{
int iVal;
double dVal;
public:
    C_G2(){}
    C_G2(int in)
    {printf("I'm in C_son(int).\n");}
    C_G2(double in)
    {printf("I'm in C_son(double).\n");}
    C_G2(C_G2 & o):C_G1(o){printf("I'm in C_G2(C_G2 &).\n");}

};

class C_G3 : public C_G2{
public:
    C_G3(){printf("I'm in C_G3().\n");}
    C_G3(int i){printf("I'm in C_G3(int).\n");}
    operator int()
    {
        return 4;
    }
};

void testConstructorCallOrder()
{
    //C_G2 o;
    //C_G2 o2(o);
    //m(1);
    //f('c');
    //C_Sunzi s;
    //son_grandma(s);
    C_G1 a, b=a;
    //C_G3 c;
    b = a+b;
}
