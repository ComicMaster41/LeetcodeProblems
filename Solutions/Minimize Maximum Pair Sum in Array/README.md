### LeetCode 1877 — Minimize Maximum Pair Sum in Array

In this problem, you pair up the array into **2-element pairs**, then look at each pair’s **sum**. Your goal is to arrange the pairs so that the **largest pair sum** is as small as possible.

This was one of my first problems after being out of practice, and I definitely overcomplicated it at first. The key mindset shift I learned: you don’t need to literally build every pair and then search for the maximum afterward. A cleaner way to think about it is:

* **Sort the array** from smallest to largest
* **Pair the smallest with the largest**, the second smallest with the second largest, and so on
* Track the **maximum** of these pair sums as you go

#### What I learned

* Many “pairing” problems become simpler after **sorting**.
* You can often avoid extra work by focusing on what actually matters (here: the **worst** pair sum).
* Edge cases become more obvious once the approach is structured (especially around **large values** dominating the maximum).

In short: I spent two days fighting the problem, then solved it by realizing the solution is mostly about **reframing** and doing less unnecessary work.
