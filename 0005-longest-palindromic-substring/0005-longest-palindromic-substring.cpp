class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 1;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < s.length() &&
                   s[left] == s[right]) {
                left--;
                right++;
            }

            int len = right - left - 1;

            if (len > maxLen) {
                maxLen = len;
                start = left + 1;
            }
        };

        for (int i = 0; i < s.length(); i++) {
            // Odd length
            expand(i, i);

            // Even length
            expand(i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};