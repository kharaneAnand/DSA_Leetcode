class Solution {
public:
    bool check(vector<int>& nums) {
        int check = 0 ;

        for(int i=1 ; i<nums.size() ; i++){
            if(nums[i] < nums[i-1]) check++ ;
        }
        if(nums.back() > nums.front()) check++ ;
        if(check>1) return false ;
        return true ;
    }
};