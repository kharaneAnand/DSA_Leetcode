// M-1 brute force 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0 ; i<nums.size() ; i++){
            for(int j=1 ; j<nums.size() ; j++){
                if(nums[i] + nums[j] == target) return {i , j} ;
            }
        }
        return {0,0} ;
    }
};

// Tc :- 0(n^2) ;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>extraspace = nums ;
        sort(extraspace.begin() , extraspace.end()) ;

        int i=0 ;
        int j = nums.size() -1 ;
        int a = -1 , b= -1 ;

        while(i<j){
            int sum = extraspace[i] + extraspace[j] ;

            if(sum == target){
                a = extraspace[i] ;
                b = extraspace[j] ;
                break ;
            }
            else if(sum > target) j-- ;
            else i++ ;
        }
        int idx = -1 , idx2 = -1  ;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] == a && idx == -1 ) idx = i ;
            else if (nums[i] == b) idx2 = i ;
        }
        return {idx , idx2} ;
    }
};

// TC :- o(nlogn) ;
// Sc :- 0(n) ;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp ;
        int a = -1 , b = -1 ;
        for(int i =0 ; i<nums.size() ; i++){
            int rem = target - nums[i] ;

            if(mp.find(rem) != mp.end()) {
                a = mp[rem] ;
                b = i ;
                break ;
            }

            else mp[nums[i]] = i ;
        }
        return {a , b} ;
    }
};

// TC :- o(n) ;
// sc :- 0(n) ;