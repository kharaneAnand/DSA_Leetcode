/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges,
 check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], 
where each entry edges[i] = [u, v] denotes an edge from vertex u to v.

*/

//Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 0], [2, 3]]
//Output: true
// Explanation: The diagram clearly shows a cycle 0 → 1 → 2 → 0


class Solution {
    bool DFS(int node, vector<vector<int>>& adjList,
             vector<int>& vis, vector<int>& visPath) {

        vis[node] = 1;
        visPath[node] = 1;

        for (auto ele : adjList[node]) {

            if (!vis[ele]) {
                if (DFS(ele, adjList, vis, visPath))
                    return true;
            }

            else if (visPath[ele]) {
                return true;
            }
        }

        visPath[node] = 0;
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adjList(V);

        // Create adjacency list
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
        }

        vector<int> vis(V, 0);
        vector<int> visPath(V, 0);

        // Run DFS for all vertices
        for (int i = 0; i < V; i++) {

            if (!vis[i]) {
                if (DFS(i, adjList, vis, visPath))
                    return true;
            }
        }

        return false;
    }
}; 

// using the topological sort using the kahans algorithm ;
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>indgree(V ,0) ;
        vector<vector<int>>adjlist(V) ; 
        vector<int>ans ;
        
        for(int i=0 ; i<edges.size() ; i++){
            int u = edges[i][0] ;
            int v = edges[i][1] ;
            
            adjlist[u].push_back(v) ;
            indgree[v]++ ;
        }
        
        queue<int>qe ;
        for(int i=0 ; i<V ; i++){
            if(indgree[i] == 0) {
                qe.push(i) ;
                ans.push_back(indgree[i]) ;
            }
        }
        
        while(!qe.empty()){
            int node = qe.front() ;
            qe.pop() ;
            
            for(auto ele : adjlist[node]){
                indgree[ele]-- ;
                
                if(indgree[ele] == 0){
                     qe.push(ele) ;
                      ans.push_back(ele) ;
                }
            }
        }
        if(ans.size()!= V) return true  ;
        else return false  ;
    }
};


// TC :- 0(N + E) ;
// SC :- 0(N + N) ;