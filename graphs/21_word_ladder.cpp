class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string , int>>qe ;
        unordered_set<string>st(wordList.begin() , wordList.end()) ;

        qe.push({beginWord , 1}) ;
        st.erase(beginWord) ;

        while(!qe.empty()){
            string word = qe.front().first ;
            int steps = qe.front().second ;
            qe.pop() ;

            if(word == endWord) return steps ;
            for(int i=0 ; i<word.size() ; i++){
                char original = word[i] ;
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    word[i] = ch ;

                    if(st.find(word) != st.end()){
                        qe.push({word , steps+1}) ;
                        st.erase(word) ;
                    }
                }
                word[i] = original ;
            }
        }
        return 0 ;
    }
};