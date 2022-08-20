//Recursive method
 int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       
       if(n==0 || W==0) return 0;
      
       
       if(wt[n-1]<=W) 
       return 
         max(val[n-1]+ knapSack(W-wt[n-1], wt, val, n-1), knapSack(W, wt, val, n-1));
        
        else if(wt[n-1]> W)
        return
        knapSack(W, wt, val, n-1);
       
    }



//memoization method
class Solution() {

    int dp[1002][1002];

    Solution(){
    memset(dp, -1, sizeof dp);
        
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       
       if(n==0 || W==0) return 0;
       
       if(dp[n][W]!= -1) return dp[n][W];
       
       if(wt[n-1]<=W) 
       return 
        dp[n][W] = max(val[n-1]+ knapSack(W-wt[n-1], wt, val, n-1), knapSack(W, wt, val, n-1));
        
        else if(wt[n-1]> W)
        return
        dp[n][W] = knapSack(W, wt, val, n-1);
       
    }

};


