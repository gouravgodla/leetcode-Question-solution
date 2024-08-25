// There is a strange printer with the following two special properties:

// The printer can only print a sequence of the same character each time.
// At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
// Given a string s, return the minimum number of turns the printer needed to print it.

 

// Example 1:

// Input: s = "aaabbb"
// Output: 2
// Explanation: Print "aaa" first and then print "bbb".
// Example 2:

// Input: s = "aba"
// Output: 2
// Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
 

// Constraints:

// 1 <= s.length <= 100
// s consists of lowercase English letters.



class Solution {
public:
    int strangePrinter(string s) {
        const int n = s.length();
        vector<vector<int>> mem(n, vector<int>(n));
        return strangePrinter(s, 0, n - 1, mem);
    }

private:
    // Returns the minimum number of turns to print s[i..j].
    int strangePrinter(const string& s, int i, int j,
                       vector<vector<int>>& mem) {
        if (i > j)
            return 0;
        if (mem[i][j] > 0)
            return mem[i][j];

        // Print s[i].
        mem[i][j] = strangePrinter(s, i + 1, j, mem) + 1;

        for (int k = i + 1; k <= j; ++k)
            if (s[k] == s[i])
                mem[i][j] =
                    min(mem[i][j], strangePrinter(s, i, k - 1, mem) +
                                       strangePrinter(s, k + 1, j, mem));

        return mem[i][j];
    }
};
