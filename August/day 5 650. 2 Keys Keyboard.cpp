// There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:

// Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
// Paste: You can paste the characters which are copied last time.
// Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

 

// Example 1:

// Input: n = 3
// Output: 3
// Explanation: Initially, we have one character 'A'.
// In step 1, we use Copy All operation.
// In step 2, we use Paste operation to get 'AA'.
// In step 3, we use Paste operation to get 'AAA'.
// Example 2:

// Input: n = 1
// Output: 0
 

// Constraints:

// 1 <= n <= 1000




class Solution {
public:
    // A memoization table to store results of subproblems
    vector<int> memo;

    // Main function to compute the minimum steps required to get 'n' 'A's on the notepad
    int minSteps(int n) {
        // Initialize the memoization table with '-1', to indicate that no subproblem is solved yet
        memo.assign(n + 1, -1);

        // Call the recursive depth-first-search function to compute the answer
        return dfs(n);
    }

    // Helper function to perform the depth-first search
    int dfs(int n) {
        // If only one 'A' is needed, 0 steps are required
        if (n == 1) return 0;

        // If the result has already been computed, return it instead of recomputing
        if (memo[n] != -1) return memo[n];

        // Initialize the answer with the maximum value, which is 'n' (copying 'A' one by one)
        int ans = n;

        // Try to find the minimal steps by finding divisors of 'n'
        for (int i = 2; i * i <= n; ++i) {
            // If 'i' is a divisor of 'n'
            if (n % i == 0) {
                // Recursively solve for the smaller problem 'n / i' and add 'i' steps
                // (the steps to paste 'A's 'i-1' times after copying once)
                ans = min(ans, dfs(n / i) + i);
            }
        }

        // Save the computed answer to the memoization table
        memo[n] = ans;

        // Return the minimum number of steps calculated
        return ans;
    }
};
