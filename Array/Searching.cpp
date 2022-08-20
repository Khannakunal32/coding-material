#include<iostream>

using namespace std;




//linear search                                            level 1
// 5 
// 12 34 65 23 64
// element to be searched for
// 64
// 4

int linearSearch(int arr[], int n, int key) {
    
    for(int i=0; i<n; i++) {
        if(key==arr[i]) return i;
    }
    return -1;
}

int main()
{
    int n,key;
    cin>>n;     // number of elemeents
    
    int arr[n];
    
    for(int i=0; i<n; i++) cin>>arr[i];          //enter array elements
    
    cout<<"\nelement to be searched for\n";
    cin>>key;
    
    cout<<linearSearch(arr, n, key);
    return 0;
}










//binary search in array                       level 1 but better then linear
//6
//1 2 3 4 5 6 
// element to be searched for
// 44
// -1

int binarySearch(int arr[], int n, int key) {
    int st=0, en=n-1, mid;
    
    while(st<=en){
        mid=(st+en)/2;
        
        if(arr[mid]==key) return mid;
        
        else if(arr[mid]>key) en=mid-1;
        
        else if(arr[mid]<key) st=mid+1;
    }
    
    return -1;
}

int main()
{
    int n,key;
    cin>>n;     // number of elemeents
    
    int arr[n];
    
    for(int i=0; i<n; i++) cin>>arr[i];          //enter array elements
    
    cout<<"\nelement to be searched for\n";
    cin>>key;
    
    // cout<<linearSearch(arr, n, key);
    cout<<binarySearch(arr,n, key);
    return 0;
}
