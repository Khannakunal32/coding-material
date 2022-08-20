/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//r
#include<bits/stdc++>

using namespace std;

int main()
{
    vector<int> g;
    
    for(auto i=1; i<=5; i++) g.push_back(i*10);
    
    //this assigning give pointer
    cout<<"g.begin() to g.end()    :";
    for(auto i=g.begin(); i<g.end(); i++) cout<<*i<<" ";
    
    cout<<"\ng.cbegin() to g.cend()  :";
    for(auto i=g.cbegin(); i<g.cend(); i++) cout<<*i<<" ";
   
    cout<<"\ng.rbegin() to g.rend()  :";
    for(auto i=g.rbegin(); i<g.rend(); i++) cout<<*i<<" ";
   
    cout<<"\ng.crbegin() to g.crend():";
    for(auto i=g.crbegin(); i<g.crend(); i++) cout<<*i<<" ";
    
    
    cout<<"\nsize()  :"<<g.size();
    cout<<"\ncapacity()  :"<<g.capacity();
    cout<<"\nmax_size()  :"<<g.max_size();
    
    g.resize(4);
    cout<<"\nSize() after resize(4)     :"<<g.size();
    
     if (g.empty() == false)
        cout << "\nVector is not empty (g.empty())";
    else
        cout << "\nVector is empty";
        
        g.shrink_to_fit(); //shrinks the vector
        
        cout<<"\ng.begin() to g.end()    :";
    for(auto i=g.begin(); i<g.end(); i++) cout<<*i<<" ";
    
    
    
    cout<<"\nReference operator g[2]    :"<<g[2];
    cout<<"\nReference operator g.at(3)    :"<<g.at(3);
    cout<<"\ng.front()    :"<<g.front();
    cout<<"\ng.back()    :"<<g.back();
    
    int *pos = g.data();
    cout<<"\n  int *pos = g.data()    :"<<*pos;
    
    
    g.clear();
    cout<<"\nsize() after g.clear()     :"<<g.size();
    
    // fill the array with 10 five times
    g.assign(5,10);
    
    
    //this assigning give position (not pointer)
    cout<<"\n0 to g.size()    :";
    for(auto i=0; i<g.size(); i++) cout<<g[i]<<" ";
    
    g.push_back(15);
    g.push_back(20);
    g.pop_back();
    
    cout<<"\ng.back() after push_back(15) push_back(20) pop_back()  :"<<g.back();
    
    // inserts 5 at the beginning
    g.insert(g.begin(), 5);
    
    cout<<"\ng.front() after  g.insert(g.begin(), 5)  :"<<g.front();
    
    
    // removes the first element
     g.erase(g.begin());
     
      cout<<"\ng.front() after  g.erase(g.begin())   :"<<g.front();
      
      auto k=g.begin();
      g.insert(k+2, 5);
    cout<<"\ng after auto k=g.begin()  g.insert(k+2, 5)   :";
    for(auto i=g.begin(); i<g.end(); i++) cout<<*i<<" ";
    
    
      g.emplace_back(20);
    int n = g.size();
    cout << "\nLast element g[g.size() - 1] after  g.emplace_back(20)       :" << g[g.size() - 1];
    
    
      // two vector to perform swap
    vector<int> v2;
    v2.push_back(3);
    v2.push_back(4);
  
    cout << "\n\ng vector: ";
    for (int i = 0; i < g.size(); i++)    cout << g[i] << " ";
  
    cout << "\nVector 2: ";
    for (int i = 0; i < v2.size(); i++)    cout << v2[i] << " ";
  
    // Swaps v1 and v2
    g.swap(v2);
  
    cout << "\nAfter Swap g.swap(v2) \ng Vector: ";
    for (int i = 0; i < g.size(); i++)    cout << g[i] << " ";
  
    cout << "\nVector 2: ";
    for (int i = 0; i < v2.size(); i++)     cout << v2[i] << " ";


     //resizing with 
    v2.resize(10, 9);
     cout << "\nVector 2 resize with v2.resize(10, 9)     : ";
    for (int i = 0; i < v2.size(); i++)     cout << v2[i] << " ";

    //convert vector in to prifix sum vector  v=1 2 3 => 1 3 6
    g.clear();
    g.push_back(1);  g.push_back(2);  g.push_back(3); 

    partial_sum(g.begin(), g.end(), g.begin());

     cout << "\nVector 2 partial prefix sum after g= 1 2 3  partial_sum(g.begin(), g.end(), g.begin())  : ";
    for (int i = 0; i < v2.size(); i++)     cout << v2[i] << " ";



    //important max element in vector stl
    for(int i=0; i<10; i++) v.push_back(i+1);
    cout<<"v vector have 1 .. 10 number pushed *max_element(v.begin(), v.end()) =>  "<<*max_element(v.begin(), v.end());

    return 0;
}