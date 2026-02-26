### LeetCode 98 — Validate Binary Search Tree (BST)

My final approach was heavily inspired by HeyCoach’s C++ solution (linked below). I initially tried a “hybrid” idea of my own, but it kept failing on edge cases, so I used the article to understand the clean, reliable pattern for this problem.

**Key idea:**
Use a helper function that validates each node while carrying **bounds**:

* Everything in the **left subtree** must be **strictly less** than the current node.
* Everything in the **right subtree** must be **strictly greater** than the current node.
  So as you recurse downward, you update the allowable `min` and `max` range for each node.

**Base case:**
If the current node is `null`, it’s valid by default (an empty subtree can’t break BST rules).

**Invalid conditions:**
A node breaks the BST if:

* A `min` bound exists and `node->val <= min`
* A `max` bound exists and `node->val >= max`

The HeyCoach solution also explicitly checks whether the bounds are `null` before comparing, which avoids bad comparisons and keeps the logic clean.

**Final step:**
Recursively validate both sides and combine results:

* `isValid(left subtree)` **AND** `isValid(right subtree)`

If both are true, the whole tree is a valid BST.

**Reference:**
HeyCoach solution I used: [https://heycoach.in/blog/validate-binary-search-tree-solution-in-cpp/](https://heycoach.in/blog/validate-binary-search-tree-solution-in-cpp/)
