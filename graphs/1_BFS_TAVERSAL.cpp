// LEVEL _WISE TRAVERSAL OR BREADTH FIRST SEARCH ;
// lets say zero based indexing graph and graph is created using a adj matrix 



vector<int>bfsTraversal(vector<vector<int>>&adj){
    queue<int>qe ;
    vector<int>bfs ;
    int v = adj.size() ;
    vector<int>visited(v , 0) ;

    qe.push(0) ;
    visited[0] = 1 ;

    while(!qe.empty()){

        int node = qe.front() ;
        qe.pop() ;
        bfs.push_back(node) ;

        for(auto neigh : adj[node]){
            if(visited[neigh] != 1){
                qu.push(neigh) ;
                visited[neigh] = 1 ;
            }
        }
    }

    return bfs ;
}