class Solution {
public:
    bool isPalindrome(int x) {
        // best so far is to compare left and right
        // break apart the int by running 
        int orgX = x;
        vector<int> orgVec;
        if (x == 0) {
            orgVec.push_back(x);
        }

        if (x < 0) return false;

        while (x > 0) {
            int temp = x % 10;
            orgVec.push_back(temp);
            x /= 10;
        }

        return std::ranges::equal(orgVec, std::views::reverse(orgVec));
    }
};
