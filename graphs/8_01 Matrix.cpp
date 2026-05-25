//Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
//The distance between two cells sharing a common edge is 1.

//Leetcode :- 542 ;
//Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
//Output: [[0,0,0],[0,1,0],[0,0,0]]


class Solution {
    private:
    void BFS(int m , int n , vector<vector<int>>& mat , vector<vector<int>>& vis , vector<vector<int>>&Dis){

        queue<pair<pair<int , int> , int>>qe ;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(mat[i][j] == 0) {
                    qe.push({{i , j} , 0} ) ;
                    vis[i][j] = 1 ;
                    Dis[i][j] = 0 ;
                }
            }
        }

        int delrow[] = {-1 , 0 , 1 ,0} ;
        int delcol[] = { 0 , 1 , 0 , -1} ;

        while(!qe.empty()){
            int row = qe.front().first.first ;
            int col = qe.front().first.second ;
            int d = qe.front().second ;
            qe.pop() ;

            for(int i=0 ; i<4 ; i++){
                int neighrow = row + delrow[i] ;
                int neighcol = col + delcol[i] ;

              
                if(neighrow>=0 &&  neighrow<m && neighcol>=0 && neighcol<n && !vis[neighrow][neighcol] && mat[neighrow][neighcol] == 1){
                    qe.push({{neighrow , neighcol} , d+1}) ;
                    vis[neighrow][neighcol] = 1 ;
                    Dis[neighrow][neighcol] = d+1 ;
                }
            }
        }
        return ;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size() ;
        int n = mat[0].size() ;
        vector<vector<int>>vis(m , vector<int>(n , 0)) ;
        vector<vector<int>>Dis(m , vector<int>(n , 0)) ;
        BFS(m , n , mat , vis , Dis) ;

        return Dis ;
    }
};


// TC :- 0(M X N ) ;
// Sc :- 0(M X N) ;


 