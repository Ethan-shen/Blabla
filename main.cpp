#include <iostream>
#include "list.cpp"
#include <list>
using namespace std;
int main()
{
    List<int> a;
    for(int i = 1; i <= 100000;++i)
        a.push_back(i);


    list<int> b;
    for(int i = 1; i <= 100000;++i)
        b.push_back(i);

    return 0;

}
