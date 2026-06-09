// User function Template for C++
class Solution {
    private :
    void toposort(stack<int>&st , vector<vector<pair<int,int>>>&adj , vector<int>&vis , int src){
        vis[src] = 1 ;
        
        for(auto ele : adj[src]){
            int v = ele.first ;
            if(!vis[v]){
                toposort(st , adj , vis , v) ;
            }
        }
        st.push(src) ;
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        
        for(int i=0 ; i<E ; i++){
            int u = edges[i][0] ;
            int v = edges[i][1] ;
            int wt =edges[i][2] ;
            
            adj[u].push_back({v,wt}) ;
        }
        
        vector<int>vis(V , 0) ;
        stack<int>st ;
        
        
        // step 01 - find toposort 
        for(int i=0 ; i<V ; i++){
            if(!vis[i]) toposort(st , adj , vis , i) ;
        }
        
        // step 2 :- distance ka khel 
        vector<int>dis(V , INT_MAX) ;
        dis[0] = 0 ;
        
        while(!st.empty()){
            int node = st.top() ;
            st.pop() ;
            
            for(auto ele : adj[node]){
                int v = ele.first ;
                int wt = ele.second ;
                
                if(dis[node] != INT_MAX && dis[node] + wt < dis[v]){
                    dis[v] = dis[node] + wt ;
                }
            }
         }
         
         for(int i=0 ; i<V ; i++){
             if(dis[i] == INT_MAX) dis[i] = -1 ;
         }
       return dis ;
        
    }
};
