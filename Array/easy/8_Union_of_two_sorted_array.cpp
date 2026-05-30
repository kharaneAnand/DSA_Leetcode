/*

Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.
Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.

Examples:

Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
Output: [1, 2, 3, 4, 5, 6, 7]
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.

*/

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        int i=0 ;
        int j=0 ;
        vector<int>ans ;
        
        while(i<a.size() && j<b.size()){
            if(i>0 && a[i]==a[i-1]){
                i++ ;
                continue ;
            }
            if(j>0 && b[j] == b[j-1]) {
                j++ ;
                continue ;
            }
            
            if(a[i] < b[j]) {
                ans.push_back(a[i]) ;
                i++ ;
            }
            if(b[j] < a[i]){
                ans.push_back(b[j]) ;
                j++ ;
            }
            if(a[i] == b[j]){
                ans.push_back(a[i]) ;
                i++ ;
                j++ ;
            }
        }
        
        while(i < a.size()) {
            if(i == 0 || a[i] != a[i-1])
                ans.push_back(a[i]);
            i++;
        }
        
        while(j < b.size()) {
            if(j == 0 || b[j] != b[j-1])
                ans.push_back(b[j]);
            j++;
        }
        return ans ;
    }
};