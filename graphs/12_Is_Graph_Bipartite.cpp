// Leetcode :- 785 ;

/* color the graph with 2 color such that no adjacent nodes have same color */

class Solution {
    private :
    bool BFS(vector<vector<int>>& graph , vector<int>&vis , int node ){
        queue<int>qe ;
        qe.push(node) ;
        vis[node] = 0 ;

        while(!qe.empty()){
            int Node = qe.front() ;
            int NodeColor = vis[Node] ;
            qe.pop() ;

            for(auto neigh : graph[Node]){
                 if(vis[neigh] == -1 ){
                    qe.push(neigh) ;
                   vis[neigh] = 1 - NodeColor ;
                 }
                 else if(vis[neigh] == NodeColor) return false ;
            } 
        }
        return true ;
    }

    bool DFS(vector<vector<int>>& graph , vector<int>&vis , int node , int color){
        vis[node] = color ;
        for(auto neigh : graph[node]){
            if(vis[neigh] == -1){
               if(!DFS(graph , vis , neigh , 1-color)) return false ;
            }
            else if(vis[neigh] == color) return false ;
        }
        return true ;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size() ;
        vector<int>vis(v , -1) ;
        
        for(int i=0 ; i<v ; i++){
            if(vis[i] == -1 ) {
                //if(!BFS(graph , vis , i )) return false ;
                if(!DFS(graph , vis , i , 0 )) return false ;
            }
        }
        return true ;
    }
};