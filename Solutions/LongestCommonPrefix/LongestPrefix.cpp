class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // check if the string set is empty
        if (strs.empty()) return "";
        string prefix = strs[0];

        // look to the next few
        for (int i = 1; i < strs.size(); ++i) {
            string firstStr = strs[i];
            string next = "";
            int minStr = min(prefix.size(), firstStr.size());

            // get the min between our prefix and the current thing we're
            // looking at, because if it is a prefix then we can skip

            // once we have our min we can loop up to it
            for (int j = 0; j < minStr; ++j) {
                // compare the thing we're looking at with each other thing
                if (prefix[j] == firstStr[j]) {
                    next.push_back(prefix[j]);
                }

                else break;
            }

            // once we update next we want to set our new prefix
            prefix = next;
        }

        return prefix;
    }
};
