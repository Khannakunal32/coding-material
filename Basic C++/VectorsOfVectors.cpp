// #include<bits/stdc.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<vector<int>> vec;

    int num = 10;
    int row = 5, col = 5;

    //intializing a vector of vector
    for (int i = 0; i < row; i++)
    {

        vector<int> v; // creating a new vector everytime

        for (int j = 0; j < col; j++)
        {
            v.push_back(num);
            num += 10;
        }

        vec.push_back(v);
    }

    //printing a vector of vector
    for (auto i = 0; i < vec.size(); i++)
    {
        for (auto j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    //pop_back a vector of vector

    vec[0].pop_back();
    vec[2].pop_back();
    vec.pop_back();

    //printing a vector of vector using pointer
    cout << endl;
    for (auto i = 0; i < vec.size(); i++)
    {
        for (auto j = vec[i].begin(); j < vec[i].end(); j++)
        {
            cout << *j << " ";
        }
        cout << endl;
    }

    return 0;
}


//https://www.geeksforgeeks.org/how-to-flatten-a-vector-of-vectors-or-2d-vector-in-c/?ref=rp