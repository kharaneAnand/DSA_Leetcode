//Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first 
// stair and wants to reach the last stair. From any stair i, the frog has two options: 
// it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference
//  in height between the two stairs.
//  Determine the minimum total cost required for the frog to reach the last stair.


/*Input: heights[] = [20, 30, 40, 20]
Output: 20
Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
jump from stair 0 to 1: cost = |30 - 20| = 10
jump from stair 1 to 3: cost = |20 - 30| = 10
Total Cost = 10 + 10 = 20
*/

// the question is diffent from the leetcode ;;

#include<bits/stdc++.h>

class Solution {
    private :
    int f(vector<int>&heights , int idx){
        if(idx == 0) return 0 ;
        
        int left  = f(heights , idx -1 ) + abs(heights[idx] - heights[idx -1 ]) ;
        int right = INT_MAX ;
        if(idx>1) {
            right = f(heights , idx-2) + abs(heights[idx] - heights[idx-2]) ;
        }
        return min(left , right) ;
    }
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size() ;
        return f(height , n-1) ;
    }
};

class Solution {
    
private:

    int f(vector<int>& heights, int idx, vector<int>& dp){
        
        if(idx == 0) return 0;

        if(dp[idx] != -1) return dp[idx];

        int left = f(heights, idx - 1, dp) +
                   abs(heights[idx] - heights[idx - 1]);

        int right = INT_MAX;

        if(idx > 1){
            right = f(heights, idx - 2, dp) +
                    abs(heights[idx] - heights[idx - 2]);
        }

        return dp[idx] = min(left, right);
    }

public:

    int minCost(vector<int>& height) {
        
        int n = height.size();

        vector<int> dp(n, -1);

        return f(height, n - 1, dp);
    }
};


// tabulation 
class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here    
        int n = height.size() ;
        vector<int>dp(n , 0) ; 
        dp[0] = 0 ;
        
        for(int i=1 ; i<n ; i++){
            int left = dp[i-1] + abs(height[i] - height[i-1]) ;
            int right = INT_MAX ;
            if(i>1) right = dp[i-2] + abs(height[i] - height[i-2]) ;
            
            dp[i] = min(left , right) ;
        }
        return dp[n-1] ;
    }
};

// tabulation with the space optimization ;
class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here    
        int n = height.size() ;
        int prev = 0 ;
        int prev1 = 0 ;
        
        for(int i=1 ; i<n ; i++){
            int left = prev + abs(height[i] - height[i-1]) ;
            int right = INT_MAX ;
            if(i>1) right = prev1 + abs(height[i] - height[i-2]) ;
            
            int curr = min(left , right) ;
            prev1 = prev ;
            prev = curr ;
        }
        return prev ;
    }
};