class Solution {
    private :
    int diameter = 0 ;
    int check(TreeNode* root ){
        if(root == NULL) return 0 ;
        int left = check(root->left) ;
        int right = check(root->right) ;

         diameter = max(diameter , left + right) ;
        return 1 + max(left , right) ;
    }   
public:
    int diameterOfBinaryTree(TreeNode* root) {
        check(root) ;
        return diameter ;
    }
};