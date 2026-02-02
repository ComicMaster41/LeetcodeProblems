## LeetCode 7 — Reverse Integer (What I Learned)

This problem was a solid refresher on **when to use the modulo operator (`%`)** and **when to use multiplication (`* 10`)** while working with base-10 integers.

My first approach was to **figure out how many digits** the number had (tens place, hundreds place, etc.). I used a `while` loop to count digits, then used that count to decide how many times my main loop should run.

Inside the loop, the core idea is:

* **Extract the last digit** with `x % 10`
* **Shift the result left in base-10** by doing `result * 10`
* **Add the extracted digit** into the new number
* **Remove the last digit** from the input with integer division (`x / 10`)
* **Guard against overflow**: if the result goes outside the 32-bit signed integer range, return `0`

### Key Takeaways

* `% 10` is the cleanest way to grab the last digit of an integer.
* `* 10` is how you “make room” for the next digit in the reversed number.
* Overflow checks aren’t optional—reversing can easily exceed `int` limits.
* This problem is basically **base-10 digit manipulation**, step-by-step.

**In one sentence:** I got more comfortable extracting digits, shifting in base-10, and building a result safely without overflowing.
