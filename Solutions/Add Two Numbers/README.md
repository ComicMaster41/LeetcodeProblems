## LeetCode #2 — Add Two Numbers (C++ / Linked List)

### Problem

You’re given **two non-empty linked lists** representing two non-negative integers.
Each node contains a single digit, and the digits are stored in **reverse order** (the 1’s digit is first).
Your goal is to **add the two numbers** and return the sum as a **new linked list**, also in reverse order.

---

### Key Idea / Trick

A common instinct is to **reverse the lists** and convert them to integers—but you don’t need to.

Instead, you:

1. Traverse both lists **digit-by-digit**
2. Add the digits **plus a carry**
3. Store `(sum % 10)` in the result node
4. Update `carry = sum / 10`
5. Continue until both lists are finished
6. If there’s leftover `carry`, append a final node

---

### Edge Cases to Handle

* One list is **shorter** than the other (treat missing digits like `0`)
* A list could have **just one node**
* There may be a **carry left over** after both lists end (e.g., `5 + 5 = 10`)

---

### What I Learned

* How to **construct and extend** a linked list in C++
* How to **traverse multiple linked lists** safely
* How to implement **addition with carry** cleanly (without reversing)

---

### Code Implementation (C++)

```cpp
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
        int carry = 0;

        ListNode* res = new ListNode();
        ListNode* resHead = res;

        resHead->val = (l1->val + l2->val) % 10;
        carry = (l1->val + l2->val) / 10;

        l1 = l1->next;
        l2 = l2->next;

        while (l1 != NULL || l2 != NULL) {
            resHead->next = new ListNode();
            resHead = resHead->next;

            if (l1 == NULL) {
                resHead->val = (l2->val + carry) % 10;
                carry = (l2->val + carry) / 10;
                l2 = l2->next;
            }

            else if (l2 == NULL) {
                resHead->val = (l1->val + carry) % 10;
                carry = (l1->val + carry) / 10;
                l1 = l1->next;
            }

            else {
                resHead->val = (l1->val + l2->val + carry) % 10;
                carry = (l1->val + l2->val + carry) / 10;
                l1 = l1->next;
                l2 = l2->next;
            }
        }

        if (carry != 0) {
            resHead->next = new ListNode(carry);
        }

        return res;
    }
};
```
