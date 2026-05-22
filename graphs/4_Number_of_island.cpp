//Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water),
//  return the number of islands.

//An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
//  You may assume all four edges of the grid are all surrounded by water.


// LeetCode 200 ;

class Solution {
    private :
    void bfs(int row , int col , vector<vector<char>>&grid , vector<vector<int>>&vis){

        queue<pair<int,int>>qe ;
        qe.push({row , col}) ;
        vis[row][col] = 1 ;
        int m = grid.size() ;
        int n = grid[0].size() ;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!qe.empty()){
           int r = qe.front().first ;
           int c = qe.front().second ;
           qe.pop() ;
            
            for(int i=0 ; i<4 ; i++){
                int neighrow = r + delrow[i] ;
                int neighcol = c + delcol[i] ;

                if(neighrow >= 0 && neighrow<m && neighcol>=0 && neighcol<n &&
                !vis[neighrow][neighcol] && grid[neighrow][neighcol] == '1'){
                    qe.push({neighrow , neighcol}) ;
                    vis[neighrow][neighcol] = 1 ;
                }
            }
        }
        return ;
    }

    void dfs(int row , int col , vector<vector<char>>&grid , vector<vector<int>>&vis){
        int m = grid.size() ;
        int n = grid[0].size() ;
         vis[row][col] = 1 ;

         int delrow[] = {-1 , 0 , 1 , 0} ;
         int delcol[] = {0 , 1 , 0 , -1} ;

         for(int i=0 ; i<4 ; i++){
            int neighrow = row + delrow[i] ;
            int neighcol = col + delcol[i] ;

            if(neighrow>=0 && neighrow<m && neighcol>=0 && neighcol<n && 
            !vis[neighrow][neighcol] && grid[neighrow][neighcol] == '1') {
                dfs(neighrow , neighcol , grid , vis);
            }
         }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int  m = grid.size() ;
        int n = grid[0].size() ; 
        vector<vector<int>>vis(m , vector<int>(n , 0)) ;

        int cnt = 0 ;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++ ;
                    dfs(i , j , grid , vis) ; // or bfs(i,j,grid , vis) can use both traversal 
                }
            }
        }
        return cnt ;
    }
};



// SC = 0(n^2) ;
// TC = 0(N^2) ;