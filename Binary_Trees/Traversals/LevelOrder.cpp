/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>qe ;
        vector<vector<int>>ans ;

        if(root == nullptr) return ans ;
        qe.push(root) ; 
        while(!qe.empty()){
          int size = qe.size() ;
          vector<int>level ;
          for(int i=0 ; i<size ; i++){
            TreeNode* node = qe.front() ;
            qe.pop() ;

            if(node->left != NULL) qe.push(node->left) ;
            if(node->right != NULL) qe.push(node->right) ;
            level.push_back(node->val) ; 
          }
          ans.push_back(level) ;
        }
        return ans ;
    }
};