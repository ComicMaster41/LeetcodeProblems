class Solution {
public:
    int minOperations(string s) {
        /*
        Right off the bat i notice that we can just count how many 0s and 1s are in a given list and see if they are even we just flip and return that number
        the third case says that if we have 1111 we can get 2 because we can just flip two of them. so the algoruthm would be to get the count of 0s and 1s and whichever is lesser, we flip.

        considering the first example, because we have 3 0s and 1 1 we can return 1 because we know that 1.count is < than 0.count. actually, just subtract, so if we have"
        0.count = 3
        1.count = 1
        4 - 3 = 1, which is our answer. I got this because 4 is the count of the string and 3 is whatever is greater, which is 0.count in this case.

        second case
        n = 2
        0.count = 1
        1.count = 1
        since they are equivalent, we return 0....

        third case
        n = 4
        0.count = 0
        1.count = 4
        because n == 1.count, we can divide that evenly

        so the structure would be

        if (n = greaterCount) return greaterCount / 2 
        else 

        im facing an issue with determining if they are equal. the idea is that if they are equal then we want to subtract that by the total amount, but if we get 1, for example, when we are supposed to get 0, then that is wrong. i think that the point is that im missing the point of what im finding. it says that no two adjacent characters are equal which is called adjacent... so i feel like that leaves a sort of clue. in the second problem, it says that s is alreayd alternating. ...h mmmmmm.... grrr.... is it already alternating because it has neighboring 1s and 0s. meaning, we havae nothing to alternate if they are the same. i wonder too if we can . if 

        if i habe 110010
        n = 6
        1.count = 3
        0.count = 3
        we want 2
        n / onect

        n = 2
        1.count = 1
        0.count = 1
        2/1=2, which is not right in this case

        i think i need to consider the problem differently, maybe for the test cases where they have the same. if we parse the int, we can find that it has 11 and 00 together, which is 2, then it has a 1 0, which is a 0. so if we add the two, we get 4/2 = 2

        i wonder if the problem then becomes how many groups do we find, and how many can we change to get alternating. so if we have a group of 11 and 00, then we can change 2 to get the alternating. so thats 2 + 2 

        so if we had our original, we had 1 group of 1 and 1 group of 0, which is 2 / 2 which is jsut 1... gree, thats not whats right

        maybe what if we check if its alreayd alternating. so if we consider 11 and 00, that becomes 4 for both, but then 10 is already alternating, so we throw that away

        so we can count the groups of alternating? 

        11 and 11 for ex. 3 has 2, which we return
        10 has no alternating, so we get 0
        0100, has 00 so thats just 1
        */

        int n = s.size();
        int oneCt = 0;
        int zeroCt = 0;
        for (int i = 0; i < n; ++i) {
            // if we don't have alternating, then we add
            char exp0 = (i % 2 == 0) ? '0' : '1';
            char exp1 = (i % 2 == 0) ? '1' : '0';

            if (exp0 != s[i]) oneCt++;
            if (exp1 != s[i]) zeroCt++;
        }

        return min(oneCt, zeroCt);
    }
};
