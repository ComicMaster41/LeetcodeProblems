## Binary Tree Inorder Traversal — What I Learned

For this LeetCode problem, I implemented **inorder traversal** (`left → root → right`). I *could’ve* written it without a helper, but I chose to use one anyway to keep the logic clean and focused.

The main bug I ran into was **passing my result container by value instead of by reference**. That mistake made my output look like it was “working” inside the helper, but nothing actually stuck—so I kept getting an **empty array** even when the tree clearly had nodes.

Once I fixed the reference issue, everything clicked. This problem reinforced that **tree traversal is mostly about the order and the base case**, and it ended up being much simpler than I expected.
