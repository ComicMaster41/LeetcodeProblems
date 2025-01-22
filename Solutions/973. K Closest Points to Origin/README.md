# LeetCode 973: K Closest Points to Origin

## Problem Description
Given an array of points, where each point is represented as `[x, y]`, the task is to determine the `k` closest points to the origin `(0, 0)`.

The Euclidean distance from a point `(x, y)` to the origin is calculated as:

```
distance = sqrt(x^2 + y^2)
```

However, since only relative distances matter for this problem, we can use the squared distance formula:

```
distance_squared = x^2 + y^2
```

## Approach
### Initial Attempt
My first attempt involved a nested loop to calculate the distances for all points. The distances were then stored in a dictionary mapping each distance to its corresponding point. While this approach worked conceptually, it was not efficient and seemed over-engineered for an "easy" problem.

### Optimized Python Solution
A simpler and more efficient approach leverages Python's `sort` function with a lambda to compute the squared distance inline. This method eliminates the need for additional data structures and keeps the implementation concise.

Here is the step-by-step process:

1. Use the `sort` method to sort the input list of points based on their squared distances to the origin.
2. Use a lambda function as the key for sorting, calculating the squared distance as `x^2 + y^2`.
3. Return the first `k` points from the sorted list.

### Code Implementation
```python
from typing import List

def k_closest(points: List[List[int]], k: int) -> List[List[int]]:
    # Sort the points based on their squared distance to the origin
    points.sort(key=lambda point: point[0]**2 + point[1]**2)
    # Return the first k points
    return points[:k]
```

### Example
#### Input:
```python
points = [[3, 3], [5, -1], [-2, 4]]
k = 2
```

#### Output:
```python
[[3, 3], [-2, 4]]
```

#### Explanation:
1. Squared distances:
   - `(3, 3)`: `3^2 + 3^2 = 18`
   - `(5, -1)`: `5^2 + (-1)^2 = 26`
   - `(-2, 4)`: `(-2)^2 + 4^2 = 20`
2. After sorting: `[[3, 3], [-2, 4], [5, -1]]`
3. Return the first `k=2` points: `[[3, 3], [-2, 4]]`

## Reflections
This approach highlights the elegance of Python's built-in functionality, especially for straightforward problems. For future iterations, I aim to solve this type of problem independently without referencing external solutions, further strengthening my problem-solving skills.

## Next Steps
- Explore more efficient approaches for large datasets, such as using a min-heap to maintain the top `k` closest points during iteration.
- Practice writing the solution in other languages like Java or C to deepen understanding of data structures like heaps and priority queues.

## Key Takeaways
- Leveraging Python's `sort` function and lambdas can simplify complex tasks.
- Understanding the problem requirements is crucial for selecting the right algorithm.
- Iterative problem-solving and reflection help refine skills over time.

