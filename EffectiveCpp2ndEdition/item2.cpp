/**Item 2
Use more <iostream> rather than <stdio.h>:
1, type safty
2, extensibility

Don't use <iostream.h> which is not under std namespace.
*/
#include <iostream>
using namespace std;
using std::ostream;
class Rational
{
private:
    int n, d;
public:
    Rational(int numerator = 0, int denominator = 1):
        n(numerator), d(denominator){}
    /*Without 'friend', the following is a inner method,
    which should have only one arg*/
    friend ostream& operator<<(ostream& os,const Rational& r)
    {
        os<<r.n<<"/"<<r.d;
        return os;
    }
};
