#include <bits/stdc++.h>

using namespace std;

vector <int> readFromFile(string FileName) 
{
    ifstream fin(FileName);
    
    std::vector<int> data;
    
    int element;
    while (fin >> element)
    {
        data.push_back(element);
    }

    return data;

}

void printVector(vector<int> & V)
{
    for (auto i = V.begin(); i != V.end(); ++i)
    std::cout << *i << ' ';
    cout << endl;
}

vector <int> mergeSort (vector <int> & data) 
{
    vector<int> sorted;
    int n = data.size();

    if (n == 1)
    {
        //cout << "return: " << data[0] << endl;
        return data;
    }

    // if (n == 2)
    // {
    //     if (data[0] < data[1])
    //         return data;
    //     else 
    //     {
    //         sorted[0] = data[1];
    //         sorted[1] = data[0];
    //         return sorted;
    //     }
    // }

    vector<int>::const_iterator begin = data.begin();
    vector<int>::const_iterator middle = data.begin() + n/2 ;
    //vector<int>::const_iterator middleP1 = data.begin() + n/2 +1 ;
    vector<int>::const_iterator last = data.begin() + n;
    vector<int> firstHalf(begin, middle);
    vector<int> secondHalf(middle, last);
    // cout << "1st half un-sorted : " ;
    // printVector(firstHalf);
    // cout << "2nd half un-sorted : " ;
    // printVector(secondHalf);

    auto firstHalfSorted = mergeSort (firstHalf);
    auto secondHalfSorted = mergeSort (secondHalf);
    // cout << "1st half sorted : " ;
    // printVector(firstHalfSorted);
    // cout << "2nd half sorted : " ;
    // printVector(secondHalfSorted);

    int i = 0;
    int j = 0;
    int k = 0;

    while ( i < firstHalfSorted.size() && j < secondHalfSorted.size() )
    {
        // cout << "1st half: "<< firstHalfSorted[i] << " || 2nd half: " << secondHalfSorted[j] << endl;
        if (firstHalfSorted[i] < secondHalfSorted[j]) 
        {
            //sorted[k] = firstHalfSorted[i];
            sorted.push_back(firstHalfSorted[i]);
            k++;
            i++;
        } else 
        {
            //sorted[k] = secondHalfSorted[j];
            sorted.push_back(secondHalfSorted[j]);
            k++;
            j++;
        }
        // cout << sorted[k] << endl;
    }

    if (i == firstHalfSorted.size()) 
    {
        while ( j < secondHalfSorted.size() ) 
        {
            //sorted[k] = secondHalfSorted[j];
            sorted.push_back(secondHalfSorted[j]);
            k++;
            j++;
        }
    } 

    if ( j == secondHalfSorted.size() )
    {
        while (i < firstHalfSorted.size()  )
        {
            //sorted[k] = firstHalfSorted[i];
            sorted.push_back(firstHalfSorted[i]);
            k++;
            i++;
        }
    }

    return sorted;

}

int main()
{

    string fileName = "/app/proj/cpp/coursera/data/IntegerArray.txt";
    
    auto data = readFromFile(fileName);

    cout << data.size() << endl;
    cout << data[0]  <<" " <<  data[1]  << endl;

    auto sorted = mergeSort(data);
    cout << sorted[0] <<" " << sorted[1]  << endl;

    printVector(sorted);

    return 0;
}