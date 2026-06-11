class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode* , int>mp ;

        ListNode* temp = head ;
        while(temp != nullptr){
            if(mp.find(temp) != mp.end()) return temp ;
            else mp[temp]= temp->val ;
            temp = temp->next ;
        }
        return nullptr ;
    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* f = head ;
        ListNode* s = head ;
        ListNode* temp = head ;
        bool flag = false ;

        while(f!=nullptr && f->next != nullptr){
            s = s->next ;
            f = f->next->next ;

            if(s==f){
                flag = true ;
                break ;
            }
        }

        if(flag == false) return nullptr ;

        while(temp != s){
            s = s->next ;
            temp = temp->next ;
        }
        return temp ;
    }
};