/*

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi 
first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 Leetcode :- 207 ;

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

*/

//m-1 DFS topological sort 
class Solution {
    private:
    bool DFS(int node , vector<vector<int>>&adjlist ,  vector<int>&vis , vector<int>&pathvis){
        vis[node] = 1 ;
        pathvis[node] = 1 ;
        for(auto ele : adjlist[node]){
            if(!vis[ele]){
               if(DFS(ele , adjlist , vis , pathvis)) return true ;
            }
            else if(vis[ele] && pathvis[ele]) return true ;
        }

        pathvis[node] = 0 ;
        return false ;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjlist(numCourses) ;
        vector<int>vis(numCourses) ;
        vector<int>pathvis(numCourses) ;
        for(int i=0 ; i<prerequisites.size() ; i++){
            int u = prerequisites[i][0] ;
            int v = prerequisites[i][1] ;

            adjlist[v].push_back(u) ;
        }

       for(int i=0 ; i<numCourses ; i++){
            if(!vis[i]){
                if(DFS(i , adjlist , vis , pathvis)) return false ;
            }
       }
       return true  ;
    }
};


// M-2 using kahans algorithm ;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        if(ans.size() == numCourses ) return true ;
        else return false ;
    }
};
