class Solution {
    private :
    bool check(TreeNode* node1 , TreeNode* node2){
        if(node1== NULL && node2==NULL) return true ;
        if(node1== NULL || node2==NULL) return false ;
        if(node1->val != node2->val) return false ;
        return check(node1->left , node2->right) && check(node1->right , node2->left) ;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true ;
        bool flag = check(root->left , root->right) ;
        return flag ;
    }
};