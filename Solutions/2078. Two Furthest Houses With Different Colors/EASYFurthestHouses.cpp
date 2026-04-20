class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();

	    int maxSize = 0;
	    for (int i = 0; i < n; i++) {
		    for (int j = 0; j < n - 1; j++) {
			    if (colors[i] != colors[j]) {
			        int dst = abs(i - j);
				    maxSize = max(maxSize, dst);
			    }
		    }
	    }

	    return maxSize;
    }
};
