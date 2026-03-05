## Learning Outcomes (LeetCode 1758 — Minimum Changes To Make Alternating Binary String)

This problem was more frustrating than I expected because I initially thought I found a “trick,” but when I tried to implement it, I realized my approach was missing a key rule. That forced me to restructure the solution and rethink what the problem was actually asking.

### What I tried first (and why it failed)
My first idea was based on **counts**:
- Count the number of `'0'`s and `'1'`s
- Take whichever count is larger
- Use that to estimate how many flips are needed

That logic *sounds* reasonable, and it would work **if the goal were only to balance counts**.  
But this problem has an **adjacency / alternation requirement** — the final string must match one of these two patterns:

- `010101...`
- `101010...`

A string can have the “right” number of zeros and ones but still be arranged incorrectly, so a count-only method can’t guarantee the minimum flips.

### The correct approach
The right solution is **position-based**, not count-based:

1. Walk through the string from left to right.
2. Count mismatches against the pattern `0101...` (what each index *should* be).
3. Count mismatches against the pattern `1010...`.
4. Return the minimum of those two mismatch counts.

Example intuition:
- If we’re targeting `0101...`, then even indices should be `'0'` and odd indices should be `'1'`.
- Every time the actual character doesn’t match the expected one, that’s a flip we’d need.

### Biggest takeaway
Even if a “trick” feels right, it’s worth re-checking the **exact rules in the prompt**.  
In this case, the important detail wasn’t how many zeros/ones existed — it was whether each character matched the required alternating structure.
