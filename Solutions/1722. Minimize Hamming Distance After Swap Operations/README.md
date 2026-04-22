# Minimum Hamming Distance After Swap Operations

## Why I Think This Should Be a LeetCode Hard

Even if you manage to spot the trick behind this problem, actually implementing the algorithm is no joke. You're expected to build a Union-Find structure from scratch *and* layer a counting algorithm on top of it — and that's what pushes this beyond a typical medium in my opinion.

## Recognizing the Trick

The key insight is hiding in one small detail of the problem: we're allowed to perform **as many swaps as we want** using the allowed swap pairs.

That unlimited-swaps rule is doing a ton of heavy lifting. It means that if index `A` can swap with `B`, and `B` can swap with `C`, then through a chain of swaps, `A`, `B`, and `C` can all freely shuffle their values among themselves. In other words, the allowed swaps form **connected components** — groups of indices that can all share values freely.

## Why "Root" Is Misleading

A lot of explanations describe Union-Find using the word "root," which implies a tree structure branching out from a single leader. I don't love that word for this problem, because we're not really building a tree — we're building a **graph**, where edges represent allowed swaps, and we care about which indices end up in the same connected component.

## The Two Halves of the Solution

### Half 1: Building the Union-Find

The first half of the work is the Union-Find infrastructure itself:

- A `findLeader` function that tells you which component an index belongs to
- A union step that merges two components together by pointing one leader at the other

This alone is roughly half the solution. It's the scaffolding that lets us group indices efficiently.

### Half 2: The Counting Logic

The second half — and the real core of the algorithm — is a frequency map with the structure:
