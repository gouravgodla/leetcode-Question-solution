// You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.

// To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

// However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

// Return the maximum number of points you can achieve.

// abs(x) is defined as:

// x for x >= 0.
// -x for x < 0.



class Solution {
 public:
  long long maxPoints(vector<vector<int>>& points) {
    const int n = points[0].size();
    // dp[j] := the maximum number of points you can have if points[i][j] is the
    // most recent cell you picked
    vector<long> dp(n);

    for (const vector<int>& row : points) {
      vector<long> leftToRight(n);
      long runningMax = 0;

      for (int j = 0; j < n; ++j) {
        runningMax = max(runningMax - 1, dp[j]);
        leftToRight[j] = runningMax;
      }

      vector<long> rightToLeft(n);
      runningMax = 0;

      for (int j = n - 1; j >= 0; --j) {
        runningMax = max(runningMax - 1, dp[j]);
        rightToLeft[j] = runningMax;
      }

      for (int j = 0; j < n; ++j)
        dp[j] = max(leftToRight[j], rightToLeft[j]) + row[j];
    }

    return ranges::max(dp);
  }
};
