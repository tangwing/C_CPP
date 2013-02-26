#include "stl.h"
class NextNum
{
    int currentNum;
    int intervale;
    public:
    NextNum(int base, int inter)
    {
        currentNum=base;intervale=inter;
    }
    int operator()()
    {
        int res = currentNum;
        currentNum+=intervale;
        return res;
    }
};

struct SortByNumber
{
    bool operator() (const int & a1, const int & a2)
    {
        return a1>a2;
    }
};

bool judge(const int & a1, const int & a2)
{
    return a1>a2;
}

void mysort(int* begin, int*end, bool(*cmp)(const int&,const int&))
{
    int *i,*j;
    for(i = end; i > begin; i--)
    {
        for(j = begin; j < i; j++)
        {
            if(!cmp(*j,*(j+1)))
            {
                int tmp = *j;
                *j = *(j+1);
                *(j+1) = tmp;
            }
        }
    }
}

//
typedef int T;
//template <class T>
void mysort2(std::vector<T>::iterator begin,
            std::vector<T>::iterator end,
            bool(*cmp)(const int&,const int&))
{
    std::vector<T>::iterator  i;
    std::vector<T>::iterator  j;
    for(i = end; i != begin; i--)
    {
        for(j = begin; j != i; j++)
        {
            if(!cmp(*j,*(j+1)))
            {
                T tmp = *j;
                *j = *(j+1);
                *(j+1) = tmp;
            }
        }
    }
}

void tryFoncteur()
{

    std::vector<int> tab(5);
    std::generate(tab.begin(), tab.end(), NextNum(10,5));
    parcourir<std::vector<int>::iterator>(tab.begin(), tab.end());


    //std::sort(tab.begin(), tab.end(), SortByNumber());
    //OU std::sort(tab.begin(), tab.end(), judge);
//    mysort(&tab.front(),&tab.back() , judge);
    mysort2(tab.begin(),tab.end() , judge);
    parcourir<std::vector<int>::iterator>(tab.begin(), tab.end());
}
