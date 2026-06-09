class Solution {
    private :
   int noOfWaviness(int num){
        int res = 0 ;
        if(num < 100) return 0 ;
        string ans = "" ;
        while(num>0){
            int rem = num % 10 ;
            ans.push_back(rem + '0') ;
            num/=10 ;
        }
        reverse(ans.begin() , ans.end()) ;
        int n= ans.size();
        for(int i=1 ; i<n-1 ; i++){
            if(ans[i-1]<ans[i] && ans[i+1] < ans[i]) res++ ;
            else if(ans[i-1] > ans[i] && ans[i+1]>ans[i]) res++ ;
        }
        return res ;
    }
public:
    int totalWaviness(int num1, int num2) {
        int res=0 ;
        for(int i=num1 ; i<=num2 ; i++){
            res+= noOfWaviness(i) ;
        }
        return res ;
    }
};