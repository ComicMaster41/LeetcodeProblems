# TwoSums Problem on LeetCode

This README documents my approach to solving the TwoSums problem on LeetCode.

## Thought Process

1. **Initial Idea**:
   - Start by adding the first and second elements of the list.
   - Compare the sum with the target value.
   - This straightforward approach was my first step to get a working solution before refining it.

2. **Challenges**:
   - Iterating through the list and accessing the next element.
   - Handling cases where there is no next element.

3. **Improvement with `enumerate`**:
   - The `enumerate` function returns both the index and value of elements in the list.
   - It allowed me to compare two elements and return their indices as required by the problem.

4. **Nested Loops**:
   - Used a nested for loop:
     - The outer loop iterates through the list up to the second-to-last element.
     - The inner loop starts from the next element and continues to the end of the list.
   - This ensures that every element is compared with the ones that follow it.

5. **Final Solution**:
   - Add the first and second elements.
   - Compare the sum to the target.
   - If it matches, return the indices of the two elements.

## Lessons Learned

- Sometimes a simple, working solution is better than an overly complex one.
- Nested loops can be a starting point but may not be the most efficient approach.

## Code Highlights

The solution uses:
- `enumerate` to simplify index-value pairing.
- Efficient iteration through the list with nested loops to solve the problem.

This approach, while not the most optimal, provided a clear pathway to arrive at a correct solution.
