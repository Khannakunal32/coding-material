 
#include <iostream>

using namespace std;





//multiplication of a matrix                     level 1
// output
// 10 20
// 10 20
// 10 20
int main()
{ int n1=3,n2=4,n3=2;
    int m1[x][y]={{1,2,3,4},{1,2,3,4},{1,2,3,4}};
    int m2[y][z]={{1,2},{1,2},{1,2},{1,2}};
    
    int prn=0;
    
    for(int i=0; i<n1; i++) {
        for(int j=0; j<n3; j++) {
            for(int k=0; k<n2; k++ ) {
            prn+=m1[i][k]*m2[k][j];
            }
            cout<<prn<<" ";
            prn=0;
        }
        cout<<endl;
    }
    
    
    

    return 0;
}





                                                //level 2

//searching in a 2d matrix with sorted rows and columns
//     3 4
// 1 2 3 4
// 2 4 6 8
// 7 22 36 58

int main()
{
    int n,m; cin>>n>>m; cout<<endl; int arr[n][m];
    for(int i=0; i<n; i++){
    for(int j=0; j<m; j++) cin>>arr[i][j];
    cout<<endl; }
    cout<<"\nenter key to search";
    int key; cin>>key;

    int i=0, j=m-1;
    
    while(i<3 && j>=0) {
        if (arr[i][j]==key) {cout<<"present"; return 0;}
        
        if(arr[i][j]<key) i++;
        else if(arr[i][j]>key) j--;
        
    }
    
    cout<<"not present"; 
    return 0;
}






//spiral print a matrix                        //level 2
//3 4
//1   2   3   4
//10  11  12  5
//9   8   7   6

//output  1 2 3 4 5 6 7 8 9 10 11 12
#include<iostream>
using namespace std;
int main()
{
    int n,m; cin>>n>>m; cout<<endl; int arr[n][m];
    for(int i=0; i<n; i++){
    for(int j=0; j<m; j++) cin>>arr[i][j];
    cout<<endl; }
   
   int rs=0, re=n-1;
   int cs=0, ce=m-1;
   
  int j=cs;
  int i=rs;
  int count= 0, total =(n-1)*(m-1);
  
    while(rs<=re && cs<=ce and count<=total) {
        
        for(int j=cs; count<=total and j<=ce; j++){ cout<<arr[rs][j]<<" "; count++;}
        rs++;
        
        for(int i=rs; count<=total and i<=re; i++){ cout<<arr[i][ce]<<" "; count++;}
        ce--;
        
        for(int j=ce; count<=total and j>=cs; j--){ cout<<arr[re][j]<<" "; count++;}
        re--;
        
        for(int i=re;count<=total and  i>=rs; i--){ cout<<arr[i][cs]<<" "; count++; }
        cs++;
        
    }


    return 0;
}