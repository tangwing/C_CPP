#include "stl.h"
void tryVector()
{
    using namespace std;
    std::vector<int> iTab(5,1);
    cout<<"vector iTab: isEmpty = "<<iTab.empty()<<endl;
    cout<<"vector iTab: size = "<<iTab.size()<<endl;
    cout<<"vector iTab: capacity = "<<iTab.capacity()<<endl<<endl;

    //iTab.push_front(3);
    iTab.push_back(2);
    cout<<"vector iTab: size = "<<iTab.size()<<endl;
    cout<<"vector iTab: max_size = "<<iTab.max_size()<<endl;
    cout<<"vector iTab: capacity = "<<iTab.capacity()<<endl;

    cout<<"elements -> : ";
    parcourir<std::vector<int>::iterator>(iTab.begin(), iTab.end());
    cout<<"elements <- : ";
    parcourir<std::vector<int>::reverse_iterator>(iTab.rbegin(), iTab.rend());
//    for(std::vector<int>::iterator it = iTab.begin(); it != iTab.end(); it++)
//    {
//        cout<<"\t"<<*it;
//    }

    //cout<<"vector iTab : size = "<<iTab.size()<<endl;
}

void tryDeque()
{
    using namespace std;
    std::deque<int> iTab(5,1);
    cout<<"vector iTab: isEmpty = "<<iTab.empty()<<endl;
    cout<<"vector iTab: size = "<<iTab.size()<<endl;
    //cout<<"vector iTab: capacity = "<<iTab.capacity()<<endl<<endl;

    iTab.push_back(2);
    cout<<"vector iTab: size = "<<iTab.size()<<endl;
    //cout<<"vector iTab: capacity = "<<iTab.capacity()<<endl;

    cout<<"elements -> : ";
    parcourir<std::deque<int>::iterator>(iTab.begin(), iTab.end());
    cout<<"elements <- : ";
    parcourir<std::deque<int>::reverse_iterator>(iTab.rbegin(), iTab.rend());
//    for(std::vector<int>::iterator it = iTab.begin(); it != iTab.end(); it++)
//    {
//        cout<<"\t"<<*it;
//    }

    //cout<<"vector iTab : size = "<<iTab.size()<<endl;
}

//void tryTuple()
//{
//    std::tuple<int, double, std::string> Triple;
//    Triple test(1,2.2, "san");
//    std::string san = std::get<2>(test);
//    std::cout<<san<<std::endl;
//}
