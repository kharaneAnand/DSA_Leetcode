class Solution {
public:
    bool isPalindrome(ListNode* head) {
        unordered_map<int , int>mp ;
        int idx = 0 ;
        ListNode* temp = head ;
        while(temp != nullptr){
            mp[idx++] = temp->val;
            temp = temp->next ;
        }

        int i = 0;
        int j = idx - 1;

        while(i < j){
            if(mp[i] != mp[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};

class Solution {
    private:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL ;
        ListNode* nxt = NULL ;
        ListNode* curr = head ;

        while(curr != nullptr){
            nxt = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = nxt ;
        }
        return prev ;
    }
public:
    bool isPalindrome(ListNode* head) {
        int sz = 0 ;
        ListNode* temp = head ;

        while(temp != nullptr){
            sz++ ;
            temp = temp->next ;
        }
        
        temp = head ;
        int a = sz/2 ;
        while(a--){
            temp = temp->next ;
        }
        ListNode* newhead = reverse(temp) ;

        temp = head ;
        while(newhead != nullptr){
            if(temp->val != newhead->val) return false ;
            temp = temp->next ;
            newhead = newhead->next ;
        }
        return true ;
    }
};