## Learning Outcomes

This problem was more frustrating than I expected, mostly because I actually had the right instinct at the beginning, but I kept looking for a shortcut that would make the solution easier.

My first idea was to compute the product of all elements in the matrix and then divide by the current element to get the answer for each position. At first, this felt clever, but it turned out to be the wrong approach here. The main issue was that it did not safely handle division, and more importantly, it was not the intended strategy for solving the problem cleanly.

The correct direction was the one I had started with earlier: flatten the matrix into a 1D array, then use **prefix** and **suffix** products to represent the product of everything before and after a given index. That way, for each position, I could multiply the prefix and suffix values together to get the product of all elements except the current one.

The hardest part for me was not understanding the high-level idea, but understanding how to actually implement it. After working through the problem and asking follow-up questions, I got a much better grasp of how prefix and suffix arrays are built and why they work. In particular, I had to slow down and understand:

* why prefix starts from left to right
* why suffix starts from right to left
* why the base values are initialized to `1`
* how index shifting works in expressions like `prefix[i - 1]` and `suffix[i + 1]`

One thing I especially learned from this problem was that a solution can be technically correct and still be difficult to understand. Some generated versions of the solution felt overly “clean” in a way that made the logic harder to follow, especially when it came to index mapping and rebuilding the matrix. Because of that, I chose to write the final values back into the grid using a traditional nested `for` loop, which made the solution feel much clearer to me.

### What I learned most

* **Prefix and suffix products** are a powerful way to solve “product except self” problems without unsafe division.
* **Flattening a matrix** can make a 2D problem much easier to reason about.
* A solution is only useful if I can explain **why** it works, not just copy something that looks correct.
* It is important to question generated code and break it apart until the logic actually makes sense.

I finished this problem feeling much better than when I started. Even though it took time, I came away with a real understanding of the algorithm instead of just ending with a solution that “looked right.”

## Final takeaway

This problem reminded me that sometimes the hardest part is not finding the idea, but understanding how to express it clearly in code. In this case, the biggest win was turning a confusing-looking solution into one I could actually follow and explain.
