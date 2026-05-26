/*
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where
 a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if
  and only if one island is not equal to another (not rotated or reflected).
*/


// Leetcode 694 ;

/*
Input:
grid[][] = [[1, 1, 0, 1, 1],
            [1, 0, 0, 0, 0],
            [0, 0, 0, 0, 1],
            [1, 1, 0, 1, 1]]
Output: 3
Explanation:
grid[][] = [[1, 1, 0, 1, 1], 
            [1, 0, 0, 0, 0], 
            [0, 0, 0, 0, 1], 
            [1, 1, 0, 1, 1]]
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.

*/

// User function Template for C++

class Solution {
    private :
    void DFS(int row , int col , int m , int n , vector<vector<int>>&grid ,
    vector<vector<int>>&vis ,vector<pair<int ,int>>&list , int row0 , int col0 ){
        
        vis[row][col] = 1 ;
        list.push_back({row-row0 , col-col0}) ;
        int delrow[] = {-1 , 0 , 1 , 0} ;
        int delcol[] = { 0 , 1 , 0 , -1 } ;
        
        for(int i=0 ; i<4 ; i++){
            
            int neighrow = row + delrow[i] ;
            int neighcol = col + delcol[i] ;
            
            if(neighrow >= 0 && neighrow<m && neighcol>=0 && neighcol<n
            && !vis[neighrow][neighcol] && grid[neighrow][neighcol] == 1){
                DFS(neighrow , neighcol , m , n, grid , vis , list , row0 , col0) ;
            }
        }
        return ;
        
    }
    
    void BFS(int row , int col , int m , int n , vector<vector<int>>&grid ,
    vector<vector<int>>&vis ,vector<pair<int ,int>>&list , int row0 , int col0 ){
            
            queue<pair<int , int >>qe ;
            qe.push({row , col}) ;
            list.push_back({row-row0 , col-col0}) ;
            vis[row][col]  = 1 ;
            
            int delrow[] = {-1 , 0 , 1 , 0} ;
            int delcol[] = { 0 , 1 , 0 , -1 } ;
            
            while(!qe.empty()){
                int r = qe.front().first ;
                int c = qe.front().second ;
                qe.pop();
                
                for(int i=0 ; i<4 ; i++){
                    
                    int neighrow = r + delrow[i] ;
                    int neighcol = c + delcol[i] ;
                    
                    if(neighrow >= 0 && neighrow<m && neighcol>=0 && neighcol<n
                    && !vis[neighrow][neighcol] && grid[neighrow][neighcol] == 1){
                        qe.push({neighrow , neighcol}) ;
                        vis[neighrow][neighcol] = 1 ;
                        list.push_back({neighrow-row0 , neighcol-col0}) ;
                    }
                }
             }
        return ;
    }   
    
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size() ;
        int n = grid[0].size() ;
        
        
        vector<vector<int>>vis(m , vector<int>(n , 0)) ;
        set<vector<pair<int , int>>>st ;
        
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
               if(grid[i][j] == 1 && !vis[i][j]){
                    vector<pair<int , int>>list ;
                    //DFS(i , j , m , n,grid , vis , list , i , j) ;
                    BFS(i , j , m , n,grid , vis , list , i , j) ;
                    st.insert(list) ;
               }
            }
        }
        return st.size() ;
    }
};
    