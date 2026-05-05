/* Two Sum Problem  */

/*
 Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

// IMP assumptions :-  You may assume that each input would have exactly one solution, and you may not use the same element twice. 

#include<iosteam>
using namespace std ;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
        // Basic Brute Force approch for this is just traverse through the all possible combinations and get the first pair 

        for(int i=0 ; i<nums.size() ; i++){
            for(int j=i+1 ; j<nums.size() ; j++){
                if(nums[i]+ nums[j] == target ) return {i , j} ;
            }
        }
        return {} ;
    }
};