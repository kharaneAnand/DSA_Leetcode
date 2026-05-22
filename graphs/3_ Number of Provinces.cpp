// A province is a group of directly or indirectly connected cities and no other cities outside of the group. 
// LeetCode question number 547 ;

class Solution {
    private :
     void dfs(vector<vector<int>>&adj , vector<int>&vis , int node){
        vis[node] = 1;

        for(auto ele : adj[node]){
            if(!vis[ele]){
                dfs(adj , vis , ele) ;
            }
        }
     }
     public :
     int findCircleNum(vector<vector<int>>& isConnected){
        int v = isConnected.size() ;

        vector<vector<int>>adj(v) ;
        for(int i=0 ; i<v ; i++){
            for(int j=0 ; j<v ; j++){
                if(isConnected[i][j] ==1 && i!=j) {
                    adj[i].push_back(j) ;
                    adj[j].push_back(i) ;
                }
            }
        }

        vector<int>vis(v , 0) ;
        int cnt = 0 ;

        for(int i=0 ; i<v ; i++){
            if(!vis[i]) {
                cnt++ ;
                dfs(adj , vis , i) ; 
            }
        }
        return cnt ;
     }
};


// space complexity :- not considering the adjList in this most of the question adjList is given insted of matrix so ;
// SC :- 0(n) vis + 0(n) recussive stack ;
// tc :- 0(n) + 0(v+2E) ;



// 2nd approch using BFS traversal same methood but traversal technique changes 

class Solution {
    private :
     void bfs(vector<vector<int>>&adj , vector<int>&vis , int node){
        queue<int>qe ;
        qe.push(node) ;
        vis[node] = 1;

        while(!qe.empty()){
            int neigh = qe.front() ;
            qe.pop() ;

            for(auto ele : adj[neigh]){
                if(!vis[ele]){
                     qe.push(ele) ;
                     vis[ele] = 1;
                }
            }
        }
        return  ;
     }
     public :
     int findCircleNum(vector<vector<int>>& isConnected){
        int v = isConnected.size() ;

        vector<vector<int>>adj(v) ;
        for(int i=0 ; i<v ; i++){
            for(int j=0 ; j<v ; j++){
                if(isConnected[i][j] ==1 && i!=j) {
                    adj[i].push_back(j) ;
                    adj[j].push_back(i) ;
                }
            }
        }

        vector<int>vis(v , 0) ;
        int cnt = 0 ;

        for(int i=0 ; i<v ; i++){
            if(!vis[i]) {
                cnt++ ;
                dfs(adj , vis , i) ; 
            }
        }
        return cnt ;
     }
};
