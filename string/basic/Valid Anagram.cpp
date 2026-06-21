
// 0(nlogn) ;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false ;
        sort(s.begin() , s.end()) ;
        sort(t.begin() , t.end()) ;

        for(int i=0 ; i<s.size() ; i++){
            if(s[i] != t[i]) return false ;
        }
        return true ;
    }
};


//0(n) ;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false ;
        vector<int>alpha(26 ,0) ;

        for(int i=0 ; i<s.size() ; i++){
            int x = s[i] -'a' ;
            alpha[x]++ ; 
        }

        for(int j=0 ; j<t.size() ; j++){
            int x = t[j]-'a' ;
            alpha[x]-- ;
        }

        for(int i=0 ; i<26 ; i++){
            if(alpha[i] != 0) return false ;
        }
        return true ;
    }
};