
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

