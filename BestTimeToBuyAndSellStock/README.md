## Problem Overview
To find the solution to the problem, I had to rethink my original approach. Initially, I attempted to solve the problem by taking the minimum and maximum values in the list and determining if the maximum value occurred before the minimum value. If true, I would remove the largest value and recalculate the biggest value.

The idea was to check if we could sell before buying. However, this approach was not optimal because it relied too heavily on frequent calls to the `min` and `max` functions. Below is the code from my original solution:

```python
for i in prices:
    sell_price = max(prices)
    buy_price = min(prices)

    max_index = prices.index(sell_price)
    min_index = prices.index(buy_price)

    if max_index < min_index:
        prices.remove(sell_price)
        print(prices)
    else:
        sell_price -= buy_price
        return sell_price
    if len(prices) == 1:
        return 0
```

This solution had several issues:
- Four variables were required to track the minimum and maximum values, as well as their indices.
- The frequent recalculations made the code inefficient.
- Nearly 70% of the test cases passed with this solution, but it was clear a better approach was needed.

## Optimized Solution
The improved solution builds the result iteratively instead of recalculating values repeatedly. By iterating through the list with a `min_price` and `max_profit`, I could achieve a more optimal solution. The critical line of code in this solution is:

```python
max_profit = max(max_profit, i - min_price)
```

This line eliminates the need for an `if/else` condition to check the maximum profit. Instead, it compares the current maximum profit with the difference between the current value and the smallest price in the list. 

### Key Insights:
- Avoid brute-forcing and modifying the original content.
- Build the solution dynamically by traversing the input data.

Here is the final implementation:

```python
def maxProfit(prices):
    min_price = float('inf')
    max_profit = 0

    for price in prices:
        min_price = min(min_price, price)
        max_profit = max(max_profit, price - min_price)

    return max_profit

# Example Usage
ans = maxProfit([2, 4, 1])
print(ans)
```

## Learning Outcome
This problem was a learning opportunity to rethink logic and optimize solutions. By focusing on building the solution, I was able to approach similar problems more effectively, including challenges like Kadane's algorithm.
