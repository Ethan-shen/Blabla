#include <iostream>
#include "list.cpp"
using namespace std;

int main()
{
    List<int> a;
    for(int i = 1; i <= 5;++i)
        a.push_back(i);
    cout << a._size() << endl;
    cout << a[-1] << endl;

    return 0;

}
