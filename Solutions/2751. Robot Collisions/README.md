
This problem was challenging because the main difficulty was **choosing the right structure and simulation order**.

At first, I tried to model the robots in a more direct way with a custom struct and treat the input arrays and direction string like one combined data structure. That made the implementation feel organized, but it also pulled me away from the actual core of the problem: **collision handling after sorting by position**.

The key insight is that robots must be processed in **position order**. After sorting them, a **stack** becomes the natural data structure because it lets us keep track of the robots that are still alive and may collide with the next incoming robot. When a collision happens, we compare health values, decrement the survivor when needed, and remove any robot that dies. This continues until there are no more valid collisions.

Another important observation is that collisions only occur when a robot moving right meets a robot moving left. That makes the simulation much more manageable, because not every pair of robots needs to be checked.

Finally, since the answer has to be returned in the **original input order**, it helps to keep track of each robot’s original index while processing.

Overall, this problem reinforced how important it is to recognize the right data structure early. The solution is much less about brute force and much more about **sorting, stack simulation, and careful state updates**.

**Summary:** sort by position, use a **stack** to simulate surviving robots, resolve only **right-left collisions**, and store original indices so the final result can be returned in the right order.
