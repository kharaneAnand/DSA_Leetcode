# 🚀 237. Delete Node in a Linked List | One Line Interview Trick | No Head Pointer Needed | Beats 100%

# Intuition
Normally, to delete a node in a linked list:
- We need access to the previous node.

But in this problem:
- We are only given the node to delete.
- Head pointer is not provided.

So we cannot:
- Traverse backward
- Find previous node

### Clever Trick
Instead of deleting the current node:
1. Copy the value of the next node into the current node.
2. Skip the next node.

Effectively:
- Current node becomes next node.
- Next node gets removed from the list.

# Approach
Suppose:

```text
4 -> 5 -> 1 -> 9
     ↑
   node
```

Copy value:

```text
4 -> 1 -> 1 -> 9
     ↑
```

Now skip next node:

```text
4 -> 1 -> 9
```

Node `5` is effectively deleted.

# Complexity
- Time complexity:
  - `O(1)`

- Space complexity:
  - `O(1)`

# Code
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {

public:

    void deleteNode(ListNode* node) {

        // Copy next node value
        node->val = node->next->val;

        // Skip next node
        node->next = node->next->next;
    }
};
```