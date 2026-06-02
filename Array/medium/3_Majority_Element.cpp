/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3

*/
//TC:- 0(n) but Sc= 0(n) ;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int , int>mp ;

        for(int i=0 ; i<nums.size() ; i++){
            mp[nums[i]]++ ;
        }

        for(auto ele:mp){
            if(ele.second > nums.size()/2) return ele.first ;
        }
        return 0 ;
    }
};

// Algo is Moore’s Voting Algorithm 


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0 ;
        int ele ;
        for(auto num : nums){

            if(count == 0){
                ele = num ;
            }
             if(ele == num) {
             count++ ;
           }
           else count-- ;
        }
        return ele ;
    }
};