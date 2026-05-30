//m-1 by  sorting 
/*
Input: arr[] = [10, 10, 10]
Output: -1
Explanation: The largest element of the array is 10 and the second largest element does not exist.
*/

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        sort(arr.begin() , arr.end()) ;
        int sz = arr.size() ;
        int largest = arr[sz-1] ;
        int temp = sz-2 ;
        
        while(arr[temp] == largest){
            temp-- ;
            if(temp<0) return -1 ;
        }
        return arr[temp] ;
    }
};

//m-2 

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest = arr[0] ;
        int secondLargest = -1 ;
        
        for(int i=1 ; i<arr.size() ; i++ ){
            if(arr[i] > largest) {
                secondLargest = largest ;
                largest = arr[i] ;
            }
            else {
                if( largest > arr[i] && secondLargest < arr[i]) secondLargest = arr[i] ;
            }
        }
        return secondLargest ;
    }
};