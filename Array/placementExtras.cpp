#include <bits/stdc++.h>

using namespace std;


//max till i                                level 1
// 11     1 5 2 9 6 7 12 4 2 0 2
// 1 5 5 9 9 9 12 12 12 12 
int main()
{
    int arr[] = { 1, 5, 2, 9, 6, 7, 12, 4, 2, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
        
        int mx=INT_MIN;
        
        for(int i=0; i<n; i++) {
            
            if(arr[i]>mx) mx=arr[i];
            
            cout<<mx<<" ";
        }
        
    return 0;
}




//sum of subarrays                           level 1
//  int arr[] = { 1, 5, 2, 9 };
// 1 6 8 17 5 7 16 2 11 9                              //n(n-1)/2 +n number of subarrays

int main()
{
    // int arr[] = { 1, 5, 2, 9, 6, 7, 12, 4, 2, 0 };
    int arr[] = { 1, 5, 2, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
        
       
        
        for(int i=0; i<n; i++) {
             int sum=0;
             
            for(int j=i; j<n; j++) {
                sum=sum+arr[j];
                cout<<sum<<" ";
            }
            
        }
        
    return 0;
}







//print number of longest arithamatic subarray               level 2
//10  11 10 9 11 21 31 41 51 55 32
// 5
int main()
{
    // int arr[] = { 1, 5, 2, 9, 6, 7, 12, 4, 2, 0 };
    // int arr[] = { 1, 5, 2, 9 };
    // int n = sizeof(arr) / sizeof(arr[0]);
        
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    
    int count=2 , diff=a[1]-a[0], mx=-1;
    
    if(n<=2) {
        cout<<"2";
        return 0;
    }
    
    for(int i=1; i<=n-2; i++) {
        
        if(diff==a[i+1]-a[i]) ++count;
        
        else {
            count =2;
            diff=a[i+1]-a[i];
        }
        mx= max(mx,count);
        
    }
    
        cout<<mx<<" ";
        
        
        
    return 0;
}








//Arrays Challenge-Record Breaker                  // level 2 good
// (Google kickstart)
// 5  1 2 0 7 2 0 2 2
// 2


int main()
{
        
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    
    int count=0 , mx=-1;
    arr[n]=-1;
    
    for(int i=0; i<n; i++) {
        
        if(arr[i]>mx && arr[i]>arr[i+1]) count++;
        
        mx= max(mx,arr[i]);
    }
    
        cout<<count;
        
    return 0;
}






//Find the smallest positive missing number in the given array.         level 2
// Example: [0, -10, 1, 3, -20], Ans = 2
int main() {
    int n; cin>>n; int arr[n];
     for(int i=0; i<n ; i++) cin>>arr[i];
    
    int m= 1e6 +2;  // creating an array m
    int narr[m];
    
    //initializing with 0 
    for(int i=0; i<m; i++) narr[i]=0;
    
    for(int i=0; i<n; i++) {
        if(arr[i]>=0) narr[arr[i]]=1; 
    }
    
    for(int i=0; i<m; i++) {
        if(narr[i]==0) {
            cout<<i; break;
        } 
    } 
    
    return 0;
}









                                                // Level 3 
// Problem                                            
// Given an array arr[] of size N. The task is to find the first repeating element in an
// array of integers, i.e., an element that occurs more than once and whose index of
// first occurrence is smallest.
// Constraints
// 1 <= N <= 106
// 0 <= Ai <= 106
// Example
// Input:
// 7
// 1 5 3 4 3 5 6
// output: 2

int main() {
    int n; cin>>n; int arr[n];
     for(int i=0; i<n ; i++) cin>>arr[i];
    
    int m= 1e6 +2;  // creating an array m
    int narr[m];
    int mn=INT_MAX;
    // int mn=20;  //10 10 30 30 40 60 10 3 5 8 1
    
    //initializing with -1
    for(int i=0; i<m; i++) narr[i]=-1;
    
    for(int i=0; i<n; i++) {
        if(narr[arr[i]]==-1) {
        narr[arr[i]]=i;
        } else mn=min(mn,narr[arr[i]]);
  }
    
    if(mn==INT_MAX) cout<<"-1";
    else cout<<mn+1;
        
    
    return 0;
}









                 /// level 3 difficult

//Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.
vector<int> subarraySum(int arr[], int n, long long key){   
 // Your code here
        int st=0, en=1;
        long long sum;
        sum=arr[st]+arr[en];
         
    if(arr[0]==key) {
         vector<int> res;
    res.push_back(1);
    res.push_back(1);
    return res;
    }
    
    
     while(en<n || st<n || st<=en) {
         
         if(sum==key) 
             break;
         
         while(sum<key) {
             en++;
             sum+=arr[en];
         }
         
         while (sum>key) {
             sum-=arr[st];
             st++;
         }
         
     }

    vector<int> res;
    res.push_back(st+1);
    res.push_back(en+1);
    
    if(st>en || sum!=key) {
        res.clear();
        res.push_back(-1);
    }
    
    
    return res;
    }









//print all subarray                    //level 1

//     4 -1 4 7 2
// -1 
// -1 4 
// -1 4 7 
// -1 4 7 2 

// 4 
// 4 7 
// 4 7 2 

// 7 
// 7 2 

// 2 


int main() {   //8 2 4 7 11 14 16 20 21
//5 1 2 3 7 5
      int n; cin>>n; int arr[n];
      long long key;
     for(int i=0; i<n ; i++) cin>>arr[i];

        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                for(int k=i; k<=j; k++)
                cout<<arr[k]<<" ";
                cout<<endl;
            }
            cout<<endl;
        }
 
 
     return 0;
}









//kadanes algorithm                     //level 2 important

int kadanes(int arr[], int n) {
    
    int sum=0, mx=INT_MIN;
    
    for(int i=0; i<n; i++) {
        sum+=arr[i];
        if(sum<0) sum=0;
        
        mx=max(sum,mx);
    }
    
    return mx;
}

int main() {   
//6 -1 4 -6 7 5 -4
      int n; cin>>n; int arr[n];
      for(int i=0; i<n; i++) cin>>arr[i];

      cout<<kadanes(arr,n);
     return 0;
}






                                            //level advance of kadanes
// maximum circular subarray sum with kadanes

//7   4 -4 6 -6 10 -11 12
//22

int main() {   
//6 -1 4 -6 7 5 -4
      int n; cin>>n; int arr[n];
      for(int i=0; i<n; i++) cin>>arr[i];
      
      int totalArrSum=0;
      for(int i=0; i<n; i++) totalArrSum+=arr[i];
      
      //reversing sign of array
      for(int i=0; i<n; i++) arr[i]*=-1;
      
      int nonWrapSum=kadanes(arr,n);
    
    int maxCircularSum = totalArrSum + nonWrapSum;
    cout<<maxCircularSum;
 
     return 0;
}








                                            level 2
// find if there is a pair with given sum
//8 2 4 7 11 14 16 20 21
// Enter the key to find sum of
// 31
// 3 6
int pairSum(int arr[], int n, int key) {
    int st=0,en=n-1, sum=0;
    
    while(st<en) {
        
        sum=arr[st]+arr[en];
    
        if(sum==key) { cout<<st<<" "<<en;
        break; }
        
        if(sum>key) en--;
        else if(sum<key)  st++;
        }
        
    return 0; 
}

int main() {   
      int n; cin>>n; int arr[n];
      for(int i=0; i<n; i++) cin>>arr[i];
      
      int key;
      cout<<"\nEnter the key to find sum of\n";
      cin>>key;
      
      pairSum(arr,n,key);

      return 0;
}










//prime factorization using seive of eratosthenes        level 3
// eg input 20 output 2 2 5 

// maintain an array with smallest prime factor filled eg for n=20 array will be 
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20  // inital array in first loop statement
// 0 1 2 3 2 5 2 7 2 3  2 11  2 13  2  3  2 17  2 19  2  // final array in second double loop statement
// now let n=20 , if we devide 20/spf ie smallestprimefactor  20/2 =10  then 10/spf= 10/2 =5   then 5/spf= 5/5 =1 
//we can print these spf to get prime factor of n
#include <iostream>
#include <vector>

using namespace std;

void primeFactorize(int n) {
    // vector <int> v[n];
    int spf[n+1];
    
    for(int i=0; i<=n; i++) spf[i]=i;        // filling array with the same number as number is prime factor of it self
    
    for(int i=2; i*i<=n; i++) {
        if(spf[i]==i) 
        for(int j=i*i; j<=n; j+=i) {
            
            if(spf[j]==j) spf[j]=i;
        }
    }
    
    while(n!=1) {
        cout<<spf[n]<<" ";
        n= n/spf[n];
    }
}

int main()
{ int n; cin>>n;
    primeFactorize(n);
    
    return 0;
}




//Inclusion Exclusion principle        //level 1
// In many questions, we are required to include contributions of more than one
// term in our answer. This results in inclusion of the same term more than once,
// hence we use the principle of inclusion exclusion.

// Question
// Find the number of numbers in the interval [1,n] which are divisible by a or b.
// Approach
// We calculate the number of numbers divisible by a and b separately and then
// subtract the number of numbers which are divisible by both a and b.
// input 5 2 5
// output 3
int countOfNumDivisible(int n,int a, int b) {
    int c1= n/a;
    int c2= n/b;
    int c3= n/(a*b);
    
    return c1+c2-c3;
    
}

using namespace std;

int main()
{
    int n, a, b;      
    cin>>n>>a>>b;
    cout<<"number of numbers divisible till "<<n<<" by both "<<a<<" and "<<b<<endl;
    cout<<countOfNumDivisible(n,a,b);

    return 0;
}



//highest common factor or GCD
// We use the logic that
// gcd(a,b) = gcd(b,a%b)

//input 100 80
//ouput20
int gcd(int a, int b) {
    
    int rem=-1;
    while(rem!=0) {
        rem = a%b;
        a=b;
        b=rem;
    }
    
    return a;
    
}

using namespace std;

int main()
{ // 10 20
    int  a, b;      
    cin>>a>>b;
    cout<<"GCD (highest common factor)"<<endl;
    cout<<gcd(a,b);

    return 0;
}

