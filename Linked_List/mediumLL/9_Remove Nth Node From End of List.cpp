class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0 ;
        ListNode* temp = head ;

        while(temp != nullptr){
            size++ ;
            temp = temp->next ;
        }
     
        int a = size -n-1 ;

        temp = head ;
        if(size == n) return head->next ;
        if(temp == nullptr || temp->next == nullptr) return NULL ;
        while(a > 0){
            temp = temp->next ;
            a-- ;
        }
        //cout<<temp->val ;
       if(temp->next != nullptr) temp->next = temp->next->next ;
        return head ;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* slow = head ;
        ListNode* fast = head ;

        if(head== nullptr || head->next == nullptr) return nullptr ;

        for(int i=0 ; i<n+1 ; i++){
            if(fast == nullptr) return head->next ;
            fast = fast->next ;
        }

        while(fast!=nullptr){
            fast = fast->next ;
            slow = slow->next ;
        }
        slow->next = slow->next->next ;
        return head ;
    }
};