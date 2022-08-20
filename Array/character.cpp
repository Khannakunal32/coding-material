#include<iostream>



//to check if a word is palidrome or not             level 1
//5 abcba
//palidrome
int main()
{
    // char arr[10];
    // // try inputing "do or die" below ouput will be doordie...   these dots will be input by you
    // for(int i=0; i<10; i++) cin>>arr[i]; 
    
    // for(int i=0; i<10; i++) cout<<arr[i];
    
    // // used for non spaces 
    // cin>>arr;
    // cout<<arr;
    
    int m;
    cin>>m;  int n=m+1; 
    char arr[n];
    cin>>arr;
    
     for(int i=0; i<n-1; i++) {
         if(arr[i]!=arr[n-2-i]) {
             cout<<"not palidrome"; return 0;
         }
     }
    cout<<"palidrome";
    return 0;
}


//one of the best basics of char array                 //level 2
//9 do or die
//do or die
//do or die
int main(){ 
 int n;
    cin>>n; int m=n+1;
    
    cin.ignore();
    char arr[m];
    
    cin.getline(arr,m);
    // cin.ignore();          //here we have commented cin ignore so that we dont have to wait for the output 
    cout<<arr;   
    for(int i=0; i<m; i++) cout<<arr[i];
    
    return 0;
}


//number of longest word in character array       //level 1
//13 kunal is kali
//5
int main() { 
int n;
    cin>>n; 
   int m=n+1;
   cin.ignore();
   
   char arr[m];
    
   cin.getline(arr,m);
   
   int st=0, en=m-1, count=0, mx=INT_MIN;
   
   for(int i=0; i<m; i++) {
       
       if(arr[i]==' ' || arr[i]=='\0') {
           count=0;
       } else count++;
       
       mx=max(count,mx);
   }
    cout<<mx;
    return 0;
}




                                       //level 2
//print the largest word in array
// 9 do or die
// die

int main()
{
    
    int n;
    cin>>n; 
   int m=n+1;
   cin.ignore();
   
   char arr[m];
    
   cin.getline(arr,m);
//   cin.ignore();
   
   int st=0, count=0, mx=INT_MIN;
   int mx2=INT_MIN;
   
   for(int i=0; i<m; i++) {
       
       if(arr[i]==' ' || arr[i]=='\0') {
           count=0;
       } else count++;
       
       
      mx=max(count,mx);
       
       if(mx!=mx2) st=i-mx+1;
       mx2 = mx;
   }
   

    for(int i=st; i<m; i++) {
        if(arr[i]==' ' || arr[i]=='\0') break;
        cout<<arr[i];
    }
    // cout<<mx;
    // cout<<st;
    return 0;
}