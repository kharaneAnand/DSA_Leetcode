/*
Given an integer array nums, find the subarray with the largest sum, and return its sum. 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

*/

// Leetcode :- 53 ;
// kadens algo 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int maxsum = nums[0];

        for(int i=1 ; i<nums.size() ; i++){
            sum = max(sum+nums[i] , nums[i]) ;
            maxsum = max(maxsum , sum) ;
        }
        return maxsum ;
    }
};

// DP 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>dp(nums.size() , 0) ;
        dp[0] = nums[0] ;
        for(int i=1 ; i<nums.size() ; i++){
            dp[i] = max(dp[i-1]+nums[i] , nums[i]) ;
        } 

        int ans =INT_MIN ;
    for(int i=0 ; i<dp.size() ; i++){
        ans = max(dp[i] , ans) ;
    }
    return ans ;
    }
        
};