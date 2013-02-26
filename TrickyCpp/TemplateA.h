template<class T> class Vector
{
private:
    T length;
 public:
    Vector<T>()
    {
        length = 11;
    }
    T getLength() const//This is a const function
    {
        //length = 1;
        return length;
    }

    void setLength(T l)
    {
        length = l;
    }

};
