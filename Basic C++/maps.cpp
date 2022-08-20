
#include <iostream>
// #include <bits/stdc++.h>
#include <map>

using namespace std;


int main()
{
  map <string, int> mymap;
  
  //intializing method 1 
  
  mymap["a"]=1;  // a and b in next line can not be same as it is key value and key value must never be same 
  mymap["b"]=1;  
  
  cout<<"\n mymap['a']=1; mymap['b']=2 now using count itr->first  itr->second => \n";
  
  for(auto i=mymap.begin(); i!=mymap.end(); i++) 
  cout<<i->first<<" = "<<i->second<<"\n";


    //intializing method 2 
    
    mymap = { {"india",1},          // this will overide the previous initialization , as it does not insert values , it rather remove and overwrite
              {"china",2} };      // this will be output china first as key value is in lexographical order of key value
              
  cout<<"\n mymap = { {\"india\",1}, {\"china\",2} };  (shown according to lexographical order of key)   => \n";

for(auto i=mymap.begin(); i!=mymap.end(); i++) 
  cout<<i->first<<" = "<<i->second<<"\n";
  
  
  
//intializing method 3       // this will insert value into previous intializaition
    
    mymap.insert(make_pair("england",3));    // this will be shown after china and before india because of lexographical
    
  cout<<"\n mymap.insert(make_pair(\"america\",1));  => \n";
for(auto i=mymap.begin(); i!=mymap.end(); i++) 
  cout<<i->first<<" = "<<i->second<<"\n";
  
  
  
//intializing method 4       // this will insert value into previous intializaition
  
  mymap.insert({"africa",4});
  
  cout<<"\n mymap.insert({\"africa\",4});  => \n";
  
for(auto i=mymap.begin(); i!=mymap.end(); i++) 
  cout<<i->first<<" = "<<i->second<<"\n";
  
  
  //size()
  
  cout<<"\n\n mymap.size() =>   "<<mymap.size();
  cout<<"\n mymap.max_size() =>   "<<mymap.max_size();
  
  
  //initialization of another map
   
   map <string, int> m1;
   
   m1.insert( mymap.begin(), mymap.end());
   
  cout<<"\n\n\n  m1.insert( mymap.begin(), mymap.end()); => \n";
for(auto i=m1.begin(); i!=m1.end(); i++) 
  cout<<i->first<<" = "<<i->second<<"\n";
  
  
  
  mymap.clear();           //clears everything in map
  cout<<"\n\n mymap.clear();  mymap.empty() =>    "<<mymap.empty();
  
  
  //erase a specefic key from map           important !!!!!!!!!!
  map <int, char> m2= {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}};
  
  auto itr= m2.find(3); // finds and put the pointer at the key location 
  m2.erase(itr);
  
  
  cout<<"\n\n\n auto itr= m2.find(3); m2.erase(itr);  => \n";
for(auto i=m2.begin(); i!=m2.end(); i++) 
  cout<<i->first<<" = "<<i->second<<"\n";
  
  
  
  // checks if key 4 is present or not and returns count with keys = 4;
  m2.insert({4, 'x'});
  m2.insert({4, 'm'});
  
  cout<<"\n\n\n check if key 4 is present in m2 if(m2.count(4)) cout<<..  => \n";
    if (m2.count(4))
        cout << "The key 4 is present in m2\n";
    else
        cout << "The key 4 is not present in m2\n";
        
        
    // emplace()
    map <int, int> m3;
    
    m3.insert({0,1});
    m3.emplace(1,2);
    m3.emplace(2,3);
    m3.emplace(1,4);    //will only give the first value with key=1 initialized so this will be ignored
    m3.emplace(4,5);
    cout<<"\n\n\n  m3.emplace(1,2);....skips m3.emplace(1,4) as only considers with first key value initialized  => \n";
for(auto i=m3.begin(); i!=m3.end(); i++) 
  cout<<i->first<<" = "<<i->second<<"\n";
        
    
    //map upper_bound()
    // The mapname.upper_bound() is a built-in function in C++ STL which returns an iterator pointing to the immediate next element just greater than k. If the key passed in the parameter exceeds the maximum key in the container, then the iterator returned points to the number of elements in the map container as key and element=0.
    auto iter = m3.upper_bound(2);
    cout<<"\n\n\n auto iter = m3.upper_bound(2); (*iter).first; iter->second; => \n"<<(*iter).first<<" "<<iter->second;
    
    
    
    
    //map lower_bound()
    //The map::lower_bound(k) is a built-in function in C++ STL which returns an iterator pointing to the key in the container which is equivalent to k passed in the parameter.
    
    iter = m3.lower_bound(2);
    cout<<"\n\n\n auto iter = m3.lower_bound(2); (*iter).first; iter->second; => \n"<<(*iter).first<<" "<<iter->second;
    
    
    iter = m3.lower_bound(6);
    cout<<"\n\n\n auto iter = m3.lower_bound(6); (*iter).first; iter->second this will return number of keys and 0 as element as it doesn't exist; => \n"<<(*iter).first<<" "<<iter->second;  //same for upperbound and other functions
    
    
    
    
    //swap() swap(m1,m2) swaps and also m1.swap(m2)
    
    cout<<"\n\n\n swap(m1,m2) swaps and also m1.swap(m2) \n";  
    
    
    //mapname.at()
    
    mymap.clear();
    mymap={{"india",1},{"england",2}};
    
    cout<<"\n\n\n mymap={{\"india\",1}, {\"england\",2}};  mymap.at(\"india\") =>  \n"<<mymap.at("india");
    
    
    return 0;
}

// map rend() function in C++ STL– Returns a reverse iterator pointing to the theoretical element right before the first key-value pair in the map(which is considered its reverse end).
// map rbegin() function in C++ STL– Returns a reverse iterator which points to the last element of the map.
// map crbegin() and crend() function in C++ STL– crbegin() returns a constant reverse iterator referring to the last element in the map container. crend() returns a constant reverse iterator pointing to the theoretical element before the first element in the map.
// map cbegin() and cend() function in C++ STL– cbegin() returns a constant iterator referring to the first element in the map container. cend() returns a constant iterator pointing to the theoretical element that follows last element in the multimap.
// The mapname.upper_bound() is a built-in function in C++ STL which returns an iterator pointing to the immediate next element just greater than k. If the key passed in the parameter exceeds the maximum key in the container, then the iterator returned points to the number of elements in the map container as key and element=0.
//