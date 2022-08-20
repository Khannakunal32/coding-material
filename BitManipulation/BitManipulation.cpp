
#include <iostream>

using namespace std;

int getBit(int n, int pos) {           //5 000 001 010 011 100 0101 0001
    return (n & (1<<pos)!=0);
}
int setBit(int n, int pos) {
    return (n | (1<< pos));
}
int clearBit(int n, int pos) {
    int mask= ~(1<<pos);
    return (n & mask);
}

void updateBit(int n, int pos, int update) {
    if(update==1) setBit(n,pos);
    else clearBit(n,pos);
}

int toggleBit(int n, int pos) {
    return(n xor (1<<pos));
}

int main()
{   int n,pos,update;  
    cout<<"enter number and position \n";  cin>>n; cin>>pos; 
    
     cout<< getBit(n, pos);      
     cout<< setBit(n,pos);
     cout<< clearBit(n,pos);
    
    cout<<"\n update to which bit 1 or 0 \n";
    cin>>update;
    cout<<updateBit(n,pos,update);
    
    cout<<toggleBit(n,pos);
    
    return 0;
}





//swapping with xor without using 3rd variable       //level 1 simple trick
int main()
{
    int a, b;
    cin>>a>>b;
    //trick
    a=a^b;
    b=a^b;
    a=a^b;
    
    cout<<a<<" "<<b;

    return 0;
}




//power of two                                  // level 1 simple trick

#include <iostream>

using namespace std;

//trick
int checkPowOfTwo(int n) {
    return (!(n & (n-1)));
}

int main()
{ int n; cin>>n;
    if(checkPowOfTwo(n)) cout<<"true";
    else cout<<"false";

    return 0;
}



//count set bit                 //level 1 trick
//input  7 //0111
//output 3
int countSetBits(int n) {
    int count=0;
    if(n==0) return 0;
    while(n!=0) {
        n= (n & (n-1));
        count++; 
    }
    return count;
}



//print all subsets                          //level 2
#include <iostream>
#include <math.h>

using namespace std;


int getBit(int n, int pos) {
    return (!(n & (1<<pos)));
}

int printSubsets(int arr[], int n) {
    int pos=0;
    for(int i=0; i<pow(2,n); i++) {         // also pow(2,n) = (1<<n);
        for(int j=0; j<n; j++) {
            
            if(getBit(i,j)) cout<<arr[j];
        }
        cout<<endl;
    }
    return 0;
}

int main()
{
    int arr[3]= {1,2,3};
    printSubsets(arr,3);
    return 0;
}




//finding unique number in array , others are repeating twice             //level 1 (trick)
//output 4
int printRepeatingNum(int arr[], int n) {
    int xorsum=0;
    for(int i=0; i<n; i++) {
        xorsum^=arr[i];
    }
    return xorsum;
}

int main()
{
    int arr[7]= {1,2,3,4,1,2,3};
    
    cout<<printRepeatingNum(arr,7);
    return 0;
}










                                                    // level 2
//Write a program to find 2 unique numbers in an array where all numbers

// Logic
// 1. Take XOR of all the elements and let that xor value be x. All the repeating
// elements will get nullified and xor of only two unique elements will last. (as
// a⊕a = 0).
// 2. There will be at least one bit set in x. Using that set bit, divide the original
// set of numbers into two sets
// a. First set which contains all the elements with that bit set.
// b. Second set which contains all the elements with that bit unset.
// 3. Take xor of both the sets individually, and let those xor values be x1 and x2.
// 4. Voila, x1 and x2 are our unique numbers. Reason: both the above sets
// contain one of the unique elements and rest elements of the sets occur
// twice which will get nullified after ⊕ operation.
// except two, are present twice.


// output 6 4
int twoUniqueNum(int arr[], int n) {
     int xorsum=0;
    for(int i=0; i<n; i++) {
        xorsum^=arr[i];
    }
    // int a1[n]; int b1[n];
    vector <int> a;
    vector <int> b;
    
    for(int i=0; i<n; i++) {
        
        if(xorsum== (xorsum & arr[i])) a.push_back(arr[i]);
        else b.push_back(arr[i]);
    }
    
    int xa=0, xb=0;
    for(auto i=0; i<a.size(); i++) xa^=a[i]; 
    cout<<xa<<" ";
    
    for(auto i=b.begin(); i<b.end(); i++) xb^=*i; 
    cout<<xb;
    
    return 0;
}

int main()
{
    int arr[7]= {1,2,3,4,1,2,3};
    
    // cout<<printRepeatingNum(arr,7);
    
    int arrt[10]= {1,2,3,4,1,2,3,6,9,9};
    twoUniqueNum(arrt,10);
    return 0;
}










                                                // level 3

// Write a program to find a unique number in an array where all numbers
// except one, are present thrice.
// Logic
// 1. We will maintain an array of 64 size which will store the number of times i
// th              input 1 2 3 4 1 2 3 1 2 3      output 4
// bit has occurred in the array.
//    4 4 7 ..........64bits
// 2. Take the modulo of each element of this array with 2. Resultant array will
// represent the binary representation of the unique number.
// 3. Convert that binary number to decimal number and output it.

int getBit(int n, int pos) {
    return (!(n & (1<<pos)));
}


int setBit(int n, int pos) {
    return ( n | (1<<pos));
}

int uniqueNumOthersRepThree(int arr[], int n) {
    
    int tmp[64];
    int ans=0;
    
    for(int i=0; i<64; i++) {
    int sum=0;
    
    for(int j=0; j<n; j++) {
        if(!getBit(arr[j], i)) sum++;
    }
        
        if(sum%2!=0) ans=setBit(ans,i);
        
    }
    return ans;
}

int main()
{
    int arr[10]= {1,2,3,4,1,2,3,1,2,3};
    cout<<uniqueNumOthersRepThree(arr, 10);
    return 0;
}
