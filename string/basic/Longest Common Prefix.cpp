class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0] ; 

        for(int i=1 ; i<strs.size() ; i++){
            string res = "" ;
            for(int j=0 ; j<min(ans.size(), strs[i].size()) ; j++){
                if(ans[j] == strs[i][j]) res.push_back(ans[j]) ;
                else break ;
            }
            ans = res ;
            cout<<ans<<" ";
        }
        return ans ;
    }
}; 