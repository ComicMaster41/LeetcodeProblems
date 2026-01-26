### LeetCode — Minimum Absolute Difference

This problem felt really similar to other “pair” questions I’ve done: once the array is **sorted**, the information you care about (differences between values) becomes much easier to reason about.

The main challenge for me wasn’t the math — it was the *implementation details*:

* figuring out how to build a **list of pairs** (a list of 2-element lists),
* and tracking the **smallest difference** without constantly re-checking the entire array.

The approach that finally clicked for me was simple and reliable:

* **Sort the array**
* Do one pass to compute the **minimum absolute difference** between adjacent elements
* Do a second pass to collect every adjacent pair whose difference matches that minimum

#### What I learned

* Sorting turns a “global search” problem into a local one: the smallest difference will always be between **neighbors** in the sorted list.
* It can be easier (and clearer) to separate the solution into two clean passes:
  one to *measure*, one to *collect*.
* Even if it’s not the most optimized version, getting a correct solution first is huge — optimization can come later.

This one pushed me to rethink how I store results and structure loops, which is exactly the kind of struggle that actually builds problem-solving skill.
