/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course
 bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers,
 return any of them. If it is impossible to finish all courses, return an empty array.


Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. 
So the correct course order is [0,1].

*/


//m-1 kahans algorithm ;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          vector<vector<int>>adjlist(numCourses) ;
        vector<int>vis(numCourses) ;
        vector<int>indgree(numCourses , 0) ;
        vector<int>ans;

        for(int i=0 ; i<prerequisites.size() ; i++){
            int u = prerequisites[i][0] ;
            int v = prerequisites[i][1] ;

            adjlist[v].push_back(u) ;
            indgree[u]++ ;
        }

        queue<int>qe ;
        for(int i=0 ; i<numCourses ;i++){
            if(indgree[i] == 0){
            qe.push(i) ;
            vis[i] = 1 ;
            ans.push_back(i) ;
            }
        }
        while(!qe.empty()){
            int node = qe.front() ;
            qe.pop() ;

            for(auto ele : adjlist[node]){
                indgree[ele]-- ;

                if(indgree[ele] == 0){
                    qe.push(ele) ;
                    vis[ele] = 1 ;
                    ans.push_back(ele) ;
                }
            }
        }
        if(ans.size() != numCourses)
             return {};
      return ans ;
    }
};


// M-2 DFS 
class Solution {
    private:
    bool DFS(int node , vector<vector<int>>&adjlist , stack<int>&st ,vector<int>&vis , vector<int>&pathvis){
        vis[node] = 1 ;
        pathvis[node] = 1 ;
        for(auto ele : adjlist[node]){
            if(!vis[ele]){
               if(DFS(ele , adjlist ,st , vis , pathvis)) return true ;
            }
            else if(vis[ele] && pathvis[ele]) return true ;
        }
        st.push(node) ;
        pathvis[node] = 0 ;
        return false ;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>>adjlist(numCourses) ;
         vector<int>vis(numCourses) ;
         vector<int>pathvis(numCourses) ;
         stack<int>st ;
        for(int i=0 ; i<prerequisites.size() ; i++){
            int u = prerequisites[i][0] ;
            int v = prerequisites[i][1] ;

            adjlist[v].push_back(u) ;
        }

        for(int i=0 ; i<numCourses ; i++){
                if(!vis[i]) DFS(i , adjlist ,st , vis , pathvis) ;     
        }

        if(st.size() != numCourses) return {} ;
        vector<int>ans ;

        while(!st.empty()){
            ans.push_back(st.top()) ;
            st.pop() ;
        }
        return ans ;
       }
      
};