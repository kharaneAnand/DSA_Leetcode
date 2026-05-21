//Depth first search 
// zero level indexing graph (GFG :- DFS TRaversal question)  ;


class solution {
    private :
    void dfs_graph(vector<vector<int>>&adj , vector<int>&vis , vector<int>&dfs , int node){
        vis[node] = 1 ;
        dfs.push_back(node) ;

        for(auto ele : adj[node]){
            if(!ele){
                dfs(adj , vis , dfs , ele) ;
            }
        }
    }

    public :

    vector<int>dfs(vector<vector<int>>&adj){
        int v = adj.szie()  ;
        vector<int>vis(v , 0) ;
        vector<int>dfs ;

        dfs_graph(adj , vis , dfs , 0) ;
        return dfs ;
    }
};


// space complexity :- 0(n) visited array + 0(n) dfs storing graph + 0(n) recurssive stack ;
// time complexity :- 0(N) fuction calls no of node time + 0(2E) and neighbours or depth that for loop
//                          is no of degree sumation which is 2 into no. of Edges ;

