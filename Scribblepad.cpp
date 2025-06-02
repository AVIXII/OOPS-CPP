#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    set<int> a = {1, 2, 3, 4, 5};
    set<int> b = {3, 4, 5, 6, 7};
    set<int> result;

    a.erase(5);

    for (int x : a)
        cout << x << " ";
}