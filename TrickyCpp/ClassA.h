/*
This class is created only for testing some
tricky subject of C++. So the content of this
class is not so OO(Object Oriented).
*/
class ClassA{
private:
    int iage;
public:
    //int ciAge;
    ClassA(int age)
    {
        iage = age;
        //ciAge = iage;
    }

    int getAge() const
    {
        //iage=-1; we are in a readonly structure
        return iage;
    }
    int getAge()
    {
        iage=-1;
        return iage;
    }
    int getAgeNoConst()
    {
        iage=-1;
        return iage;
    }
};
