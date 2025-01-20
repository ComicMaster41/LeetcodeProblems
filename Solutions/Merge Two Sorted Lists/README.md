Here’s the formatted version of your README, ready to copy and paste into GitHub:

```markdown
# Merge Two Sorted Lists (LeetCode Problem 21)

## Overview

After a month-long break from school, I wanted to solve a coding problem that was "easy" yet practical to shake off the rust. LeetCode Problem 21, **Merge Two Sorted Lists**, turned out to be the perfect choice. This problem requires merging two sorted lists into a single sorted linked list.

The challenge lies in using a **singly-linked list** to sort the elements. If we were working with arrays, this problem would have been straightforward—simply concatenating and sorting the two lists would suffice. However, leveraging the linked list structure made it more interesting and a great way to get back into problem-solving mode.

## Problem Description

You are given two sorted singly-linked lists and tasked with merging them into one sorted linked list. The merged list should retain its sorted order.

LeetCode provides the definition for the `ListNode` class to work with:

```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
```

The solution involves recursively traversing the linked lists and constructing the merged result.

## My Approach

I wanted this problem to warm up my coding skills, so I decided to focus on an **elegant recursive solution** rather than a naive iterative approach. While I initially struggled, I found a helpful article on GeeksforGeeks that explained the recursive method.

The process involves:
1. **Base Case**: Check if either list is `None`. If so, return the other list.
2. **Recursive Case**: Compare the values of the current nodes in `list1` and `list2`. Attach the smaller node to the result and recursively call the function for the remaining elements.

Here’s the key logic:
- If `list1.val <= list2.val`, set `list1.next` to the result of the recursive call, passing `list1.next` and `list2`.
- Otherwise, set `list2.next` similarly.

### Key Insights

- A mistake I encountered was forgetting to use `self` in the recursive call. Since the function is part of the `Solution` class, failing to call it as `self.mergeTwoLists` resulted in a `NameError`. 
- This subtle issue reminded me of the importance of understanding Python’s scoping rules, especially when working within classes.

## Code Implementation

Here’s the Python solution I used:

```python
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 is None:
            return list2
        if list2 is None:
            return list1
        
        if list1.val <= list2.val:
            list1.next = self.mergeTwoLists(list1.next, list2)
            return list1
        else:
            list2.next = self.mergeTwoLists(list1, list2.next)
            return list2
```

## Reflections

- **Why Recursion?** I found recursion to be both elegant and more in line with what I’m currently learning in school. It allowed me to break down the problem into manageable chunks.
- **Lesson Learned**: Always pay attention to the context in which a function is defined—especially within a class. This was a valuable debugging experience.

## Conclusion

This problem served as an excellent reintroduction to coding challenges. While the solution wasn’t entirely original, it helped me rebuild confidence and get back into problem-solving mode. I look forward to tackling more complex challenges in the future!
```
