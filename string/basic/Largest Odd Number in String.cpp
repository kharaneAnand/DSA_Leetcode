class Solution {
    bool Ifodd(int num){
        if(num%2==0) return false ;
       else  return true ;
    }
public:
    string largestOddNumber(string num) {
        string ans=num ;
        for(int i=num.size()-1 ; i>=0 ; i--){
            if(num[i]%2==0) ans.pop_back() ;
            else return ans ;
        }
        return ans ;
    }
};