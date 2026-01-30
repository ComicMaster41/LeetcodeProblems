### 🧠 What I Learned (Dijkstra + Adjacency List)

This was easily one of the toughest problems I’ve worked on so far.

The biggest takeaway was learning how to **implement Dijkstra’s algorithm** *properly*—and realizing that the real work starts **before** the algorithm even runs. The input came in as a matrix/edge-style structure, but Dijkstra works best with an **adjacency list**, so I had to convert the input into a **directed adjacency list** first.

That adjacency list step was *crucial*, because once I had it, Dijkstra could do its job without me “reinventing the wheel.”

#### Key steps in my approach

* **Build a directed adjacency list** from the input

  * Each entry stores what I needed for the search (neighbor + weight/cost).
* **Run Dijkstra** to compute shortest distances efficiently.
* **Return the best cost** found for the target node:

  * `dist[n - 1]`

#### Edge case / correctness detail

One thing that tripped me up at first was **handling invalid/out-of-range results**. I added a final check:

* If `dist[n - 1]` is outside the valid integer range → return `-1`
* Otherwise → return `dist[n - 1]`

That small safeguard made the difference between “almost working” and “consistently correct output.”

---

**Summary:** I converted the input into a directed adjacency list, ran Dijkstra to compute the best path cost, returned `dist[n-1]`, and added a final range/validity check to return `-1` when the result isn’t valid.
