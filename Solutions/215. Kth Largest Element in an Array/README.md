Here’s a cleaned-up, GitHub-ready version (with clearer wording + correct “kth largest” detail):

---

## Kth Largest Element in an Array (LeetCode)

I worked on this problem after it was assigned in my Data Structures course. The task is simple to state:

> Given an array `nums`, return the **kth largest** element.

LeetCode allows a sorting-based solution, but encourages solving it **without sorting**. Since we covered this in class, I knew the intended approach was to use a **priority queue (heap)**.

### Key idea (no sorting)

Instead of sorting the entire array, we maintain a **min-heap of size `k`**:

* Push each number into the heap.
* If the heap grows larger than `k`, pop once (this removes the **smallest** element).
* By doing this, the heap always stores the **k largest elements seen so far**.
* At the end, the top of the min-heap is the **smallest among those k**, which is exactly the **kth largest element** overall.

### What I learned

* How to use a `priority_queue` in C++ with a custom comparator.

  * By default, `priority_queue` is a **max-heap**.
  * Using `greater<int>` flips it into a **min-heap**, which is what we need here.
* Why the “size > k → pop” rule works:

  * It constantly removes the *smallest* “candidate” so only the best `k` remain.

### Analogy

This feels a bit like a sliding window in the sense that we keep a limited “active set” of elements — but instead of keeping a contiguous window, we keep the **best k values**, regardless of where they appear in the array.

At the end, `heap.top()` returns the **kth largest** element.

---
