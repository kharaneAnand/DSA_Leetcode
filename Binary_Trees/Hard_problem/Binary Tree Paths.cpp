class Solution {
    private :
    void path(TreeNode* root , string ans , vector<string>&res){
        if(root == NULL){
            return ;
        }
        ans += to_string(root->val) ;

         if (root->left == NULL && root->right == NULL) {
            res.push_back(ans);
            return;
        }
        ans += "->" ;
        path(root->left , ans , res) ;
        path(root->right , ans , res) ;
        return ;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res ;
        string ans = "" ;
        path(root , ans , res) ;
        return res ;
    }
};