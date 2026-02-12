## Reflection

I’m not entirely proud of this solution, but I chose to prioritize solving it **my way** rather than chasing the “best” approach right away.

### My idea
- Store the digits/values in a `vector`
- Reverse the `vector`
- Compare the original and reversed versions to determine if they match

### What I learned
Even when the core logic is simple, implementation details can introduce unnecessary work. In my case, storing *every* element (and then processing the whole structure) made the solution feel heavier than it needed to be.

### What I’d improve next time
- Add clearer edge-case handling (early returns) so I can answer **true/false** without always running the full loop
- Reduce extra storage when possible

### Takeaway
Getting a correct solution matters first — then you can iterate and optimize. A working approach is still progress, and it naturally leaves room to improve later.
