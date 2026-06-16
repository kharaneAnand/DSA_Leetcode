class Solution {
    private :
     int sum(TreeNode* root , int& ans){
        if(root == NULL) return 0 ;
        int leftsum = max(0 ,sum(root->left , ans)) ;
        int rightsum = max(0 ,sum(root->right , ans)) ;

        int add = root->val + leftsum + rightsum ;
        ans = max(ans , add) ;
        return root->val + max(leftsum , rightsum ) ;
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN ;
        sum(root ,ans ) ;
        return ans ;
    }
};