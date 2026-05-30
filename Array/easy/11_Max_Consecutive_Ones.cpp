/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.
Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

*/


//Leetcode :- 485 ;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0 ;
        int currOnes = 0 ;
        for(int i=0 ; i<nums.size(); i++){
            if(nums[i] == 0) currOnes = 0 ;
            if(nums[i] == 1)  currOnes++ ;
            maxOnes = max(maxOnes , currOnes) ;
            
        }
        return maxOnes ;
    } 
};