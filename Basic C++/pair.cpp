//output
//  kali 1
//  geeks 2.5
//  abcd 3
//  this is p3 after p1.swap(p3) => kali 1
//  this is string a and int b after tie(a,b)=p3 =>  kali 1
//  this is d after d=3 tie(ignore, d)= p3 => 1

//  this is p4 after pair < pair<string, int>, int> p4 
//  p4.second= 4; p4.first.first="kali"; =>        kali 0 4

//  p4 after p4={{"kunal",1},4};  =>  kunal 1 4

#include <iostream>
#include <utility>
#include <bits/stdc++.h>  //for tie

using namespace std;

int main()
{
   
    //intializing techniques
    
    pair <string, int> p1 = {"kali", 1};
    cout<<"\n "<<p1.first<<" "<<p1.second;
    
    
    pair <string, double> p2; 
    p2= make_pair("geeks",2.5);
    cout<<"\n "<<p2.first<<" "<<p2.second;
    
    pair<string, int> p3; 
    p3= {"abcd", 3};
    cout<<"\n "<<p3.first<<" "<<p3.second;
    
    p1.swap(p3);
    cout<<"\n this is p3 after p1.swap(p3) => "<<p3.first<<" "<<p3.second;
    
    string a; int b;
    tie(a,b) = p3;
    cout<<"\n this is string a and int b after tie(a,b)=p3 =>  "<<a<<" "<<b;
    
    // p3=make_pair("kali",3);
    
    int d=3;
    tie(ignore,d) = p3;
    cout<<"\n this is d after d=3 tie(ignore, d)= p3 => "<<d<< endl;
    
    
    //pair inside pair
    
    pair < pair<string, int>, int> p4;
    
    p4.second= 4;
    p4.first.first="kali";
    cout<<"\n this is p4 after pair < pair<string, int>, int> p4 \n p4.second= 4; p4.first.first=\"kali\"; =>        "<<p4.first.first<<" "<<p4.first.second<<" "<<p4.second;
    
    p4={{"kunal",1},4};
    cout<<"\n\n p4 after p4={{\"kunal\",1},4};  =>  "<<p4.first.first<<" "<<p4.first.second<<" "<<p4.second;
    
    return 0;
}




                                    //level 2
//concept of pair with vector and comparator
// return an array with position of sorted elements eg               // apna college vector and pair video 48
//input 10 16 17 14 5 3 12 9
//output 3  6  7  5 1 0  4 2     // here 0 is at place of 3 to show that it is smallest then 1 is on 5 and so on
bool myComparator(pair<int,int>p1, pair<int,int>p2) {       //comparator is of bool type
    return p1.first<p2.first;
}

int main()
{
   
    //intializing techniques
    
    int arr[]={10, 16, 17, 14, 5, 3, 12, 9};
    int n = sizeof(arr)/ sizeof(arr[0]);
    
    vector< pair <int,int> > v;
    pair <int,int> p;
    
    for(int i=0; i<n; i++) {
        p={arr[i],i};
        v.push_back(p);
    }
    sort(v.begin(), v.end(), myComparator);
    
    for(auto i=0; i<v.size(); i++) {
        arr[v[i].second]=i;
    }
    
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    
    
        
    return 0;
}
