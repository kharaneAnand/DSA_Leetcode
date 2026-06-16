class Solution {
    int maxHeight(TreeNode* root , int level , int mx ){
        if(root == NULL) return mx ;
        mx = max(mx , level) ;
        if(root->left != nullptr) mx = maxHeight(root->left , level+1 , mx ) ;
        if(root->right != nullptr) mx = maxHeight(root->right , level+1 , mx) ;
        return mx ;
    }
public:
    int maxDepth(TreeNode* root) {
        int ans = 0 ;
        if(root == NULL) return 0 ;
        ans = maxHeight(root , 1 , 1) ;
        return ans ;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0 ;
        return  1 + max(maxDepth(root->left) , maxDepth(root->right)) ;
    }
};