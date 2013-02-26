/**
When there is not enough memory...
How to handle 'new' exception?

Use set_new_handler(noMemoryZenMeBan);//header : <new>
*/

#include "effectivecpp.h"


void testNewHandler()
{
    set_new_handler(noMemoryZenMeBan);
    double *big = new double[100000000000000];
//    double *big = new (nothrow)double[100000000000000];
//    if(big == 0)cout<<"Like malloc in C";
}
/**
The new_handler will be executed repeatedly, so it must have one
of these functions:
1, create more mem;
2, register a new handler, or set_new_handler(0)
3, Throw std::bad_alloc or its sub-objects
*/
void noMemoryZenMeBan()
{
    cerr<<"Unable to satify request for memory!\n";
    abort();//Indispensable!!
}

/**How to create new_handler for your class:*/
class NewHandlerTester
{
private:
    static new_handler handler;
public:
    static void outOfMem();
    new_handler setNewHandler(new_handler newh);
    void* operator new(size_t taille)
    {
        new_handler globalHandler = set_new_handler(handler);
        void *mem;
        try{
            mem = ::operator new(taille);
        }catch(std::bad_alloc&)
        {
            set_new_handler(globalHandler);
            throw;
        }

        set_new_handler(globalHandler);
        return mem;
    }
};

new_handler NewHandlerTester::handler;///null default
void outOfMem()
{
    cerr<<"I'm the new_handler of class NewHandlerTester!"<<endl;
    exit(0);
}
new_handler NewHandlerTester::setNewHandler(new_handler newh)
{
    new_handler oldHandler = handler;
    handler = newh;
    return oldHandler;
}


/**How can the 'operator new' of the Base class handle
the 'new' operation of sub-classes. (The same thing should be done for delete)
*/
class Base
{
public:
    void* operator new(size_t size)
    {
        if(size == sizeof(Base))
        {
            ///'New' operation for Base
        }
        else
        {///Let the system new do the job
            return ::operator new(size);
        }
    }
};

/**
    System 'new' = 'operator new' + constructiong of objects.
    'Operator new' can be called directly, it allocate the memory but donot init it.
    'operator new' and 'operator delete' are synonymes of malloc and free, who don't
call constructors and destructors. We can use them when we don't want the constructor
to be called.

Placement new: We now have already a memory, we need new to construct a object in
this memory.
*/
void testPlachementNew()
{
    char buffer[] = "abcdefghi";
    //void* buf2 = operator new(10);

    int * i = new (buffer) int;

    cout<<buffer<<endl;
    *i = 0x37383940;
    cout<<buffer<<endl;
    char a = (char)*i;
    cout<<(int)a<<endl;
}

/** item9
Self-defined multi-parameter 'operator new' will mask the default
new, just like a self-defined constructor will mask the default constructor.
*/
class MultiParaNew
{
public:
//---------------first way---------------
    ///To use this: MultiParaNew *npn = new (para2) MultiParaNew;
    static void* operator new (size_t, new_handler para2);

    ///The following is mandatory for : MultiParaNew *npn = new MultiParaNew;
    static void * operator new (size_t size){return ::operator new(size);}
//---------------second way---------------
    //static void* operator new (size_t, new_handler para2 = 0);
};

