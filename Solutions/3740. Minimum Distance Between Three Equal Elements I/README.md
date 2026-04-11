
**LeetCode 3740 — Reflection**

**Difficulty feel:** Easy | **Time:** ~15 min

The problem statement was fairly prescriptive — the implementation details were largely spelled out. Two sticking points:

1. **Nested loop indexing** — Deciding whether three nested loops were actually necessary, and tracking indices correctly across them. This is a recurring weak point I want to sharpen.

2. **Comparison logic bug** — I initialized `bestDist` to a large sentinel value, but had the comparison condition backwards when evaluating candidates. Flipping it gave the correct result.

