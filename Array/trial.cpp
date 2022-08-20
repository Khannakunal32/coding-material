
//spiral print a matrix                        //level 2
//3 4
//1   2   3   4
//10  11  12  5
//9   8   7   6

//output  1 2 3 4 5 6 7 8 9 10 11 12
#include <iostream>

using namespace std;
int main()
{
    // int n,m; cin>>n>>m; 
    // cout<<endl; 
    // int arr[n][m];
    int n=3, m=4;
    int arr[3][4] ={{1,2,3,4},{10,11,12,5},{9,8,7,6}};
    // for(int i=0; i<n; i++){
    // for(int j=0; j<m; j++) cin>>arr[i][j];
    // cout<<endl; }
   
   int rs=0, re=n-1;
   int cs=0, ce=m-1;
   
//   int j=cs;
//   int i=rs;
    while(rs<=re && cs<=ce) {
        
        for(int j=cs; j<=ce; j++) cout<<arr[rs][j]<<" ";
        rs++;
        
        for(int i=rs; i<=re; i++) cout<<arr[i][ce]<<" ";
        ce--;
        
        for(int j=ce; j>=cs; j--) cout<<arr[re][j]<<" ";
        re--;
        
        for(int i=re; i>=rs; i--) cout<<arr[i][cs]<<" ";
        cs++;
        
    }


    return 0;
}