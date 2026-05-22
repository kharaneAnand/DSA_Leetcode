//The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

//F(0) = 0, F(1) = 1
//F(n) = F(n - 1) + F(n - 2), for n > 1.

// Leetcode 509 :

// method -01 reccurssion simple ;

class Solution {
public:
    int fib(int n) {
        if(n==0) return 0 ;
        if(n==1) return 1 ;

        return fib(n-1) + fib(n-2) ;
    }
};

// method - 02  (Memoization) ;
class Solution {
    private :
    int helper(vector<int>&dp , int n){
        if(n==0) return 0 ;
        if(n==1) return  1 ;

        if(dp[n] != -1) return dp[n];
        return dp[n] = helper(dp , n-1) + helper(dp  , n-2);
    }
public:
    int fib(int n) {
        vector<int>dp(n+1 , -1) ;
        return helper(dp , n) ;
    }
};

// method 3 (tabulation ) ;
class Solution {
public:
    int fib(int n) {
        vector<int>dp(n+1 , 0) ;
        dp[0] = 0 ;
        dp[1] = 1 ;

        for(int i=2 ; i<=n ; i++){
            dp[i] = dp[i-1] + dp[i-2] ;
        }
        return dp[n] ;
    }
}; 


// method 04 :- tabulation with space optimization 

class Solution {
public:
    int fib(int n) {
        if(n==0) return 0 ;
       int prev2 = 0 ;
       int prev = 1 ;
      

        for(int i=2 ; i<=n ; i++){
           int curr = prev2 + prev ;
            prev2 = prev ;
            prev = curr ;
        }
        return prev ;
    }
}; 
