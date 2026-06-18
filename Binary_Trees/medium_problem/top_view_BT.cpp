class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        if(root == NULL) return {} ;
        map<int , int>mp ;
        queue<pair<int , Node* >>qe ;
        
        qe.push({0 , root}) ;
        while(!qe.empty()){
            auto  node = qe.front() ;
            qe.pop() ;
            
            int level = node.first ;
            Node* p = node.second ;
            
            if(mp.find(level) == mp.end()){
                mp[level] = p->data ;
            }
            if(p->left != NULL) qe.push({level-1 , p->left}) ;
            if(p->right != NULL) qe.push({level+1 , p->right}) ;
        }
        vector<int>ans ;
        for(auto it : mp){
            ans.push_back(it.second) ;
        }
        return ans ;
    }
};