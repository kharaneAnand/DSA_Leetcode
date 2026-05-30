// Topological sort 

class Solution {
    private :
    void DFS(vector<vector<int>>&adjlist , int node , vector<int>&vis , stack<int>&st){
        vis[node] = 1 ;
        
        for(int ele : adjlist[node]){
            if(!vis[ele]) DFS(adjlist , ele , vis , st) ;
        }
        
        st.push(node) ;
        return ;
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adjlist(V) ;
        for(int i=0 ; i<edges.size() ; i++){
            int u = edges[i][0] ;
            int v = edges[i][1] ;
            
            adjlist[u].push_back(v) ;
        }
        vector<int>vis(V , 0) ;
        stack<int>st ;
        
        for(int i=0 ; i<V ; i++){
            if(!vis[i]) DFS(adjlist , i , vis , st) ;
        }
        
        vector<int>ans ;
        while(!st.empty()){
            int tp = st.top() ;
            st.pop() ;
            ans.push_back(tp) ;
        }
        return ans ;
    }
};
