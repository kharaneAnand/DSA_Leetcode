//Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][],
//  where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph
//  contains a cycle or not.

//Note: The graph can have multiple component.

class Solution {
    bool BFS( vector<vector<int>>&adj , vector<int>&vis , int node){
        queue<pair<int , int >> qe ;
        qe.push({node , -1}) ;
        vis[node] = 1 ;
        
        while(!qe.empty()){
            int child = qe.front().first ;
            int parent = qe.front().second ;
            qe.pop() ;
            
            for(auto ele : adj[child]){
                if(!vis[ele]){
                    qe.push({ele , child}) ;
                    vis[ele] = 1 ;
                }
                else if(parent != ele) {
                    return true ;
                }
            }
        }
        return false ;
    }
    
    bool DFS(vector<vector<int>>&adj , vector<int>&vis , int node , int parent){
        vis[node] = 1 ;
        
        for(auto ele : adj[node]){
            if(!vis[ele]) {
               if(DFS(adj , vis , ele , node) ) return true ;
            }
            else if(parent != ele) return true ;
        }
        return false ;
    }
        
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int>vis(V , 0) ;
        vector<vector<int>>adj(V) ;
        
        for(int i=0 ; i<edges.size() ; i++){
            int node1 = edges[i][0] ;
            int node2 = edges[i][1] ;
            
            adj[node1].push_back(node2) ;
            adj[node2].push_back(node1) ;
        }
        
        for(int i=0 ; i<V ; i++){
            if(!vis[i]) {
                bool ans = DFS( adj ,vis , i , -1);
                if(ans == true) return true ;
            }
        }
        return false ;
    }
};


// TC :- 0(N+2E)
//sc :-  0(N) + 0(N) 