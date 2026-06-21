class Solution {
public:
    string reverseWords(string s) {
        string ans = "" ;
        reverse(s.begin() , s.end()) ;

         string part = "" ;
        for(int i=0 ; i<s.size() ; i++){
           
            if(s[i]== ' '){
                if(part.size() > 0){
                    reverse(part.begin() , part.end()) ;
                    ans+=part ;
                    ans+=' ' ;
                    part = "" ;
                }
            }
            else {
              part +=s[i] ;
            }
        }
        reverse(part.begin() , part.end()) ;
         ans+=part ;
         int n = ans.size() ;
         if(ans[n-1] == ' ') ans.pop_back() ;
        return ans ;
    }
};