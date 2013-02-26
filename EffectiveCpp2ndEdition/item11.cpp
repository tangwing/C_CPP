/**Item 11
    Never forget to define you copy constructor and '='. If this is
really not necessary, put them in private.
*/

/**Item12
    There are big differences between ':a(aa)' and 'a=aa' in constructor. Use
the first one.
*/

/**Item13
1. Vars are inited as their order of declaration, not the order in the init list.
2. Vars of Base classes are inited before subclasses.
3. Multiheritage, order of their heritage, not the order in the init list.
*/
class OrderOfInit
{
private:
    int a;
    int b;
public:
    OrderOfInit(int aa, int bb):a(aa), b(bb){}
    ///Don't do this : OrderOfInit(int aa, int bb):b(bb),a(aa){}
};


/**Item14
    It's an error when trying to delete a object using the pointer of
its father who doesn't have a virtual destructor. Normally the destructor
of this object is never called.
    Almost all Base classes have a virtual destructor.

    Virtual functions are implemented using vptr(virtual pointer) which points
to the vtbl(virtual function table) of the app. A virtual function must be in this table, so declare an inline function virtual
will still let system make a copy of this function. (normally it doesn't exist independently)

*/

/**Item15 return the reference of *this in function 'operator ='
to support continuous affectation.
*/

/**Item16 Deal with all attributes in 'operator ='.
And in subclass, never forget to assign attrs of Base class.
(By calling Base::operator= or by 'static_cast<Base&>(*this)=qqch')

The same thing when creating copy constructor for subclasses.
*/


/**Item17
Don't forget to check 'self' in 'operator='. It's always possible to have surnames
for a same object.
if(this == *rtOBject)return *this;//Addr approche
*/

/**Item18 - 28
争取使类的接口完整并最小
public接口不要出现数据成员
尽量使用const，尽量使用引用传参
不想使用隐式生成的函数就要显式禁止
*/
