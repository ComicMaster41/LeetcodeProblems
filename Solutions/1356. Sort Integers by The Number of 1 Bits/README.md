## LeetCode 1356 — Sort Integers by the Number of 1 Bits (Draft + Notes)

I didn’t get enough time to fully finish this during the attempt, but I was able to draft the solution outline (below). After having ChatGPT refine my original approach, I ran the refined version and confirmed the idea was correct.

### Core idea
- Convert each value to its binary representation (as a string).
- Count how many `'1'` characters it has (popcount).
- Sort by:
  1. **Fewer `1`s first**
  2. If tied, **smaller numeric value first**

> Note: In my comments I initially described tie-breaking by “the smaller number has fewer 1s,” which isn’t always true.  
> The actual rule is: **if the 1-bit counts are equal, sort by the numeric value.**

---

### My INCOMPLETE code (from the timed attempt)

```cpp
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

void sortByBits(vector<int>& arr) {
	// for loop to iterate over each number

	// Maybe after I get a solution I can figure out if I can do this
	// recursively

	// change all the numbers into binary representation
	for (int i = 0; i < arr.size(); ++i) {
		string iString = bitset<8>(i).to_string();
		for (int j = i + 1; j < arr.size(); ++j) {
			string jString = bitset<8>(j).to_string();
			int oneOcc = count(jString.begin(), jString.end(), '1');
			// now compare if the jString has > int count than iString
		        // if true, swap the value of arr[j] = arr[i], and make a temp var
		        
		        // if there's the chance their count is ==, then we need to for loop over each string\
		        // and flag occurrence, and the one with the flag set off first gets to go
		}
	}
	
	// then return
}

int main()
{
    vector<int> vec = {0,1,2,3,4,5,6,7,8};
	sortByBits(vec);
	
	for (auto& i : vec) {
	    cout << i << endl;
	}

	return 0;
}
