/*Given an integer array nums, find the subarray with the largest sum, and return its sum.

 
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

*/

/*TC :- 0(n^2)*/ 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int sum = 0 ;
       int mxsum = INT_MIN ;

       for(int i=0 ; i<nums.size() ; i++){
            sum = nums[i] ;
            mxsum = max(mxsum , sum) ;
            for(int j=i+1 ; j<nums.size() ; j++){
                sum += nums[j] ;
                mxsum = max(mxsum , sum ) ;
            }
       } 
       return mxsum ;
    }
};