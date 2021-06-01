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

long long int	 inversion (vector<int> & data)
{
    long long int	 count = 0;

    int n = data.size();

    for (int i = 0; i < n ; i ++ )
    {
        for (int j = i + 1; j < n; j ++ )
        {
            if (data[i] > data[j])
            {
                count ++ ;
                //cout << data[i] << " > " << data[j] << endl;

            }
                
        }
    }

    return count;
}

void printVector(vector<int> & V)
{
    for (auto i = V.begin(); i != V.end(); ++i)
    std::cout << *i << ' ';
    cout << endl;
}



int main()
{

    string fileName = "/app/proj/cpp/coursera/data/IntegerArray.txt";
    
    auto data = readFromFile(fileName);

    
    cout << data.size() << endl;
    cout << data[0]  <<" " <<  data[1]  << endl;
    //printVector(data);
    auto s = inversion(data);


    cout << s << endl;

    return 0;
}