/*
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board.
 Such regions are completely enclosed by 'X' cells.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board.
 You do not need to return anything.
*/

// LEETCODE 130 ;

//Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
//Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

class Solution {
    private :
    void DFS(int m , int n , vector<vector<char>>&board , vector<vector<int>>&vis ,
     int row , int col){
        vis[row][col] = 1 ;
        int delrow[] = {-1 , 0 , 1 , 0} ;
        int delcol[] = {0,1,0,-1} ;

        for(int i=0 ; i<4 ; i++){
            int neighrow =  row + delrow[i] ;
            int neighcol = col + delcol[i] ;

            if(neighrow>=0 && neighrow<m && neighcol>=0 && neighcol<n && !vis[neighrow][neighcol] && board[neighrow][neighcol] == 'O' ) DFS(m,n, board , vis , 
            neighrow , neighcol) ;
        }
        return ;
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size() ;;
        int n = board[0].size() ;
        vector<vector<int>>vis(m , vector<int>(n , 0)) ;

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if((i==0 || j==0 || i==m-1 || j==n-1) && !vis[i][j] && board[i][j] == 'O'){
                    DFS(m , n , board , vis , i , j) ;
                }
            }
        }

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X' ;
            }
        }
        return ;
    }
};


// sc :- 0(M X N) ;
// TC :-  0(M X N) ;