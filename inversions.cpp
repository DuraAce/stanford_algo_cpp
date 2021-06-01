#include <bits/stdc++.h>

using namespace std;

struct sortAndCount {
    unsigned long long int  count;
    vector<int> sorted;
};
  

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

sortAndCount inversion (vector <int> & data) {
    sortAndCount s;



    int n = data.size();

    if (n == 1)
    {
        //cout << "return: " << data[0] << endl;
        s.count = 0;
        s.sorted.push_back(data[0]);
        return s;
    }

        
    vector<int>::const_iterator begin = data.begin();
    vector<int>::const_iterator middle = data.begin() + n/2 ;
    vector<int>::const_iterator last = data.begin() + n;
    vector<int> firstHalf(begin, middle);
    vector<int> secondHalf(middle, last);

    auto firstHalfSorted = inversion (firstHalf);
    auto secondHalfSorted = inversion (secondHalf);

    s.count =  firstHalfSorted.count + secondHalfSorted.count;
    // cout<< "current count before merge: " << s.count << endl;

    int i = 0;
    int j = 0;
    int k = 0;

    while ( i < firstHalfSorted.sorted.size() && j < secondHalfSorted.sorted.size() )
    {
        // cout << "1st half: "<< firstHalfSorted[i] << " || 2nd half: " << secondHalfSorted[j] << endl;
        if (firstHalfSorted.sorted[i] <= secondHalfSorted.sorted[j]) 
        {
            //sorted[k] = firstHalfSorted[i];
            s.sorted.push_back(firstHalfSorted.sorted[i]);
            k++;
            i++;
            s.count += j;
        } else 
        {
            //sorted[k] = secondHalfSorted[j];
            s.sorted.push_back(secondHalfSorted.sorted[j]);
            //cout <<firstHalfSorted.sorted[i]  << " > " << secondHalfSorted.sorted[j] << endl;
            k++;
            j++;

        }
        // cout << sorted[k] << endl;
    }

    if (i == firstHalfSorted.sorted.size()) 
    {
        while ( j < secondHalfSorted.sorted.size() ) 
        {
            //sorted[k] = secondHalfSorted[j];
            s.sorted.push_back(secondHalfSorted.sorted[j]);
            k++;
            j++;
        }
    } 

    if ( j == secondHalfSorted.sorted.size() )
    {
        while (i < firstHalfSorted.sorted.size()  )
        {
            //sorted[k] = firstHalfSorted[i];
            s.sorted.push_back(firstHalfSorted.sorted[i]);
            //cout << firstHalfSorted.sorted[i] << " pushed! size of j: " << secondHalfSorted.sorted.size()  << endl;
            k++;
            i++;
            s.count += j;;
        }
    }

    // s.count = s.count + firstHalfSorted.count + secondHalfSorted.count;

    //cout<< "current count afer merge: " << s.count << endl;
    return s;
}


int main()
{

    string fileName = "/app/proj/cpp/coursera/data/IntegerArray.txt";
    
    auto data = readFromFile(fileName);

    cout << data.size() << endl;


    auto s = inversion(data);


    cout << s.count << endl;
    //printVector(data);
    //printVector(s.sorted);

    return 0;
}