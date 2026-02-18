class Solution {
public:
    bool hasAlternatingBits(int n) {
        string str = bitset<32>(n).to_string(); // convert bits to string
	    str.erase(0, str.find_first_not_of('0'));
        bool dec = true;

        for (size_t i = 0; i < str.size(); ++i) {
            if (str[i] == str[i + 1]) { // then they're different
                dec = false;
            }
        }

        return dec;
    }
};
