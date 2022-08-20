#include<iostream>


using namespace std;
 

 // level 1 2 3    and   Stuck



// ******
// *    *
// *    *
// *    *
// ******

int main() {
    int row, colm;
    cin>> row>> colm;
    for(int i=0; i<row; i++ ) {
        for (int j=0; j<colm; j++) {
            if(i==0||i==(row-1)||j==0||j==(colm-1))
            cout<<"* ";
            else cout<<"  ";
        }
        cout<<endl;
    }
    return 0;
}






// 5 5
// * 
// * * 
// * * * 
// * * * * 
// * * * * * 

int main() {
    int row, colm;
    cin>> row>> colm;
    for(int i=0; i<row; i++ ) {
        for (int j=0; j<colm; j++) {
            cout<<"* ";
            if(i==j) break;
            // else cout<<"  ";
        }
        cout<<endl;
    }
    return 0;
}







// 10
//     *       *       
//   *   *   *   *   * 
// *       *       *   

int main() {
    int row, colm;
    row=3;
    cin>> colm;
    for(int i=1; i<=row; i++ ) {
        for (int j=1; j<=colm; j++) {
            if(((i+j)%4==0) || (i==2 && ((i+j-2)%4==0)))
            cout<<"* ";
            else cout<<"  ";
        }
        cout<<endl;
    }
    return 0;
}






// 5
// * * * * * 
// * * * * 
// * * * 
// * * 
// * 

int main() {
    int row, colm;
    // row=3;
    cin>> row;
    for(int i=1; i<=row; i++ ) {
        for (int j=1; j<=row-i+1; j++) {
        cout<<"* ";
            
        }
        cout<<endl;
    }
    return 0;
}






// 5
//         1 
//       2 1 2 
//     3 2 1 2 3 
//   4 3 2 1 2 3 4 
// 5 4 3 2 1 2 3 4 5 

int main() {
    // int row, colm;
    // row=3;
    int n;
    cin>> n;
    for(int i=1; i<=n; i++ ) {
        for (int j=1; j<=n-i; j++) 
         cout<<"  ";
         
         int k=i;
        for(int j=n-i+1; j<=n; j++) {
        cout<<k<<" ";
        k--;
        }
        
        k=2;
        for(int j=n; j<n+i-1; j++) {
            cout<<k<<" ";
            k++;
        }
        cout<<endl;
    }
    
    return 0;
}




// 5
//         * 
//       * * 
//     * * * 
//   * * * * 
// * * * * * 

int main() {
  
    int n;
    cin>> n;
    for(int i=1; i<=n; i++ ) {
        for (int j=1; j<=n-i; j++) {
            cout<<"  ";
        }
        for (int j=1; j<=i; j++) {
            cout<<"* ";
        }
        cout<<endl;
    }
    
    return 0;
}





// 5
// 1 2 3 4 5 
// 1 2 3 4 
// 1 2 3 
// 1 2 
// 1 

int main()
{
    int n,k;
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n-i+1; j++) {
           k=j;
           cout<<k<<" ";
        }
        cout<<endl;
    }
    return 0;
}





// 5
// 1 
// 2 2 
// 3 3 3 
// 4 4 4 4 
// 5 5 5 5 5 

int main()
{
    int n,k;
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
           k=i;
           cout<<k<<" ";
        }
        cout<<endl;
    }
    return 0;
}





// 5
// 1 1 1 1 1 
// 2 2 2 2 
// 3 3 3 
// 4 4 
// 5 

#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n-i+1; j++) {
           k=i;
           cout<<k<<" ";
        }
        cout<<endl;
    }
    return 0;
}







// 5
// 1 
// 2 3 
// 4 5 6 
// 7 8 9 10 
// 11 12 13 14 15 


int main()
{
    int n,k=1;
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
           cout<<k<<" ";
           k++;
        }
        cout<<endl;
    }
    return 0;
}







// 5
// 1 
// 0 1 
// 1 0 1 
// 0 1 0 1 
// 1 0 1 0 1 

int main()
{
    int n,k;
    cin>>n;
    for(int i=1; i<=n; i++) {
        
        
        for(int j=1; j<=i; j++) {
          
           if((i+j)%2==0)     k=1;
           else   k=0;
           
           cout<<k<<" ";
        }
        
        cout<<endl;
    }
    return 0;
}






// 5
//     *
//    ***
//   *****
//  *******
// *********
// *********
//  *******
//   *****
//    ***
//     *

int main()
{
    int n,i,j,st=1;
    cin>>n;
    
    for(i=1; i<=n; i++) {
        for(j=1; j<=n-i; j++) cout<<" ";
        
        for(j=1; j<=st; j++) {
            cout<<"*";
        }
        st+=2;
        cout<<endl;
        
    }
    st-=2;
    for(i=n; i>=1; i--) {
        for(j=1; j<=n-i; j++) cout<<" ";
        
        for(j=1; j<=st; j++) {
            cout<<"*";
        }
        st-=2;
        cout<<endl;
        
    }

    return 0;
}









// 5
//     *
//    * *
//   *   *
//  *     *
// *       *
// *       *
//  *     *
//   *   *
//    * *
//     *
int
main ()
{
  int n, i, j, st = 1;
  int cont = 0;
  cin >> n;

  for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= n - i; j++)
	cout << " ";
      cout << "*";

      if (cont != 0)
	{

	  for (j = 1; j <= st; j++)
	    {
	      cout << " ";
	    }
	  st += 2;
	  cout << "*";


	}

      cont = 1;

      cout << endl;
    }
    
    
    //second half
    int k=st-2;
    
    for(i=1; i<=n; i++) {
        for(j=1; j<=i-1; j++) cout<<" ";
        cout<<"*";
        
        for(j=1; j<=k; j++) {
            cout<<" ";
        }
            k-=2;
        
        if(n-i != 0) cout<<"*";
        cout<<endl;
    }
    
    
  return 0;
}









// 5              level 3
// *********
// **** ****
// ***   ***
// **     **
// *       *
// *       *
// **     **
// ***   ***
// **** ****
// *********

int
main ()
{
  int n, i, j, k = 1;
  cin >> n;

  for(i=1; i<=n; i++) {
      
      for(j=1; j<=n-i+1; j++) 
          cout<<"*";
      
      if(i>=2) {
      for(j=1; j<=k; j++) 
        cout<<" ";
        
        k+=2;
        
          for(j=1; j<=n-i+1; j++) 
          cout<<"*";
      } else for(j=1; j<=n-i; j++) cout<<"*";
        
          
          
          cout<<endl;
        
  }
  
  k=k-2;
  for(i=n; i>=1; i--) {
      
      for(j=1; j<=n-i+1; j++) 
          cout<<"*";
      
      if(i>=2) {
      for(j=1; j<=k; j++) 
        cout<<" ";
        
        k-=2;
        
          for(j=1; j<=n-i+1; j++) 
          cout<<"*";
      } else for(j=1; j<=n-i; j++) cout<<"*";
        
          
          
          cout<<endl;
        
  }
  
    
  return 0;
}





// 5
//     *****
//    *****
//   *****
//  *****
// *****

int
main ()
{
  int n, i, j, k = 1;
  cin >> n;

  for(i=1; i<=n; i++) {
  
  for(j=1; j<=n-i; j++) cout<<" ";
  
  for(j=1; j<=n; j++) cout<<"*";
  
  cout<<endl;
  
  }
    
  return 0;
}





// 5
//     *****
//    *   *
//   *   *
//  *   *
// *****

int
main ()
{
  int n, i, j, k = 1;
  cin >> n;

  for(i=1; i<=n; i++) {
  
  for(j=1; j<=n-i; j++) cout<<" ";
  
  if(i==1 || i==n)
  for(j=1; j<=n; j++) cout<<"*";
  
  else {
      cout<<"*";
      for(j=1; j<=n-2; j++) cout<<" ";
      cout<<"*";
  }
  
  cout<<endl;
  
  }
    
  return 0;
}






// 5               level 2
//     1
//    2 2
//   3 3 3
//  4 4 4 4
// 5 5 5 5 5

int
main ()
{
  int n, i, j, k = 1;
  cin >> n;

  for(i=1; i<=n; i++) {
  
  for(j=1; j<=n-i; j++) cout<<" ";
  
  for(j=1; j<=k; j++) { 
      if(j%2==0) cout<<" ";
      else cout<<i;
  }
  k+=2;
  cout<<endl;
  
  }
    
  return 0;
}






// 5               level 2
//     1
//    1 2
//   1 2 3
//  1 2 3 4
// 1 2 3 4 5

int
main ()
{
  int n, i, j, k = 1;
  cin >> n;

  for(i=1; i<=n; i++) {
  
  for(j=1; j<=n-i; j++) cout<<" ";
  
  int c=1;
  for(j=1; j<=k; j++) { 
      if(j%2==0) cout<<" ";
      else { cout<<c; c++; }
      
  }
  k+=2;
  cout<<endl;
  
  }
    
  return 0;
}








// 5                                                 level 3
// *        *
// **      **
// ***    ***
// ****  ****
// **********
// **********
// ****  ****
// ***    ***
// **      **
// *        *

int
main ()
{
  int n, i, j, k ;
  cin >> n;
    k=2*n-2;
  for(i=1; i<=n; i++) {
  
  
  for(j=1; j<=i; j++) cout<<"*";
  
  for(j=1; j<=k; j++) cout<<" ";
  
  k-=2;
  
  for(j=1; j<=i; j++) cout<<"*";

  cout<<endl;
  
  }
 
    k=k+2;
  for(i=n; i>=1; i--) {
  
  for(j=1; j<=i; j++) cout<<"*";
  
  for(j=1; j<=k; j++) cout<<" ";
  
  k+=2;
  
  for(j=1; j<=i; j++) cout<<"*";

  cout<<endl;
  
  }
    
  return 0;
}









// 5                                              level 3
// *        *
// **      **
// * *    * *
// *  *  *  *
// *   **   *
// *   **   *
// *  *  *  *
// * *    * *
// **      **
// *        *

int
main ()
{
  int n, i, j, k ;
  cin >> n;
    
    //first half
  for(i=1; i<=n; i++) {
   for(j=1; j<=2*n; j++) {
       
   if(j==1 || j==2*n || j==i || j+i==2*n+1 ) cout<<"*";
   else cout<<" ";
   }
   cout<<endl;
  }
    
    //second half
  for(i=n; i>=1; i--) {
   for(j=1; j<=2*n; j++) {
       
   if(j==1 || j==2*n || j==i || j+i==2*n+1 ) cout<<"*";
   else cout<<" ";
   }
   cout<<endl;
  }
 

    
  return 0;
}




//5                              Pascals Triangle - Stuck
