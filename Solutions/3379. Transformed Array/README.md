## Approach & Key Takeaway (LeetCode 3379)

This problem should’ve been much easier than I made it—my main struggle was **indexing backwards**, especially in a **circular array**.

The biggest lesson I took away is this:
**to move “backwards” in an array, you often write code that still moves “forwards” by wrapping around.**

### What tripped me up

The hardest part was handling **negative shifts** correctly.

* If `val > 0`, shifting is straightforward: move right and wrap using modulo.
* If `val < 0`, you still compute the target index with modulo, but you have to be careful because many languages (including C++) can produce a **negative result** for `(i + val) % n`.

For example, with a value like `-10`, we still want a valid index in `[0, n-1]`. The trick is **normalizing** the index by adding `n` *only when needed* (or using a normalization formula).

### The important insight

For a circular shift, the destination index should come from:

* `shift = (i + val) % n`
* If `shift` is negative, wrap it back into range:

  * `shift += n`

What broke my solution for a while was that I was adding `n` in the wrong way (or always adding it without checking), which caused incorrect indexing. Once I understood that **a negative index just means “wrap around from the end”**, the logic finally clicked.
