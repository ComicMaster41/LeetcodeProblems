## LeetCode 1689 — Partitioning Into Minimum Number Of Deci-Binary Numbers

I’m **not cleaning up this code** because I want to preserve my problem-solving process (as shown in the comments).

### Key realization
A “deci-binary” number can only use digits **0** and **1**.

So if the target number has a digit like **8**, then across all the deci-binary numbers you add together, you need **at least 8 ones stacked** in that position to reach 8.

That means:
> **The minimum number of deci-binary numbers needed = the maximum digit in the string.**

Examples:
- `32` → max digit is `3` → answer `3`
- `82734` → max digit is `8` → answer `8`

---

### My (intentionally messy) solution

```cpp
class Solution {
public:
    int minPartitions(string n) {
        // the problem becomes whats the min way to add 1 and 0 to make the output
        // ex. 82734
        // 11111
        /*
        Return the min number of positive deci binary numbers needed so they sum up to n. What comes to mind is min, so we have to think conservative.
        Im thinking that we could find some way to track how many 1s and 0s you need to get the decimal number. but the thing throwing me off is that one test case gives 8 and the other gives 9, so there's clearly some sort of stupid trick that im not seeing. i notice at the beginning its deci binary if the digits are either 0 or 1 without any leading zeros. i wonder if this is something to consider. any leading 0s could mean that if you converted a given string to its binary representation, if it has leading 0s, does that mean its eliminated. i thought that if you convert it to binary then you can count 1s? but that wouldn't work, it would have to be simplier than that.

        lets consider the explanation for the first test case. its 10 11 11 which is 32. i see that if you splice the numbers, starting from the right, you see 2 which is 2 1s, and the far left is   a 3, which is 3 1s. so you can put those together into a 10s operation

        the second test case is 82734 so its 11111 11111 10111 10101 10100 10100 10100 10000

        this work really helped me because ow i see the trick. let me cooooook
        */

        char mx = ' ';
        for (char& c : n) {
            if (c > mx)
                mx = c;
        }

        return mx - '0';
    }
};
