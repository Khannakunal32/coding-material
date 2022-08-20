//printing longest common subsequence
#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>


using namespace std;
//// recursive
// int lcs(string s1, string s2, int n, int m){
//     int dp[n+1][m+1];
//     for(int i=0; i<=n; i++)
//     for(int j=0; j<=n; j++)
//     if(i==0 ||j==0) dp[i][j]=0;
    
//     for(int i=1; i<=n; i++)
//     for(int j=1; j<=m; j++){
        
//         if(s1[i-1] == s2[j-1])
//         dp[i][j]= 1+dp[i-1][j-1];
        
//         else dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
//     }
    
//     return dp[n][m];
// }

// void plcs(string s1, string s2, int n, int m, string o, vector<string> &v, int lcs){
 
//     if(n==0 || m==0){
//         if(o.length()==lcs)
//         v.push_back(o);
//         return;
//     }
 
//     if(s1[n-1]== s2[m-1]){
//         o=s1[n-1]+o;
//         plcs(s1,s2,n-1,m-1, o, v, lcs);
//     }
//     else {
//         plcs(s1,s2,n-1,m,o, v, lcs);
//         plcs(s1,s2,n,m-1,o, v, lcs);
//     }
//     return;
// }
 
 // // dp
string plcs(string s1, string s2, int n, int m){
     int dp[n+1][m+1];
    for(int i=0; i<=n; i++)
    for(int j=0; j<=n; j++)
    if(i==0 ||j==0) dp[i][j]=0;
    
    for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++){
        
        if(s1[i-1] == s2[j-1])
        dp[i][j]= 1+dp[i-1][j-1];
        
        else dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
    }
    
    // return dp[n][m];
    int i=n, j=m;
    string o="";
    while(i>0 && j>0) {
        if(s1[i-1]==s2[j-1])
        {
            o.push_back(s1[i-1]);
            i--; j--;
        }
        else {
            if(dp[i-1][j] > dp[i][j-1])
            i--;
            else j--;
        }
    }
    
    return o;
}


int main()
{
    // string s1="AGGTAB";
    // string s2="GXTXAYB";
    // string o="";
    // vector<string> v;
    // int n= s1.length(), m=s2.length();

    // plcs(s1, s2, n, m, o, v, lcs(s1,s2,n,m));
    // for(auto i: v) cout<<i<<" ";
    string s1="AGGTAB";
    string s2="GXTXAYB";
    int n= s1.length(), m=s2.length();

    string o=plcs(s1, s2, n, m);
    reverse(o.begin(), o.end());
    cout<<o;
    
    return 0;
}








//sequence pattern matching
// i/p  string s1="ADXCPY" , s2="AXY";
// o/p 1  (this is true as s2 is a subsequnce of s1)
#include <iostream>
#include <cstring>

using namespace std;

// // top down using lcs
int lcs(string s1, string s2, int n, int m){
    
    int dp[n+1][m+1];
    
    for(int i=0; i<=n; i++)
    for(int j=0; j<=m; j++){
        if(i==0 || j==0) dp[i][j]=0;
        else{
        if(s1[i-1]==s2[j-1]) dp[i][j]= 1+ dp[i-1][j-1];
        
        else dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    return dp[n][m];
    
}

bool sequenceMatching(string s1, string s2, int n, int m){
    
    if(m==lcs(s1,s2,n,m)) return true;
    else return false;
}

// // recursive code without lcs
bool check(string s1, string s2, int n ,int m){
    
    if(n==0 || m==0){
        if(m==0) return true;
        else return false;
    }
    bool static b= false;
    
    if(s1[n-1]==s2[m-1]){
      b= true && check(s1,s2,n-1,m-1);
    }
    else{
        check(s1,s2,n-1,m);
    }
    
    return b;
}

//top down approach without using LCS
bool DpCheck(string s1, string s2, int n ,int m){
    
        bool dp[n+1][m+1];
        
    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++){
                if(j==0)
                dp[i][j]=1;
                else
                dp[i][j]=0;
            }
            
            
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++){
            
            if(s1[i-1]==s2[j-1])
            dp[i][j] = 1 && dp[i-1][j-1];
            
            else
            dp[i][j] = dp[i-1][j];
        }
        
        return dp[n][m];
            
        }
        


// // two pointer approach
bool tpCheck(string s1, string s2, int n, int m){
    int i=0, j=0;
    
    while(i<n && j<m){
        if(s1[i]!=s2[j]) {
            i++;
        }
        else if(s1[i]==s2[j]){
            j++; i++;
        }
    }
    
    if(j==m) return true;
    else return false;
}



int main()
{
    // string s1="kunal";
    // string s2="kl";
    string s1="ADXCPY" , s2="AXY";
    int n=s1.length(), m=s2.length();
    
    cout<<"using top down lcs =>  "<<sequenceMatching(s1,s2,n, m);    // for top down dp using LCS
    
    cout<<"\nusing recursive =>  "<<check(s1,s2,n, m);              // for recursive
    
    cout<<"\nusing top down without lcs =>  "<<DpCheck(s1,s2,n, m);          // for top down without LCS
    
    cout<<"\nusing two pointer =>  "<<tpCheck(s1,s2,n,m);          // for two pointer approach
    return 0;
}









//printing longest repeating subsequence 
//i/p s1= "axxxp"
// o/p  xx    (two subsequnce of xx is possible in given string)
#include<bits/stdc++.h>


using namespace std;



// // recursive method to print all possibilties 
	 int lcs(string s1, int n , int m){
	    
	    if(n==0 || m==0) return 0;
	    
	    
	    if(s1[n-1]==s1[m-1] and n!=m) 
	    return 1+ lcs(s1, n-1, m-1);
	    
	    else return max(lcs(s1,n-1,m), lcs(s1,n,m-1));
	}
	    
	void printlcs(string s1, int n, int m,int lcs, string o, set<string> &ans){
	    
	    if(n==0 || m==0) {
	        
	        if(o.length()==lcs)
	        ans.insert(o);
	     
	        return ;
	    }
	    
	    if(s1[n-1]==s1[m-1] and n!=m){
	        o+=s1[n-1];
	    return printlcs(s1, n-1, m-1,lcs,o,ans);
	    }
	    
	    else { 
	        printlcs(s1,n-1,m,lcs,o,ans);
	    printlcs(s1,n,m-1,lcs,o,ans);
	    }
	    
	    return;
	}
	
	
	//dp method
	string printlongestRepeatedSubsequence(string s1, int n, int m){
        
        int dp[n+1][m+1];
        
        for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
        {
            if(i==0 || j==0) dp[i][j]=0;
            else 
                dp[i][j]=0;
        }
        
        for(int i=1; i<=n ; i++)
            for(int j=1; j<=m ;j++){
                
                if(s1[i-1]== s1[j-1] && i!=j)
                    dp[i][j] = 1+ dp[i-1][j-1];
                
                else {
                    dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
                }
            }
        
        
        int i=n, j=m;
        string o="";
        
        while(i>0 && j>0){
            if(dp[i][j]== 1+dp[i-1][j-1]){
                o+=s1[i-1];
                i--;
                j--;
            }
            else if(dp[i][j]==dp[i-1][j]) i--;
            else j--;
        }
        
        return o;
    }
	
	
	
int
main ()
{
  
  string s1 = "axxxp", o="", ans="";
  int n = s1.length (), m = s1.length ();
  set<string> vv;
  
  int k=lcs(s1,n,m);
  
 printlcs(s1,n,m,k,o,vv);

cout<<"recursive method to print all repeating subsequnce =>  ";
for(auto i: vv) cout<<i<<" ";

cout<<"\ndp method to print one repeating subsequence  => "<<printlongestRepeatedSubsequence(s1,n,m);
  return 0;
}
