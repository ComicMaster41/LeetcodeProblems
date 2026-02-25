class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        // for loop to iterate over each number (selection-sort style)
        for (int i = 0; i < (int)arr.size(); ++i) {

            // change the VALUE arr[i] into binary representation
            string iString = bitset<16>(arr[i]).to_string();
            int iOnes = count(iString.begin(), iString.end(), '1');

            for (int j = i + 1; j < (int)arr.size(); ++j) {

                // change the VALUE arr[j] into binary representation
                string jString = bitset<16>(arr[j]).to_string();
                int jOnes = count(jString.begin(), jString.end(), '1');

                // now compare if arr[j] has fewer 1s than arr[i]
                // if true, swap
                if (jOnes < iOnes) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;

                    // IMPORTANT: since arr[i] changed, update iString/iOnes
                    iString = bitset<16>(arr[i]).to_string();
                    iOnes = count(iString.begin(), iString.end(), '1');
                }
                // tie case: same number of 1s -> smaller value first
                else if (jOnes == iOnes && arr[j] < arr[i]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;

                    // update iOnes again (still same ones count, but keep consistent)
                    iString = bitset<16>(arr[i]).to_string();
                    iOnes = count(iString.begin(), iString.end(), '1');
                }
            }
        }

        return arr;
    }
};
