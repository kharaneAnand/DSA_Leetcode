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
    private :
    ListNode* reverse(ListNode* head){
        if(head == NULL) return NULL ;
        ListNode* curr = head ;
        ListNode* prev = NULL ;
        ListNode* nxt = NULL ;

        while(curr != NULL){
            nxt = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = nxt ;
        }
        return prev ;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL || k == 0) return head;
        int size = 0 ;
        ListNode* temp = head ;

        while(temp != NULL){
            size++ ;
            temp = temp->next ;
        }
        k = k % size ;
        temp = head ;
        int count = 1 ;
        while(count < size - k){
            count++ ;
            temp = temp->next ;
        }
        ListNode* nxt = temp->next ;
        temp->next = NULL ;

        head = reverse(head) ;
        nxt = reverse(nxt) ;

        temp = head ;
        while(temp->next != NULL) temp = temp->next ;
        temp->next = nxt ;
        head = reverse(head) ;
        return head ;
    }
};