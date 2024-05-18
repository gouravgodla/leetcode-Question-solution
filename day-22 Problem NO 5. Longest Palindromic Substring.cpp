class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 1;
        int start = 0;
        
        // Iterate through the string
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            
            // Expand around the center
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
            
            l = i, r = i + 1;
            
            // Expand around the center for even length palindromes
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
        }
        
        return s.substr(start, maxLen);
    }
};
