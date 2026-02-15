Here’s a cleaned-up, GitHub-ready version you can copy/paste:

---

I wrote **two different solutions** for this problem because it felt approachable, and I wanted to see how many valid approaches I could come up with. This write-up focuses on my **second solution**.

My idea was a **brute-force prefix build**: compare characters **left-to-right** and stop as soon as there’s a mismatch. Since a *prefix* must be continuous from the start, any “gap” (a mismatch at some index) means the common prefix ends immediately.

To do this, I used two loops:

* An **outer loop** that compares the current prefix against each string in the array.
* An **inner loop** that compares characters up to `min(prefix.size(), current.size())` so we don’t waste time scanning past the shortest possible match.

While the runtime is **O(n · m)** (where `n` is the number of strings and `m` is the length of the prefix/string portion we compare), it felt worth it because the logic was easy to visualize and debug.

What I took away from this problem was getting more comfortable with **C++ string building**, especially using `push_back()` and constructing the prefix incrementally. I think this would’ve been simpler in Python, but doing it in C++ was a good challenge and helped me learn more about the language.

---
