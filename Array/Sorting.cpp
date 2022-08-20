
#include <iostream>
#include <bits/stdc++>

using namespace std;



//stl libarary sort
int main()
{
    int arr[] = { 1, 5, 2, 9, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    /*Here we take two parameters, the beginning of the
    array and the length n upto which we want the array to
    be sorted*/
    sort(arr, arr + n);
 
    cout << "Array after sorting sort(arr, arr + n); : \n";              // print 1,2,5,6,9
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

         sort(arr, arr + n, greater<int>());
 
    cout << "Array after sorting  sort(arr, arr + n, greater<int>()) : \n";        //print 9,6,5,2,1
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
 
    return 0;
}











//Selection Sort                            level 2
// 5 1 7 3 4 2
// 1 2 3 4 7

int selectionSort(int arr[], int n)
{

    for (int i = 0; i <= n - 2; i++)
    {

        for (int j = i + 1; j <= n - 1; j++)
        {

            if (arr[j] < arr[i])
                swap(arr[i], arr[j]);
        }
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        return 0;
    }

    int main()
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        selectionSort(arr, n);
        return 0;
    }





//bubble sort                              level 2
int
bubbleSort (int arr[], int n)
{
    int k=0, i=0;
    
  while(k<n) {
      
      for(int i=0; i<n-k; i++)
      if(arr[i+1]<arr[i]) swap(arr[i+1],arr[i]);

        ++k;
  }
  
  
      for (int i = 0; i < n; i++)
	cout << arr[i] << " ";
      return 0;
    }



  int main ()
  {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
      cin >> arr[i];

    bubbleSort (arr, n);
    return 0;
  }







//insertion sort                                level 2 
  int insertionSort(int arr[], int  n) {
     
     for(int i=1; i<n; i++) {
         
         int j=i;
         while(arr[j-1]>arr[j]) {
             swap(arr[j-1], arr[j]);
             --j;
         }
     }
     for (int i = 0; i < n; i++)
	cout << arr[i] << " ";
      return 0;
     
 }

  int main ()
  {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
      cin >> arr[i];

    // bubbleSort (arr, n);
    insertionSort(arr,n);
    
    return 0;
  }












//quick sort                             level 3
//7    3 4 6 2 8 1 4
//1 2 3 4 4 6 8 
#include <iostream>

using namespace std;

int partition(int arr[], int st, int en ) {
    int piv=en-1;
    int j=st, i=st;
    
    while(j!=piv) {
        if(arr[piv]>=arr[i]) {
            i++; j++;
        } else {
            j++;
            if(arr[j]<arr[piv]) {
                swap(arr[j],arr[i]);
                i++;
            }
        }
        if(j==piv) swap(arr[i],arr[piv]);
    }
    
    return i;
}


void quickSort(int arr[], int st, int en) {
    if(st<en) {
        int pi= partition(arr, st, en);
        
        quickSort(arr,pi+1,en);
        quickSort(arr,st,pi);
        
    }
}

int main()
{
    int n; cin>>n; int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    
    quickSort(arr, 0, n);
    cout<<endl;
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";

    return 0;
}






//count sort                             level 3
// Key Points
// The O(N) sort.
// Note: Only limited to small positive integers only.
// Input: Given an array.
// Output: print the sorted array.
// Time Complexity: O(N)
// Space Complexity: O(max(Arr))

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int countSort(int arr[], int n){
    
    int mx=INT_MIN;
    
    for(int i=0; i<n; i++) mx=max(mx,arr[i]);
    
 
    
    int count[mx+1]={0};     //initialzing with 0
    
    for(int i=0; i<n; i++) {
        count[arr[i]]++;
    }
    
    
    for(int i=1; i<=mx; i++) count[i]+=count[i-1];    //adding previous number frequency to next
    
    
    int ans[n]={0};
    
    for(int i=n-1; i>=0; i--)  {
        count[arr[i]]--;
        ans[count[arr[i]]]= arr[i];       // decreasing count and placing arr[i] to ans[i] at correct location
    }

    for(int i=0; i<n; i++) cout<<ans[i]<<" ";
    return 0;
}

int main()
{
    // int n; cin>>n; 
    int arr[9]={1,3,2,3,4,1,6,4,3};
    
    countSort(arr, 9);
    

    return 0;
}







                                             //level 2 (3 pointer technique)
//dnf sort  to sort array of only 0 1 2
// Given an array containing only 0,1 and 2. You have to sort the array in O(N) time,
// single pass, and O(1) space.
// Input: Given an array, containing only 0,1, and 2.
// Output: print the sorted array.
// Time Complexity: O(N), single pass
// Space Complexity: O(1)

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int dnfSort(int arr[], int n) {
    int high=n-1, low=0, mid=0;           //main line trick
    
    while(mid<=high) {
        if(arr[mid]==0) {
            swap(arr[low], arr[mid]); 
            low++; mid++
        } 
        else if(arr[mid]==1) mid++;
        else {
            swap(arr[high], arr[mid]);
            high--;
        }
    }
    return 0;
}

int main()
{
    int arr[10]= {1,2,0,1,1,0,2,1,2,0};
    
    dnfSort(arr, 10);
    
    for (int i=0; i<10 ;i++) cout<<arr[i];
    return 0;
}







//wave sort                                      level 2
// Given an array, transform the array such that
// arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= .....
// Input: Given an array.
// Output: print the sorted array.
// Time Complexity: O(N), single pass
// Space Complexity: O(1)

//output 5 1 4 2 3

void wave(int arr[], int n) {

    for(auto i=1; i<n; i+=2) {

        if(arr[i] > arr[i-1]) swap(arr[i], arr[i-1]);
        if(arr[i] > arr[i+1] && i<=n-2) swap(arr[i], arr[i+1]);
        
    }

}

int main()
{
    int arr[5]= {1,5,4,2,3};
   int  n=5;
    wave(arr, 5);
    for (int i=0; i<n ;i++) cout<<arr[i];
    return 0;
}



// Merge sort in C++                      level 3

#include <iostream>
using namespace std;

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
  
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}

// Driver program
int main() {
  int arr[] = {5, 4, 3 ,2, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, size - 1);

  cout << "Sorted array: \n";
  printArray(arr, size);
  return 0;
}