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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int count = 0 ;

        ListNode* temp = l1 ;
        ListNode* temp2 = l2 ;

        ListNode* head = new ListNode(-1) ;
        ListNode* ans = head ;

        int carry = 0 ;

        while(temp!=NULL && temp2!=NULL){
            int add = temp->val + temp2->val + carry ;
            int val = add % 10 ;
            ListNode* node = new ListNode(val) ;
            carry = add/10 ;
            ans->next = node ;
            ans = ans->next ;
            temp = temp->next ;
            temp2 = temp2->next ;
        }

        while(temp != NULL || temp2 != NULL){
            int add = 0 ;
            if(temp != NULL) 
            {
                add = temp->val + carry ;
                temp = temp->next ;
            }
            else {
                add = temp2->val + carry ;
                temp2 = temp2->next ;
            }
            int val = add % 10 ;
            ListNode* node = new ListNode(val) ;
            carry = add / 10 ;
            ans->next = node ;
            ans = ans->next ;
        }

        if(carry){
            ListNode* node = new ListNode(carry) ;
            ans->next = node ;
        }
        return head->next ;
    }
};