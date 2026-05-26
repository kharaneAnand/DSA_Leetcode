/* store it in the hashmap and serch in the hashmap - 

  TC = 0(n) ;
  SC = 0(n) ;
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int , int >mp ;
        int  a=-1 , b=-1 ;
      for(int i=0 ; i<nums.size() ; i++){
        int rem = target - nums[i] ;

        if(mp.find(rem) != mp.end()){
            a = mp[rem] ;
            b = i ;
            break ;
        }
        else {
            mp[nums[i]] = i ;
        }
      }

      return {a , b} ;
    }
};