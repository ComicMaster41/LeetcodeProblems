class Solution {
public:
    bool checkOnesSegment(string s) {
        /*
        Pretty easy problem, im thinking we just iterate over the string and check if the next one is an s
        */

        int n = s.size();
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0' && s[i + 1] == '1')
                return false;
        }

        return true;
    }
};
