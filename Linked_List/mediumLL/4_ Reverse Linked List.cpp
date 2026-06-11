

// m-1 brute force ;

class Solution {
    private :

    ListNode* getNode(int idx , ListNode* head){
        for(int i=0 ; i<idx ; i++){
            head = head->next ;
        }
        return head ;
    }
public:
    ListNode* reverseList(ListNode* head) {
        // method -01 brute force ; // swpping vala 
        int i=0 ;
        int j = 0 ;
        ListNode* temp = head ;
        while(temp != NULL){
            j++ ;
            temp = temp->next ; 
        }
       j-- ;
        while(i<j){
            ListNode* left = getNode(i , head) ;
            ListNode* right = getNode(j , head) ;

            int t = left->val ;
            left->val = right->val ;
            right->val = t ;
            i++ ;
            j-- ; 
        }
        return head ;
    }
};


// optimize :- 3 pointer approch 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr ;
        ListNode* curr = head ;
        ListNode* nxt = nullptr ;

        while(curr != nullptr){
            nxt = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = nxt ;
        }
        return prev ;
    }
};


// recursive code 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head ;
        ListNode* newhead = reverseList(head->next) ;
        ListNode* front = head->next ;
        front->next = head ;
        head->next = nullptr ;
        return newhead ;
    }
};