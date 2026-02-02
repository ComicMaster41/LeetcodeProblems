class Solution {
public:
    int reverse(int x) {
        int xTemp = x;
        int digit = 0;
        long long mv = 0;

        int len = 0;

        while (xTemp != 0) {
            xTemp = xTemp / 10;
            len++;
        }

        // mv * 10 shifts everything to the left by base-10
        for (int i = 0; i < len; ++i) {
            digit = x % 10; // 3

            mv = mv * 10 + digit;

            if (mv < INT_MIN || mv > INT_MAX) {
		        return 0; //move this down, if on the final mv change it exceeds 32-bit limit, it is never checked
		    }

            x /= 10;
        }

        return mv;
    }
};
