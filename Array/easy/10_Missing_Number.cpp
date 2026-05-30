/*
Input: nums = [3,0,1]

Output: 2

Explanation:

n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 
2 is the missing number in the range since it does not appear in nums.

*/

// Leetcode :- 268 ;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size() ;

        int sum = n*(n+1) / 2 ;
        int sumarray = 0 ;
        for(int i=0 ; i<nums.size() ; i++){
            sumarray += nums[i] ;
        }

        return sum - sumarray ;
    }
};




