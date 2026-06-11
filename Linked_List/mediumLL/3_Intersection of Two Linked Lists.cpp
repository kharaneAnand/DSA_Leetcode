
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0 ;
        int len2 = 0 ;

        ListNode* a = headA ;
        while(a != nullptr){
            len1++ ;
            a = a->next ;
        }

        a= headB ;
        while(a!=NULL){
            len2++ ;
            a = a->next ;
        }

        int diff = abs(len1 - len2) ;
        ListNode* t1 = headA ;
        ListNode* t2 = headB ;
        if(len1>len2){
            for(int i=1 ; i<=diff ; i++){
                t1 = t1->next ;
            }
            while(t1 != t2){
                t1 = t1->next ;
                t2 = t2->next ;
            }
            return t1 ;
        }
        else {
            for(int i=1 ; i<=diff ; i++){
                t2 = t2->next ;
            }
            while(t1 != t2){
                t1 = t1->next ;
                t2 = t2->next ;
            }
            return t2 ;
        }
        return t1 ;
    }
};