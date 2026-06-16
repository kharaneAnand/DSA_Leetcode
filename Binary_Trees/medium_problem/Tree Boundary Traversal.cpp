/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    private :
    
    bool isleaf(Node* root){
        if(root == NULL) return true ;
        if( root->left == NULL && root->right==NULL) return true ;
        else return false ;
    }
    void leftBoundary(Node* root , vector<int>&ans){
         Node* curr = root->left ;
         
         while(curr){
             if(!isleaf(curr)) ans.push_back(curr->data) ;
             if(curr->left) curr = curr->left ;
             else curr = curr->right ;
         }
        return ;    
    }
    
    void RightBoundary(Node* root , vector<int>&ans){
        Node* curr = root->right ;
        vector<int>temp ;
        
        while(curr){
            if(!isleaf(curr)) temp.push_back(curr->data) ;
            if(curr->right) curr = curr->right ;
            else curr = curr->left ;
        }
        
        for(int i=temp.size()-1 ; i>=0 ; i-- ){
            ans.push_back(temp[i]) ;
        }
        return ;
    }
    
    void addLeaves(Node* root , vector<int>&ans){
        if(isleaf(root)){
            ans.push_back(root->data) ;
            return ;
        }
        if(root->left) addLeaves(root->left , ans) ;
        if(root->right) addLeaves(root->right , ans) ;  
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans ;
        if(!root) return ans ;
        if(!isleaf(root)) ans.push_back(root->data) ;
        leftBoundary(root , ans) ;
        addLeaves(root , ans) ;
        RightBoundary(root , ans) ;
        
        return ans ;
    }
};