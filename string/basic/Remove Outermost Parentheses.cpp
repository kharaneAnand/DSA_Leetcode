class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st ;
        string ans ;
        for(int i=0 ; i<s.size() ; i++){
            if(st.empty()){
                if(s[i] == '(') st.push('(') ;
            }
            else {
                if(s[i] == '('){
                    st.push('(') ;
                    ans += '(' ;
                }
                else{
                    if(st.size() != 1) ans+=')' ;
                    st.pop() ;
                }
            }
        }
        return ans ;
    }
};

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "" ;
        int count = 0 ;

        for(auto it : s){
            if(it == '('){
                if(count > 0) ans+="(" ;
                count++ ;
            }
            else {
                count-- ;
                if(count>0) ans+=")" ;
            }
        }
        return ans ;
    }
};