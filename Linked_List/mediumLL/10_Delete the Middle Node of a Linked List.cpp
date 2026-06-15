
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode* prev = nullptr ;
        ListNode* nxt = nullptr ;
        ListNode* s = head ;
        ListNode* f = head ;

        while(f != nullptr && f->next != nullptr){
            prev = s ;
            s = s->next ;
            f = f->next->next ;
        }
        nxt = s->next ;

        prev->next = nxt ;
        s->next = nullptr ;
        return head ;
    }
};