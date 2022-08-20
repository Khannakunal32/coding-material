/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<iostream>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

int sumTill(int n) {             //sum till n
    
    if(n==0) return 0;
    return n+sumTill(n-1);
} 

void incOrder(int n){          //increasing order
    if(n==1) {
        cout<<1<<" "; return;
    }
    incOrder(n-1);
    cout<<n<<" ";
}

void decOrder(int n){          // to print in decOrder
    if(n==1) {
        cout<<1<<" "; return;
    }
    cout<<n<<" ";
    decOrder(n-1);
}


int fib(int n){                     //fibonacci series till n
    
    if(n==0 || n==1) return n;

    return fib(n-1)+fib(n-2);

}


int fact(int n) {                         //factorial till n
    if(n==1) return 1;
    
    return n*fact(n-1);
}

int pPowerOfN(int n, int p) {                  // p power of n 
    
    if(p==0) return 1;
    
    int prevPow = pPowerOfN(n,p-1);
    return n*prevPow;
}

int main()
{   int n;
cin>>n;
    
    cout<<"sum till "<<n<<" is =>  "<<sumTill(n)<<endl;
    
    incOrder(n);             
    
    cout<<endl;
    decOrder(n);
    
   cout<<"\n"<<n<<"th fibonacci number is => "<< fib(n);
    
    cout<<"\n factorial of "<<n<<" is =>  "<<fact(n);
    
    int p=5;
    cout<<"\n power of "<<n<<" raise to power "<<p<<" is =>  "<<pPowerOfN(n, p);
    
    
    return 0;
}




//Sort a Stack using recursion                   level 2 (good concept of recursion)
//output    6 5 4 3 2 1          (remember top is at one)
#include <iostream>
#include <stack>

using namespace std;

void insert(stack<int> &x, int ele) {
    
    if(x.empty()==true or x.top()<=ele) {
        x.push(ele);
        return;
    }
    
    int temp = x.top();
    x.pop();
    insert(x, ele);
    x.push(temp);
}

void sortStackRecursively(stack<int> &x){
    if(x.empty()==true) return;
    
    int topEle= x.top();
    x.pop();
    sortStackRecursively(x);
    insert(x,topEle);
    
}

int main()
{
    stack <int> x;
    x.push(1);
    x.push(2);
    x.push(3);
    x.push(4);
    x.push(6);
    x.push(5);
    
    sortStackRecursively(x);
    
    while(x.empty()!=true){
        cout<<x.top()<<" ";
        x.pop();
    }

    return 0;
}




//delete a middle element in stack;
// input stack 5 4 3 2 1
// middle pos is
// 3
// stack after deletion of middle element  => 5 4 2 1 
#include<iostream>
#include<stack>

using namespace std;

int findMid(stack<int> x){
    int count=0;
    if(x.empty()==true) return 0;
    
    while(x.empty()!=true){
        x.pop();
        count++;
    }
    return (count/2) +1;
}

void deleteMid(stack <int> &x, int mid){
    
    if(x.top()==mid) { x.pop();
    return; }
    
    int temp= x.top();
    x.pop();
    deleteMid(x,mid);
    x.push(temp);
}

int main()
 {
     stack <int> x;
    x.push(1);
    x.push(2);
    x.push(3);
    x.push(4);
    x.push(5);
    
    cout<<"\nmiddle pos is =>  "<<findMid(x);
    
   
     deleteMid(x,findMid(x));
     cout<<endl;
      while(x.empty()!=true){
        cout<<x.top()<<" ";
        x.pop();
    }
    return 0;
 }








//printing powerSet / SubSet/ Subsequence of a string using ip/op or recursion tree
// for iput abc
// printing the powerset/subset/subsequence  =>  {} c b bc a ac ab abc 
// printing the powerset/subset/subsequence Lexicographically  =>  a ab abc ac b bc c {} 

#include <iostream>
#include <string>
#include <map>
#include <bits/stdc++.h>

using namespace std;

void powerSet(string ip, string op) {
    
    
    if(ip.length()==0) {
        if(op=="") cout<<"{}"<<" ";
        else
        cout<<op<<" "; 
        return;
    }
    
    string op1=op;
    string op2= op;
    
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    
    powerSet(ip, op1);
    powerSet(ip, op2);
}

void powerSetLexi(string ip, string op, map<string,int> &m) {
    
    
    if(ip.length()==0) {
        if(op=="") m.insert({"{}",1});
        else
        m.insert({op,1});
        return;
    }
    
    string op1=op;
    string op2= op;
    
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    
    powerSetLexi(ip, op1,m);
    powerSetLexi(ip, op2, m);
    

}

int main()
{
   string ip="abc", op="";
   map<string,int> m;
 
cout<<"\nprinting the powerset/subset/subsequence  =>  ";
  powerSet(ip, op);

cout<<"\nprinting the powerset/subset/subsequence Lexicographically  =>  ";
   powerSetLexi(ip, op, m);

    for(auto i=m.begin(); i!=m.end(); i++) 
    cout<<i->first<<" ";
    
    return 0;
}






//Permutation case change using making recursion tree
// for input abc
//abc abC aBc aBC Abc AbC ABc ABC 

void permutationCaseChange(string ip, string op){
    if(ip.length()==0) {
        cout<<op<<" "; return;
    }
    
    string op1= op;
    string op2= op;
     op2.push_back(ip.at(0)-32);       // to change a case from  a->A or any alphabet to captial just  'a'-32 =A
     op1.push_back(ip.at(0));
     ip.erase(ip.begin()+0);
     
     permutationCaseChange(ip, op1);
     permutationCaseChange(ip, op2);
    
}

int main()
{
   string ip="abc", op="";
    
    permutationCaseChange(ip, op);
    

    return 0;
}





//coin change Dp             

 #include<iostream>
 #include<bits/stdc++.h>
 
 using namespace std;
 
 
//  int count(int arr[], int n, int s){
     
//      if(s==0) return 1;
//      if(n==0) return 0;
     
//      if(arr[n-1] <= s)
//      return count(arr, n, s-arr[n-1]) + count(arr, n-1, s);
     
//      else return count(arr,n-1, s);
//  }

// // memoization approach

int mem[1002][1002];

 int count(int arr[], int n, int s){
     
     if(mem[n][s]!=-1) return mem[n][s];
     
     if(s==0) return 1;
     if(n==0) return 0;
     
     if(arr[n-1] <= s)
     return mem[n][s]=count(arr, n, s-arr[n-1]) + count(arr, n-1, s);
     
     else return mem[n][s]=count(arr,n-1, s);
 }
 
 
 
 // //top down approach
//  int count(int arr[], int n, int s){
     
//      int dp[n+1][s+1];
     
//      for(int i=0; i<=n; i++)
//      dp[i][0]=1;
//      for(int j=1; j<=s; j++)
//      dp[0][j]=0;
     
//      for(int i=1; i<=n; i++)
//      for(int j=1; j<=s; j++){
//              if(arr[i-1] <= j)
//       dp[i][j]= dp[i][j-arr[i-1]] + dp[i-1][j];
//      else  dp[i][j]= dp[i-1][j];

//      }
//      return dp[n][s];
     
//  }
 
int main()
{   
    // kali();
    
memset(mem, -1, sizeof(mem));
    int i, j;
    int arr[] = { 1, 2, 3 };
    int m = sizeof(arr) / sizeof(arr[0]);
     
    cout << " " << count(arr, m, 4);
     
    return 0;
}