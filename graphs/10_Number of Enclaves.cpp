/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or 
walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary 
of the grid in any number of moves.

*/

// LEETCODE 1020 

//Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
//Output: 3
//Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

class Solution {
    void BFS(int row , int col , int m , int n , vector<vector<int>>&grid , vector<vector<int>>&vis){
        queue<pair<int,int>>qe ;
        qe.push({row , col}) ;
        vis[row][col] = 1 ;

        int delrow[] = {-1 , 0 , 1 , 0} ;
        int delcol[] = {0 , 1 , 0 , -1 } ;

        while(!qe.empty()){

            int r = qe.front().first ;
            int c = qe.front().second ;
            qe.pop() ;

            for(int i=0 ; i<4 ; i++){
            int neighrow = r + delrow[i] ;
            int neighcol = c + delcol[i] ;

            if(neighrow>=0 && neighrow<m && neighcol>=0 && neighcol<n && !vis[neighrow][neighcol] && grid[neighrow][neighcol] == 1){
                qe.push({neighrow , neighcol});
                vis[neighrow][neighcol] = 1 ;
             }
         }
        }
        
        return ;
    }

    void DFS(int row , int col , int m , int n , vector<vector<int>>&grid , vector<vector<int>>&vis){
        vis[row][col] = 1 ;

        int delrow[] = {-1 , 0 , 1, 0} ;
        int delcol[] = { 0 , 1, 0 , -1 } ;

        for(int i=0 ; i<4 ; i++){
            int neighrow = row + delrow[i] ;
            int neighcol = col + delcol[i] ;

            if(neighrow>=0 && neighrow<m && neighcol>=0 && neighcol<n && !vis[neighrow][neighcol] && grid[neighrow][neighcol] == 1){
                DFS(neighrow , neighcol , m , n, grid , vis) ;
            }
        }
        return ;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        vector<vector<int>>vis(m , vector<int>(n , 0));

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && !vis[i][j] && grid[i][j] == 1){
                    //BFS(i , j , m ,n, grid , vis) ;
                     DFS(i , j , m ,n, grid , vis) ;
                }
            }
        }
        int count = 0 ;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 1 && !vis[i][j]) count++ ;
            }
        }
        return count ;
    }
};


// TC :- 0(M X N X 4) ;
// sc :_ 0(M X N) ;
