class Solution {
    void count(TreeNode* root , int& cnt){
        if(root == NULL) return ;
        cnt++ ;
        count(root->left , cnt) ;
        count(root->right , cnt) ;
        return ;
    }
public:
    int countNodes(TreeNode* root) {
        int cnt = 0 ;
        count(root  , cnt) ;
        return cnt ;
    }
};