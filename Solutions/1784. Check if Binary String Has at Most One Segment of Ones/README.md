
## Notes

This problem looked much more annoying than it actually was. I was close to the right idea, but I got distracted by edge cases and missed the simple trick hiding in front of me.

The key observation is that if the string contains `"01"`, then the segment of `1`s has already ended. Since the problem asks whether all `1`s appear in one continuous segment, seeing a `"01"` means the block has been broken, so the answer should be `false`.

What helped me was looking more carefully at the test cases:

* patterns that return `false` involve a break in the `1`s
* patterns that return `true` keep all the `1`s together before moving into `0`s

So instead of overthinking all the possible cases, the real task was just recognizing that simple pattern.

I ended up thinking about two different implementations:

1. **Two-pointer / two-while-loop approach**
   First, move through the initial segment of `1`s. After that, check the rest of the string and make sure no other `1` appears.

2. **Pattern check approach**
   Directly check whether `"01"` appears in the string. This is the much shorter solution and captures the trick immediately.

The second approach reminded me a bit of accepting and non-accepting states in a deterministic finite automaton: once you transition out of the `1` segment into `0`, seeing another `1` would mean the string is no longer valid.

## Takeaway

I learned that sometimes the hardest part of an “easy” problem is not the implementation, but noticing the small pattern the problem is built around.
