
## Approach

This solution optimizes the brute force approach for LeetCode 3740 by leveraging a hashmap and a sliding window over indices.

### Key Insight: Index Mapping

Instead of iterating over all triplets, we first build a hashmap that maps each element to a list of indices where it appears. This lets us focus only on indices that share the same value, since `i`, `j`, and `k` must all refer to the same element.

### Simplifying the Cost Formula

The problem asks us to minimize `|i - j| + |j - k| + |k - i|`. Since our indices are stored in sorted order, we know `i < j < k`, which means we can drop the absolute values. Expanding the expression, the middle terms cancel out and we're left with just `2 * (k - i)`. This means the optimal triple is always the one where the outermost indices are as close together as possible.

### Sliding Window over Indices

To find the closest triple, we apply a sliding window of size 3 over each element's index list. This is a subtle but important insight — the problem asks for a 3-element tuple, but by sliding a window we efficiently consider all consecutive triples and return the one with the minimum cost.

### Complexity
- **Time:** O(n)
- **Space:** O(n)
