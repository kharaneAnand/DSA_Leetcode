class Solution {
    private :
    void BFS(vector<vector<int>>&adjlist ,vector<int>&vis , vector<int>&indgree ,
    vector<int>&ans){
        queue<int>qe ;
        
        for(int i=0 ; i<indgree.size() ; i++){
            if(indgree[i] == 0) {
                qe.push(i) ;
                vis[i] = 1 ;
                ans.push_back(i) ;
            }
        }
        
        while(!qe.empty()){
            int node = qe.front() ;
            qe.pop() ;
            
            for(auto ele : adjlist[node]){
                indgree[ele] -= 1 ;
                if(indgree[ele] == 0){
                    qe.push(ele) ;
                    vis[ele] = 1 ;
                    ans.push_back(ele) ;
                }
            }
        }
        return ;
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>indgree(V , 0) ;
        vector<int>vis(V , 0) ;
        vector<vector<int>>adjList(V) ; 
        
        for(int i=0 ; i<edges.size() ; i++){
            int u = edges[i][0] ;
            int v = edges[i][1] ;
            
            adjList[u].push_back(v) ;
            indgree[v]+=1 ;
        }
            
        vector<int>ans ;
        
        BFS(adjList , vis , indgree , ans) ;
        return ans ;
    }
};