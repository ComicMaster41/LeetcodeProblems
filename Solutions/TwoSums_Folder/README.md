This readme file contains my thought process for going about the TwoSums problem on leetcode.

At first, once I read the problem, I knew that I wanted to try to add the first and second element of a list and compare it with the target.
This is a pretty standard approach, so I spent some time doing this. I could investigate into cleaner solutions, but I knew that it was probably best
to look for better solutions once I got the first one to work.

I knew also that I wanted a for loop to iterate over our given list, and add that with the second element. Now, the biggest issue I faced was 
grabbing the proceeding element from the current index. What happens if there IS no other element? Well, that's when I knew my solution wasn't worth pursing.

I then experimented with the enumerate function, which returns the index and the value of each element in the list. This was perfect, because,
it would allow me to compare the two elements, then return their indecies as a list, which was required in the problem.

The only challenge was getting the NEXT element. So, I had to use another for loop. Sometimes, when you deal with nested for loops, that is a desperate
call for you to rethink your soltion that is more processing friendly. But, I just wanted something that worked.

So, I experiemented with nested for loops and the enumerate function. I got a few test cases working, but not all of them. The problem
was the way I handled the for loop. So, in a fit of frusteration, I thought to myself "well, let's play around with this idea and see if it works."

Essentially, what I did is the solution you see here. Without storing values in fancy variables or doing any sort of computations, I just add the first
and second element, compare it with the target, see if it works, and return if the condition is true. An important change is HOW the loops iterate.

The outer loop iterates until the last element, since I'm dealing with the NEXT value. the inner loop iterates from the NEXT element (second)
until it reaches the end. This is important, because I wanted the outer to grab the first element, iterate, then compare it with the next element until
it reached the end.

As you can see in the code, I have several function calls to experiment with the results of the test cases
