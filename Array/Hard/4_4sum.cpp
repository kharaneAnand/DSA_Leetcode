class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end()) ;
        int n = nums.size() ;
        vector<vector<int>>res ;
        for(int i=0 ; i<n ; i++){
            if(i>0 && nums[i] == nums[i-1]) continue ;
            for(int j=i+1 ; j<n ; j++){
                if(j>i+1 &&  nums[j] == nums[j-1]) continue ;
                    int k = n-1 ;
                    int l = j+1 ;

                    while(l<k) {
                        long long sum = 1LL *nums[i]+nums[j]+ nums[l] + nums[k] ;
                        if(sum <target){
                            l++ ;
                        }
                        else if(sum > target){
                            k-- ;
                        }
                        else {
                            vector<int>ans = {nums[i] , nums[j] , nums[l] , nums[k]} ;
                            res.push_back(ans) ;
                            l++ ;
                            k-- ;

                            while(l<k && nums[l] == nums[l-1]) l++ ;
                            while(l<k && nums[k] == nums[k+1]) k-- ;
                        }
                    }
            }
        }
         return res ;
    }
};