//Given an m x n matrix, return all elements of the matrix in spiral order. 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int rs = 0, re = m - 1;
        int cs = 0, ce = n - 1;

        vector<int> ans;

        while(rs <= re && cs <= ce) {

            for(int j = cs; j <= ce; j++)
                ans.push_back(matrix[rs][j]);
            rs++;

            for(int i = rs; i <= re; i++)
                ans.push_back(matrix[i][ce]);
            ce--;

            if(rs <= re) {
                for(int j = ce; j >= cs; j--)
                    ans.push_back(matrix[re][j]);
                re--;
            }

            if(cs <= ce) {
                for(int i = re; i >= rs; i--)
                    ans.push_back(matrix[i][cs]);
                cs++;
            }
        }

        return ans;
    }
};