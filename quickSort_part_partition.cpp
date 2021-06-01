#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> & V)
{
    for (auto i = V.begin(); i != V.end(); ++i)
    std::cout << *i << ' ';
    cout << endl;
}

int main()
{
    //vector<int> a = {3,8,2,5,1,4,7,6};
    //vector<int> a = {0,3,8,2,5,1,4,7,6};
    vector<int> a = {10,3,8,2,5,1,4,7,6};
    printVector(a);

    int boundaryIndex = 1; 
    int currentIndex = 1; 

    while (currentIndex < a.size())
    {
        if (a[currentIndex] >= a[0])
        {
            currentIndex++;
        } else
        {
            auto tmp = a[boundaryIndex];
            a[boundaryIndex] = a[currentIndex];
            a[currentIndex] = tmp;
            currentIndex ++;
            boundaryIndex ++;
        }

    }

    auto tmp = a[0];
    a[0] = a[boundaryIndex - 1 ];
    a[boundaryIndex - 1] = tmp;

    printVector(a);


    return 0;
}