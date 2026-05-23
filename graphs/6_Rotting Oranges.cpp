 /* You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

*/

// Leetcode :- 994 ;


class Solution {
    private :
    int BFS(vector<vector<int>>&grid , int m , int n){
        queue<pair<pair<int , int> , int>>qe ;
        int tem = 0 ;
        int freshOranges = 0 ;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 2) qe.push({{i,j} , 0}) ;
                if(grid[i][j] == 1) freshOranges++ ;
            }
        }

        if(freshOranges == 0) return 0 ;

        int delrow[] = {-1 , 0 , 1 , 0} ;
        int delcol[] = {0 , 1  , 0 , -1} ;
        int cnt = 0 ;

        while(!qe.empty()){
            int row = qe.front().first.first ;
            int col = qe.front().first.second ;
            int time = qe.front().second ;
            qe.pop() ;

            for(int i=0 ; i<4 ; i++){
                int neighrow = row + delrow[i] ;
                int neighcol = col + delcol[i] ;

                if(neighrow>=0 && neighrow<m && neighcol>=0 && neighcol<n && grid[neighrow][neighcol] == 1) {
                    qe.push({{neighrow , neighcol} , time+1}) ;
                    grid[neighrow][neighcol] = 2 ;
                    tem = max(tem , time+1) ;
                    cnt++ ;
                }
            }
        }
       if(cnt != freshOranges) return -1 ;
       return tem ;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;
       return  BFS(grid , m , n ) ;
    }
};
 

// SC :- (N X M) ;
// TC :- (N X M) ;