class Solution {
public:
    int countZeroes(vector<int> vec) {
        int zeroes = 0;
        // ISSUE: I PUT > INSTEAED OF >=, meaning it won't get to 0, so it'll skip a row
        for (int i = vec.size() - 1; i >= 0; --i) {
            if (vec[i] == 0) zeroes++;
            else break; // ISSUE: FORGOT TO WRITE THIS LINE AND IT RETURNS 0, VERY IMPORTANT BECAUSE WE DON'T WANT TO COUNT AFTER 0 RANGE
        }

        return zeroes;
    }

    int minSwaps(vector<vector<int>>& grid) {
        /*
        What i think right off the bat is what if we implemented an algorithm to compute how many steps it would take to convert the given matrix into upper triangular form and return it. so i see from the first example, if we consider each row, the first row, for example, has a 1 so we can save that and swap with another row where there is a 1. so in the second row, because wait i just realized i thought of this a little too complicated. we just want to swap rows to build the upper triangular. so we know that the firsrt row should have _ 0 0, the second should have a _ _ 0, so we can iterate over all the rows and check what fits this form. we can also traverse backwards from each row instead of forward to save time. 

        now i need to ask if this is the trick. considering the first example, we traverse backwards on the first row. because we see there is a 1 at the end, we stop. then we consider the second row, because theres a 0 at the end, we know that that is good so we can keep it. now finally the third row, because that ends with two 0s, we want to swap that at the end. so that swap could produce 2 stepos, which is 1 less than what the problem is asking, which makes me think that that is not what it is asking.

        so if they are asking for it to be swapped in adjacent slots, that changes the problem a bit. what if we made it a bit arbitrary and said we just want 3 0s along the upper right corner. given example 1, we know that we hafve a 1 but there is no adjacent to swap with, so we consider the second row. beause there is a 0, that is good so we can swap the two, since there isnt something to swap with. then we consider the next element in the row 1. because we did the swap we have a 1, and the diagonal is also a 1, which both need to be 0. so we consiuder the 3rd row, and because it matches the shape we swap it.

        so what weve learned is that the only operation we can deal with is swapping rows, and we consider if a row needs to be swappeed because we loop backwards from eaech row. now the questions i have is first, how do we set the conditions for the form, and how do we swap the rows around? i wonder if doing it recursively would be a good idea because we could just have a base case where the upper triangular is 0 or if it is null. but the problem doesnt sound like it wants to be recursive.

        lets highlight the problems
        1) how to set the conditions to get the upper triangular
        2) how to write each of the rows
        3) how to count the min operations we can run

        loop 
            if i = 1
                if j = 0
                    swap the two rows
        this seems kind of basic and not what is being asked. but the principle is correct. if we see that i is 1 and j = j + 1 is a 0, we can break and swap rows. this is why i consider recursion, because after we swap, we break and return the matrix and traverse again. but this algorithm would work best if we do a single pass instead of swapping and going back. i also notice something interesting. in the first example, because we swap 1 and 2, then we swap 2 and 3, then we go back and swap 1 and 2, which could tell me that after we consider the two rows, we increase i by 1 and j by 1, considering the next 2 rows until we reach the final row in the matrix. 

        consider the backwards algorithm. our row needs n - 1 - i
        you can calculate the diagnal from the row and see if it is upper triangular or not. literalally calculating the diagnal and checking if they are 1s or 0s and if not then we can swap the row with the next

        so does that formula make sense? 
        lets say n = 3
        i = 3 (were going backwards)
        3 - 1 - 3 = -1, so -1 would be the index? that would be invalid
        if i could calculate the diagnonal, it would be i + 1 
        so 0 + 1 
        then 1 + 1 then 2 + 1 and so on


        These comments come back after looking at the complete solution. So the story is that we want to swap rows only if the leading zeroes starting from the right doesn't match the upper triangular. We find this by considering the right to left of each row and checking if this is true. We have a helper function to count how many zeroes occur in each row, and once we get our count, we compare to see if we swap all rows, return -1, or else we swwap and icnrement count.

        note that im referring to upper triangular as the corner of zeroes in the matrix

        */
        int n = grid.size();
        int minCt = 0;

        for (int i = 0; i < n; ++i) {
            int count = i; // how many zeroes we have
            int diag = n - 1 - i;

            // while count is less than grid size && the number of zeroes is less than what we'd expect from the upper triangular
            while (count < n && countZeroes(grid[count]) < diag) {
                count++;
            }

            if (count == n) { // if the count of zeroes is an entire row
                return -1;
            }

            // while the count is greater than the row, so like swap row 2 with 1 or row 3 with 1 whaatever
            while (count > i) {
                swap(grid[count], grid[count - 1]);
                minCt++;
                count--;
            }
                
        }
        return minCt;
    }
};
