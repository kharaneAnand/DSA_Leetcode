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
    ListNode* middleNode(ListNode* head) {
        int sz = 0 ;
        ListNode* temp = head ;
        while(temp != nullptr){
            sz++ ;
            temp = temp->next ;
        }
        temp = head ;
        for(int i=0 ; i<sz/2 ; i++){
            temp = temp->next ;
        }
        return temp ;
    }
};


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // slow fast pointer 
        ListNode* slow = head ;
        ListNode* fast = head ;

        while(fast!=NULL && fast->next != NULL){
            slow = slow->next ;
            fast = fast->next->next ;
        }
        return slow ;
    }
};