/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size() ;
        if(n==0) return 0 ;
        int longest = 1 ;

        unordered_set<int>s ;

        for(int i=0 ; i<n ; i++){
            s.insert(nums[i]) ;
        }

        for(auto ele : s){
            if(s.find(ele - 1) == s.end()){
                int cnt = 1 ;
                int x = ele ;

                while(s.find(x+1) != s.end()){
                    cnt = cnt+1 ;
                    x = x+1 ;
                }
                longest = max(longest , cnt) ;
            }
        }
        return longest ;
    }
};