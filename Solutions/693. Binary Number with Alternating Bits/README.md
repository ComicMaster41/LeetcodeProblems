
## LeetCode 693 — Binary Number with Alternating Bits

This problem is straightforward, but it taught me a couple of useful details about working with bits. The goal is to take an integer, convert it to binary, and check whether the bits alternate (e.g., `101010...`) without any two adjacent bits being the same.

My approach:
- Convert the number into its bit representation.
- Store the bits as a string so I can compare adjacent characters.
- Remove leading zeros (since fixed-width conversions can add a bunch of them).
- Scan left to right and compare `s[i]` with `s[i+1]`. If they match, it’s not alternating.

One improvement I’d make: instead of toggling a boolean when a mismatch is found, I should return `false` immediately and return `true` at the end if no mismatches appear.

**Summary:** Convert `n` to binary, trim leading zeros, then check every adjacent pair—if any two neighbors match, it’s not alternating.
