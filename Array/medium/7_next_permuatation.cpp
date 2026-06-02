
// 31. Next Permutation 
/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
The replacement must be in place and use only constant extra memory.


Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]

*/
// simple STL is also there 

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin() ,  nums.end()) ;
        return ;
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        // step -1 longer prefix match ;
        int idx = -1 ;
        for(int i=nums.size()-2 ; i>=0 ; i--){
            if(nums[i] < nums[i+1]) {
                idx = i ;
                break ;
            }
        }
        if(idx == -1 ){
            reverse(nums.begin() , nums.end() ) ;
            return ;
        }

        // step-02 find i but the smallest one 
        for(int i= nums.size()-1 ; i>idx ; i--){
            if(nums[i] > nums[idx]) {
                swap(nums[i] , nums[idx]) ;
                break ;
            }
        }

        // step 03 - put all the number after array in the sorted manner 
        reverse(nums.begin()+idx+1 , nums.end()) ;
        return ;
    }
};