// 2130. Maximum Twin Sum of a Linked List

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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head ;
        ListNode* prev = nullptr ;
        ListNode* nxt = nullptr ;

        while(curr != nullptr){
            nxt = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = nxt ;
        }
        return prev ;
    }
public:
    int pairSum(ListNode* head) {
        ListNode* s = head ;
        ListNode* f = head->next ;

        while(f!=nullptr && f->next != nullptr){
            s = s->next ;
            f = f->next->next ;
        }
        ListNode* head2 = s->next ;
        s->next = nullptr ;

        head2 = reverse(head2) ;
        ListNode* temp = head ;
        ListNode* temp2 = head2 ;

        int sum = 0 ;
        while(temp != NULL && temp2 != NULL){
            int add = temp->val + temp2->val ;
            sum = max(sum , add) ;
            temp = temp->next ;
            temp2 = temp2->next ;
        }
        return sum ;
    }
};