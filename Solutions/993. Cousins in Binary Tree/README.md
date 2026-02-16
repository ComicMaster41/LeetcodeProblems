## Cousins in Binary Tree — Approach & Takeaways

The goal of this problem is to determine whether two nodes `x` and `y` are **cousins**, meaning they share the **same depth** but have **different parents**.

### My idea

I treated the problem like a comparison task:

* Track info for `x` (**parentX**, **depthX**)
* Track info for `y` (**parentY**, **depthY**)
* Traverse the tree once, fill those trackers, then compare them.

If `depthX == depthY` and `parentX != parentY`, then they’re cousins.

### What was tricky

The hardest part wasn’t the comparison—it was the traversal itself:

* Handling parent/child relationships correctly
* Writing a helper traversal that actually fits a tree (not a linked list)
* Avoiding messy “manual” traversal logic

At first I tried to force a `while`-loop mindset (like walking a linked list), but that misses the point of a tree: **recursion naturally explores branches**.

### The helper traversal

The key improvement was making a recursive helper that passes:

* the **current node**
* the **parent node**
* the **current depth**

Whenever the helper hits `x` or `y`, it records:

* the node’s parent (`parentX` / `parentY`)
* the node’s depth (`depthX` / `depthY`)

Then the traversal continues (or can short-circuit once both are found).

### Final check

After running the helper from the root, the result is:

* `parentX != parentY`
* `depthX == depthY`
* and `depthX != -1`

That last condition felt weird at first, but it prevents an edge case where “not found” values (like `-1`) could accidentally compare as equal and return a wrong `true`.

---

**Summary:** I solved this by traversing the tree once, recording each target node’s parent and depth, then returning `true` only if the depths match, the parents differ, and both nodes were actually found.
