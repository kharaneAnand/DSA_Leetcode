  class cmp {
    public :
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
}; 
class Solution {
    public:
    ListNode* sortList(ListNode* head) {
        priority_queue<ListNode* , vector<ListNode*> , cmp >pq ;

        ListNode* temp = head ;
        while(temp != nullptr){
            pq.push(temp) ;
            temp = temp->next ;
        }

        ListNode* ans = new ListNode(0) ;
        temp = ans ;

        while(!pq.empty()){
            ListNode* ele = pq.top();
            pq.pop() ;
            temp->next = ele ;
            temp = temp->next ;
        }
        temp->next = NULL ;
        return ans->next  ;
    }
};


// method -2 using merge sort 

class Solution {
    private :
    ListNode* merge(ListNode* head1 , ListNode* head2){
        ListNode* temp = new ListNode(0) ;
        ListNode* ans = temp ;

        while(head1 != NULL && head2 != NULL){
            if(head1->val < head2->val){
                temp->next = head1 ;
                head1 = head1->next ;
                temp = temp->next ;
            }
            else{
                temp->next = head2 ;
                head2 = head2->next ;
                temp = temp->next ;
            }
        }

        while(head1 != NULL){
            temp->next = head1 ;
            head1 = head1->next ;
            temp = temp->next ;
        }
        while(head2 != NULL){
            temp->next = head2 ;
            head2 = head2->next ;
            temp = temp->next ;
        }
        return ans->next ;
    }
public:
    ListNode* sortList(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr) return head ;
        ListNode* s = head ;
        ListNode* f = head->next ;

        while(f && f->next) {
            s = s->next;
            f = f->next->next;
        }

        ListNode* right = s->next ;
        s->next = nullptr ;

        ListNode* leftsorted = sortList(head) ;
        ListNode* rightsorted = sortList(right) ;

        ListNode* ans = merge(leftsorted , rightsorted) ;
        return ans ;

    }
};