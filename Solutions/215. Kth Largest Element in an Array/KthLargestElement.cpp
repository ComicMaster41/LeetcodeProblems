class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
        I was kind of already given a hint for this problem, which was to use sorted queing, which is why im doing this problem. i need to do some research on sorted queing, but i think that would be the algorithm of this problem. i think that it is also the trick, since we need an algorithm that will represent iterating over the given array without sworting. 

        so i think the idea is that yoy can do this with sorting from decending order you iteratew backwards and return the kth element in the sorted array. but the trick is asking if you can do this without sorting, so if you had a priority queue, you can say that the kth element is the priority

        so if i implemented the priority queue, id need to figure out what i need, and since this program gives us the kth priority element, or kth largest, we inow that we need to program in such a way that will give priority to each of the values. an idea is using a hash map where we will will map each element in the array with how large they are. we can even go so far to add how many of them exsist, or just keep them seperatew. this idea sounds a but like 

        i think i shioulod start by doing this with backwards sorting first, so we just sort in decending order, traverse up until k, and return what that element is. if i get p[assing ] test cases thejn i will figure out an algorithm to get it without sorting

        ok so the algorithm below worked with sorting, so how can i change it without sorting. the idea that comes to mind is making the kth value our priority, iterating over the queue, and returning that item. so what i need to implement is that priority.

        ok i think i got a good idae. so if we have a min-heap, we can pop k many elements onto this min heap, and if it exceeds the size of k, we remove the smallest value. this is a good way of collecting the k max amount of items in a list. so like with the first test case where it was 2, we collect the 2 elements, and when we want to add a third, we remove the smaller of the two, until we end up with the 2 largest elements and we just grab the largest of the kth elements in that heap.
        */

        // CODE BELOW WORKS FOR SORTING
        // int n = nums.size();
        // sort(nums.begin(), nums.end(), std::greater<int>());

        // return nums[k - 1];

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int x : nums) {
            minHeap.push(x);

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top(); // the greatest value is at the top
    }
};
