## LeetCode 110 — Balanced Binary Tree (What I Learned)

I expected this problem to be pretty straightforward, but it took me a while—mainly because it was my first real exposure to **binary trees**.

### What tripped me up

* **Recursion control:** In my helper function, I accidentally triggered recursion more times than needed by re-computing the left/right heights instead of reusing the values I already calculated.
* **Understanding `+1` in height:** It finally clicked that when you compute height as
  `1 + max(leftHeight, rightHeight)`, the `+1` exists to count the **current node** (not just its children).
  So height is basically: *“the tallest child path, plus me.”*

### Key takeaway

This problem taught me how to **traverse a tree recursively** using a helper function that computes:

* the height of the left subtree
* the height of the right subtree
* and whether the tree stays balanced while doing it

In other words: recursion isn’t just for “visiting nodes”—it’s for returning useful information **back up the call stack**.

---

### TL;DR

LeetCode 110 taught me how to recursively compute subtree heights using a helper function, avoid redundant recursion, and understand why height is `1 + max(left, right)` (to count the current node).
