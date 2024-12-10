def maxProfit(prices):
    max_profit = 0
    min_price = prices[0]

    for i in prices:
        if i < min_price:
            min_price = i
        max_profit = max(max_profit, i - min_price)
    return max_profit


ans = maxProfit([2, 4, 1])
print(ans)
