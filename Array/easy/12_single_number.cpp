/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.


Example 1:

Input: nums = [2,2,1]

Output: 1

*/

//leetcode :- 136 ;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = nums[0] ;

        for(int i=1 ; i<nums.size() ; i++){
            a = a^nums[i] ;
        }
        return a ;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
       set<int>st ;
       int sum = 0 ;
       for(int i=0 ; i<nums.size() ; i++){
            st.insert(nums[i]) ;
            sum+=nums[i] ;
       }
       int setsum = 0 ;

       for(auto ele : st){
        setsum+=ele ;
       }
       return 2*setsum - sum ;
    }
};