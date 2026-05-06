/*
Logic :- 

    we will sort it and use two pointer and then find the pair we got it return it 
    catch :- need to store the indices (Track the Indices) =>use ExtraSpace for that ;

        T.C = 0(nlog(n))
        S.C = 0(n) 
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // step - 01 :- creating a Extra Space ;
        vector<int>ExtraSpace  = nums ;

        // step 02 :- sort it ;
        sort(ExtraSpace.begin() , ExtraSpace.end()) ;

        // step-03 :- Two Pointer Approch 
        int i=0 , j = nums.size() -1 ;
        int a=-1 , b=-1 ;

        while(i<j){
            int sum = ExtraSpace[i] + ExtraSpace[j] ;

            if(sum == target){
                a = ExtraSpace[i] ;
                b = ExtraSpace[j] ;
                break ;
            }
            else if(sum < target) i++ ;
            else j-- ;
        }

        // step - 04 :- searching for the indices 
        int idx1=-1 , idx2=-1 ;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]==a && idx1 == -1 ) idx1 = i ;
           else if(nums[i] == b) idx2 = i ;
        }
      return {idx1 , idx2} ;
    }
};