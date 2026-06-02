/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent,
 with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

*/

// Leetcode :- 75 ;

// M-1 :- sorting 
//TC ;- 0(nlogn) ;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ;
    }
};

// M-2 traversal and by tracking the numbers ;
class Solution {
public:
    void sortColors(vector<int>& nums) {
      
      int noZeros = 0 ;
      int noOnes =  0 ;

      for(int i=0 ; i<nums.size() ; i++){
        if(nums[i] == 0) noZeros++ ;
        else if(nums[i] == 1 ) noOnes++ ;
      }
        int j=0 ;
      while(j<nums.size()){
        if(j<noZeros) nums[j] = 0 ;
        else if(j>=noZeros && j<noZeros+noOnes) nums[j] = 1 ;
        else nums[j] = 2 ;
        j++ ;
      }
      
    }
};


//m-3 dutch flag algorithm ;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0 , j=0 , k=nums.size()-1 ;

        while(j<=k){
            if(nums[j] == 0) {
                swap(nums[i] , nums[j]) ;
                i++ ;
                j++ ;
            }
            else if(nums[j] == 2) {
                swap(nums[j] , nums[k]) ;
                k-- ;
            } 
           else  j++ ;
        }
       
    }
};