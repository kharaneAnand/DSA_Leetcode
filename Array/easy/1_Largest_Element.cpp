
//method -1 (sorting)
int LargestElement(vector<int>&arr){
    sort(arr.begin() , sort.end()) ;
    int sz = arr.size() ;
    return arr[sz-1] ;
}

// method -2 
int LargestElement(vector<int>&arr){
    int sz = arrr.size() ;
    int largest = arr[0] ;

    for(int i=1 ; i<sz ; i++){
        if(largest < arr[i]) largest = arr[i] ;
    }
    return largest ;
} 