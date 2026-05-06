/*
At every index:
You decide:

Should I:
1. extend previous subarray
OR
2. start new subarray from current element?


That's core idea for this approch 

currentSum = max(nums[i] , currentSum + nums[i]) ; discard or continue the subArray ;
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0] ;
        int mxSum = nums[0] ;


        for(int i=1 ; i<nums.size() ; i++){

            // main step of this algorithm  continue or discard ;
            currentSum = max(currentSum + nums[i]  , nums[i]) ;
            mxSum = max(mxSum , currentSum) ;
        }
        return mxSum ;
    }
};