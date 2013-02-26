#include "effectivecpp.h"
/**Item29
Avoid returning a handler of inner data. Otherwise even though
your object is const, his content may still be modified.
*/

/**Item 30
Like item 29, be aware of right privilege.
*/
class Item30;
typedef void (Item30:: * PPMF)();
class Item30
{
private:
    void privateFunction(){ cout<<"I should be private!"<<endl;}
public:
    PPMF getPrivateFunction(){return &Item30::privateFunction;}
};

 void testPrivilegeRaise()
{
    Item30 ITEtest;
    PPMF cible = ITEtest.getPrivateFunction();
    (ITEtest.*cible)();
}

/**Item 31
    Never return a reference of a local object or a newed object.
    Put off the declaration of vars, and try to init the object using a proper
constructor, instead of using the default one and then assign it.
*/

/**Item33 Inline
    Inline = "在编译期间将函数调用用函数体替换"
    Virtual = "在运行时确定实际调用的函数"
    二者是不能共存的。
    而且inline只是对编译器的一个建议，很多编译器对复杂的函数拒绝实施inline。
    内联函数的更改将导致重新编译，而无法动态链接。
    内联函数难以调试。
    总之内联函数并非那么简单直接，应当将其应用于正确的函数上。
*/

/**Item 34 Reduce compilation dependency
Absract interfaces: don't include other header files in a header file. Instead,
just declare the types used. Include a header file means including a type's definition
which produce a dependency.
*/

/**Item 35-38 Object oriented design
    Public inheritance means "is-a"! Think about it when declaring un member function.

    纯虚函数意味着子类“必须继承此接口，但要有自己的实现”。但是纯虚函数还是可以提供一个实现，
而子类必须显式调用它。
    非纯虚函数意味着子类“必须继承此接口，但可以使用缺省实现”。
    非虚函数意味着所有子类都没有必要改变它的实现。

    坚决不要在子类中重新定义非虚函数。与虚函数的动态绑定相反，
这会导致对象的具体行为由指针类型决定，进而产生行为的不确定。
    另外，即使对于虚函数，也不要重新定义它的缺省参数！因为缺省参数是静态绑定的，
也就是说，虽然动态调用了子类中的某个虚函数的实现，但缺省参数却是从基类获得的！！
见下例：
*/
class Base
{
public:
    virtual void printDefaultArg(int arg = 1){cout<<arg<<endl;}
};

class Derived : public Base
{
public:
    void printDefaultArg(int arg = 2){cout<<"fils:";Base::printDefaultArg(arg);}
};

void testVirtualDefaultArg()
{
    Base b;
    Derived d;
    Base* pb = &b;
    pb->printDefaultArg();

    pb = &d;
    pb->printDefaultArg();
}

/**Item 39-43
    任何时候发现自己写出 "如果对象属于类型 T1，做某事；但如果属于类型
T2，做另外某事" 之类的代码，就要扇自己一个耳光。这不是 C++的做法。是
的，在 C，Pascal，甚至 Smalltalk 中，它是很合理的做法，但在 C++中不是。
在C++中，要使用虚函数。

    避免向下的类型转换，逼不得已时使用 dynamic_cast<...>
    一定要弄清两个类的关系为“是一个”还是“用一个来实现”

    继承与模板：当对象的类型不影响类的行为时使用模板，反之使用继承和纯虚函数

    私有继承：完全是实现上的技术，与面向对象的设计无关，继承实现而不继承接口。
应当尽量使用组合，而私有继承只在特殊情况下使用（Generic Stack）。

*/

/**Item43-44
多继承的麻烦：
    二义性
    虚基类的构造参数是由继承树中最底层决定的，而非逐级上升的构造方式。为此
在虚基类中最好不要有数据成员。（java中的接口）
    虚函数的优先级。A->B->C，AB中有同名的虚函数。如果A是纯虚，C将调用B的，否则二义。

    多继承一个很合理的应用：将接口的公有继承和实现的私有继承结合起来。
*/

