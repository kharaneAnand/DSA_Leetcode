//You are given an image represented by an m x n grid of integers image, where image[i][j] represents
//  the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].
//To perform a flood fill:


// Leetcode - 733 ; easy trvaersal problem but on matrix same catch is too find the nwighbour ;

class Solution {
    private :
    void BFS(int row ,  int col , int m , int n , int color ,vector<vector<int>>& image , vector<vector<int>>& visited){
        queue<pair<int,int>>qe ;
        qe.push({row , col}) ;
        visited[row][col] = 1 ;
        int prevColor = image[row][col] ;
        image[row][col] = color ;
        int delrow[] = {-1 , 0 , 1 , 0} ;
        int delcol[] = {0, 1, 0 , -1} ;

        while(!qe.empty()){
            int r = qe.front().first ;
            int c = qe.front().second ;
            qe.pop() ;

            for(int i=0 ; i<4 ; i++){
                  int neighrow = r + delrow[i] ;
                  int neighcol = c + delcol[i] ;
                  
                    if(neighrow>=0 && neighcol>=0 && neighrow<m && neighcol<n && !visited[neighrow][neighcol]
                    && image[neighrow][neighcol] == prevColor ) {
                        qe.push({neighrow , neighcol}) ;
                        visited[neighrow][neighcol] = 1 ;
                        image[neighrow][neighcol] = color ;
                    }
            }
        }
        return ;
    }

    void DFS(int row , int col , int m , int n , int color ,vector<vector<int>>& image , vector<vector<int>>& visited ){
        visited[row][col] = 1 ;
        int prevColor = image[row][col] ;
        image[row][col] = color ;

        int delrow[] = {-1 , 0 , 1, 0} ;
        int delcol[] = {0 , 1 , 0 , -1 } ;

        for(int i=0 ; i<4 ; i++){
            int neighrow = row + delrow[i] ;
            int neighcol = col + delcol[i] ;

            if(neighrow>=0 && neighrow<m && neighcol>=0 && neighcol<n && !visited[neighrow][neighcol] && 
            image[neighrow][neighcol] == prevColor) {
                DFS(neighrow , neighcol , m , n , color , image , visited) ;
            }
        }
        return ;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size() ;
        int n = image[0].size() ;
        vector<vector<int>>visited(m , vector<int>(n , 0)) ;
        
        //BFS(sr , sc , m , n , color , image , visited) ;
        DFS(sr , sc , m , n , color , image , visited) ;
        return image ;
    }
};


// SC :- (N X M) ;
// TC :- (N X M) ;