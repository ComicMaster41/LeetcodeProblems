## Notes / Thought Process (My Approach)

I started this problem with a quick “brain dump” of what the prompt was *really* asking. The key thing I noticed early was that the condition depends on **zeros at the end of each row**, so it makes sense to scan each row **from right to left**.

From there, I realized the only operation we’re allowed is swapping rows, so the whole problem becomes:

- figure out **which rows are “good enough”** for each position  
- then **swap** rows upward until the correct kind of row reaches that position  
- while counting how many swaps we used

### What I didn’t catch at first (the trick)
At first I was “counting zeros” in a vague way, but the important detail is:

- For row `i`, we don’t just want “some zeros”
- We need **a specific number of trailing zeros**
- That required amount is:

`required = n - 1 - i`

So as `i` increases, the number of trailing zeros needed decreases.

### What I added to make it work
To apply that trick cleanly, I needed a helper function that counts **trailing zeros** in a row (not just total zeros). Once I could compute trailing zeros for any row:

1. For each row position `i`, compute `required = n - 1 - i`
2. Search downward to find the first row with `trailingZeros >= required`
3. If found, swap it upward step-by-step until it reaches row `i`
4. Add the number of swaps to the answer
5. If no row meets the requirement, return `-1`

### What I learned
This problem is less about brute force and more about spotting the pattern:  
**the formula tells you exactly how many trailing zeros each row must have.**  
Once I used that (plus a trailing-zero helper), counting the minimum swaps became straightforward.
