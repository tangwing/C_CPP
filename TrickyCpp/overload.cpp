/*
*
*/
#include <stdio.h>
class C_Mother{


};

class C_Son : public C_Mother{
int iVal;
double dVal;
public:
    C_Son(){printf("I'm in C_son().\n");}
    C_Son(int in)
    {
        printf("I'm in C_son(int).\n");
    }
    C_Son(double in)
    {printf("I'm in C_son(double).\n");}
private:
int i;

};

class C_Sunzi : public C_Son{

public:
    C_Sunzi(){}
};

void m(C_Mother mom)
{
    printf("I'm in function m.\n");
}

void f(char i)
{

    printf("I'm in function f(char).\n");
}

void f(C_Son s)
{
    printf("I'm in function f(C_son).\n");
}

void son_grandma(C_Mother cm)
{
    printf("I'm in function son_grandma(C_Mother cm).\n");

}

void level3(char c)
{
    printf("I'm in function level3(char).\n");
}

void level3(C_Son c)
{
    printf("I'm in function level3(C_Son).\n");
}

//used to test (N2,N3A)
void level3a3b(double )//d, char c)
{
    printf("I'm in function level3a3b(double d, char c).\n");
}
//used to test (N1,N3B)
void level3a3b(char c)//, C_Son s)
{
    printf("I'm in function level3a3b(char c, C_Son s).\n");
}
void testOverload()
{
//    C_Son cs(1);
//    //m(1);
//    f('c');
//    C_Sunzi s;
//    son_grandma(s);
    //level3(1.0);
    //level3a3b('a',7.0);
    //float f=1.0f;
    //level3a3b(1);
    C_Son s1, s2 = s1;
}
