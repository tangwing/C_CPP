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

void tryCopy()
{

   // NextNum nn(10,3);
    std::vector<int> iTab(10);
    std::generate(iTab.begin(), iTab.end(), NextNum(10,5));
    parcourir<std::vector<int>::iterator>(iTab.begin(), iTab.end());
    std::copy(iTab.begin(), iTab.end(), std::ostream_iterator<int>(std::cout, ", "));
}

void tryStringFind()
{
    std::ostringstream oss(std::ostringstream::out);
    oss<<"ls -l | wc -w";

    std::string cmd = oss.str();
    std::string mem1(10,' ');
    std::copy(cmd.begin(), std::find(cmd.begin(), cmd.end(), '|'), mem1.begin());

    std::cout<<"cmd : "<<cmd<<std::endl;
    std::cout<<"membre1 : "<<mem1<<std::endl;
}


