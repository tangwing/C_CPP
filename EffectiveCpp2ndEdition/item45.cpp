#include "effectivecpp.h"
/**杂项
C++为空类生成的还有取地址符及const版本

关于默认拷贝函数。对于引用成员及const成员，C++无法自动生成，需要自行定义拷贝函数。
或者当基类将=声明为private时，派生类的=也无法有编译器生成。

“你绝对无法控制不同被编译单元中非局部静态对象的初始化顺序”所以要当心一个变量的初始化
依赖另一个变量时初始化的顺序。注意Singleton的使用

当心包含static变量的函数，在旧版本里如果声明为inline有可能导致多份拷贝。

重视编译器的警告，消除他们
*/
//Test reference count
void testRefCount()
{
    std::string str("Hello!");
    char* data = const_cast<char*>(str.data());
    char & bad = str[0];

    string str2 = str;
    cout<<str<<endl<<str2<<endl;
    data[0] = 'E'; ///modify both str and str2
    //bad = 'F'; ///modify only str
    cout<<str<<endl<<str2<<endl;
}
