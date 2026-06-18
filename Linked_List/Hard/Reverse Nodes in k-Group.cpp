class Solution {
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        int len = 0;
        ListNode* temp = head;

        while (temp) {
            len++;
            temp = temp->next;
        }

        ListNode* curr = head;
        ListNode* prevTail = NULL;
        ListNode* newHead = head;

        while (len >= k) {
            ListNode* groupHead = curr;

            for (int i = 1; i < k; i++) {
                curr = curr->next;
            }

            ListNode* nextGroup = curr->next;
            curr->next = NULL;

            ListNode* reversedHead = reverse(groupHead);

            if (prevTail == NULL) {
                newHead = reversedHead;
            } else {
                prevTail->next = reversedHead;
            }

            prevTail = groupHead;
            curr = nextGroup;

            len -= k;
        }

        prevTail->next = curr;

        return newHead;
    }
};