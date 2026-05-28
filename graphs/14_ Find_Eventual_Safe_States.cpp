/*\

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path 
starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

*/

// LEETCODE :- 802 
class Solution {
    private :

    bool DFS(int node , vector<int>&vis , vector<int>&pathvis ,vector<int>&check , vector<vector<int>>&graph){
        vis[node] = 1 ;
        pathvis[node] = 1;
        check[node] = 0 ;

        for(auto ele : graph[node]){
            if(!vis[ele]){
                if(DFS(ele , vis , pathvis , check , graph)){
                    check[ele] = 0 ;
                    return true ;
                }
            }
            else if(pathvis[ele] && vis[ele]) {
                check[ele] = 0 ;
                return true ;
            }
        }

        check[node] = 1;
        pathvis[node] = 0 ;
        return false ;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size() ;

        vector<int>vis(v , 0) ;
        vector<int>pathvis(v ,0) ;
        vector<int>check(v , 0) ;
        vector<int>ans ; 

        for(int i=0 ; i<v ; i++){
            if(!vis[i]) DFS(i , vis , pathvis , check  , graph) ;
        }   

        for(int i=0 ; i<v ; i++){
            if(check[i]== 1) ans.push_back(i) ;
        }
        return ans ;
    }
};