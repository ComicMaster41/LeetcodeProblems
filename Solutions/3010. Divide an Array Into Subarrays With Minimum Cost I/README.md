## LeetCode 3010 — Minimum Cost (Quick Win)

This one felt *way* more straightforward than most problems, mainly because the goal is to return **a single minimum total cost**, not a whole list of candidate costs.

After looking closely at the examples, the key observation is:

* **`nums[0]` is always included** in the cost.
* So the only thing left is to pick the **two smallest values** from the remaining elements (`nums[1:]`).

### My Approach

1. Treat `nums[0]` as a fixed starting cost.
2. Sort the rest of the array (everything after index 0).
3. Add the first two values from that sorted slice to `nums[0]`.

That’s it—sorting makes it trivial to grab the smallest two values, and the final sum is the minimum cost.

### Key Takeaways

* Spotting what’s **fixed** (`nums[0]`) turns the problem into a simple “pick the two smallest” task.
* Sorting a subarray can be a clean solution when the input size is small and clarity matters.

**In one sentence:** Include `nums[0]`, take the two smallest values from the remaining elements, and sum them for the minimum cost.
