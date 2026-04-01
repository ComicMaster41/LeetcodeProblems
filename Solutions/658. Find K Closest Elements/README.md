
---

## LeetCode 658 — Find K Closest Elements

This problem was recommended as part of my Data Structures course. When I first read it, I recognized that it relied on techniques we had covered in class, so I used ideas from GeeksforGeeks to guide my thinking and later watched a NeetCode explanation to better understand the approach. Because of that, I would not present this solution as fully original, but I do understand the logic well and can explain it clearly.

### Core idea

The problem is solved by thinking in terms of a **window of size `k`**.
Since the answer must always be a **contiguous subarray** of length `k`, the goal is not to pick individual elements one by one, but instead to find the **best window position**.

We use a variable, often called `m`, to represent the **starting index** of the current window. From there, the window covers:

`arr[m]` through `arr[m + k - 1]`

The main question is:

**Should this window stay where it is, or should it move one step to the right?**

### How the decision works

To decide, we compare the two values at the edges of the competing windows:

* `arr[m]`
* `arr[m + k]`

This comparison tells us whether `x` is closer to the current left side or whether the better window starts further right.

If the left edge is worse than the element just outside the right edge, we shift the window right.

### Important detail

A subtle but important point is that we do **not** really “shift left” using `m - 1` in the search process.
Instead, we search over all valid starting positions for the window and decide whether the optimal answer lies:

* at `m`, or
* further to the right

So the algorithm is really about narrowing down the best **starting index** of the window, not manually sliding back and forth in both directions.

### Final result

Once the best starting index is found, the answer is simply the subarray of length `k` beginning there.

In other words, the task is:

1. Search for the best window position
2. Return that window as the result

### Intuition

You can think of it like placing a **frame of length `k`** over the array and asking:

**“Is the better frame here, or one step to the right?”**

By repeating that decision carefully, we eventually land on the window containing the `k` closest elements.

---
