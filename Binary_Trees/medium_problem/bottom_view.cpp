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
  public:
    vector<int> bottomView(Node *root) {
        // code here
        
        if(root == NULL) return {} ;
        queue<pair<int , Node*>>qe ;
        map<int , int>mp ;
        
        qe.push({0 , root}) ;
        
        while(!qe.empty()){
            auto p = qe.front() ;
            qe.pop() ;
            
            int line = p.first ;
            Node* node = p.second ;
            
            if(mp.find(line) != mp.end()){
                mp[line] = node->data;
            }
            else mp[line] = node->data  ;
            
            if(node->left != nullptr) qe.push({line-1 , node->left}) ;
            if(node->right != nullptr) qe.push({line+1 , node->right}) ;
        }
        
        vector<int>ans ;
        
        for(auto it : mp){
            ans.push_back(it.second) ;
        }
        return ans ;
        
    }
};