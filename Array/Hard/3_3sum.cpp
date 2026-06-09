// Brute force and giving the TLE  :- 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       set<vector<int>>ans ;

        for(int i=0 ; i<nums.size() ; i++) {
            for(int j=i+1 ; j<nums.size() ; j++){
                for(int k=j+1 ; k<nums.size() ; k++){
                    vector<int>a ;
                    if(nums[i] + nums[j] + nums[k] == 0 ) {
                        a.push_back(nums[i]) ;
                        a.push_back(nums[j]) ;
                        a.push_back(nums[k]) ;
                       sort(a.begin() , a.end()) ;
                       ans.insert(a) ;
                    }
                }
            }
        }
        vector<vector<int>>res ;

        for(auto ele : ans){
            res.push_back(ele) ;
        }
        return res ; ;
    }
};


// better approch  But still giving the TLE ; 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>ans ;

        for(int i=0 ; i<nums.size() ; i++){
            set<int>a ; 
            for(int j=i+1 ; j<nums.size() ; j++){
                int third = -(nums[i] + nums[j]) ;
                if(a.find(third) != a.end()){
                    vector<int>arr ;
                    arr.push_back(nums[i]) ;
                    arr.push_back(nums[j]) ;
                    arr.push_back(third) ;

                    sort(arr.begin() , arr.end()) ;
                    ans.insert(arr) ;
                }
                a.insert(nums[j]) ;
            }
        }

        vector<vector<int>>res(ans.begin() , ans.end()) ;
        return res ;
    }
};


// Optimize approch ;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans ;

        sort(nums.begin() , nums.end()) ;

        for(int i=0 ; i<nums.size() ; i++){
            if(i>0 && nums[i] == nums[i-1]) continue ;
            int j=i+1 ;
            int k=nums.size()-1 ;
            while(j<k){ 
                int sum = nums[i] + nums[j] + nums[k] ;
                if(sum<0){
                    j++ ;
                }
                else if(sum>0){
                    k-- ;
                }
                else {
                    vector<int>temp = {nums[i] , nums[j] , nums[k]};
                    ans.push_back(temp) ;
                    j++ ;
                    k-- ;

                    while(j<k && nums[j-1] == nums[j]) j++ ;
                    while(j<k && nums[k] == nums[k+1]) k-- ;
                }
             }
        }
        return ans ;
    }
};