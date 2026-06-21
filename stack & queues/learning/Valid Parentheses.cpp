class Solution {
public:
    bool isValid(string s) {
        stack<char>st ;
        for(auto ele : s){
            if(ele == '(' || ele == '{' || ele == '['){
                st.push(ele) ;
            }
            else {
                 if (st.empty()) return false;
                if(ele == ')' && st.top() == '(') st.pop() ;
                else if(ele == '}' && st.top() == '{') st.pop() ;
                else if(ele == ']' && st.top() == '[') st.pop() ; 
                else return false ;
            }
        }

        if(st.empty()) return true ;
        else return false ;
    }
};