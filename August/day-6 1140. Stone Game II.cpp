// Alice and Bob continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones. 

// Alice and Bob take turns, with Alice starting first.  Initially, M = 1.

// On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).

// The game continues until all the stones have been taken.

// Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

 

// Example 1:

// Input: piles = [2,7,9,4,4]
// Output: 10
// Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 
// Example 2:

// Input: piles = [1,2,3,4,5,100]
// Output: 104
 

// Constraints:

// 1 <= piles.length <= 100
// 1 <= piles[i] <= 104





class Solution {
 public:
  int stoneGameII(vector<int>& piles) {
    const int n = piles.size();
    vector<vector<int>> mem(n, vector<int>(n));
    vector<int> suffix = piles;  // suffix[i] := sum(piles[i..n))
    for (int i = n - 2; i >= 0; --i)
      suffix[i] += suffix[i + 1];
    return stoneGameII(suffix, 0, 1, mem);
  }

 private:
  // Returns the maximum number of stones Alice can get from piles[i..n) with M.
  int stoneGameII(const vector<int>& suffix, int i, int M,
                  vector<vector<int>>& mem) {
    if (i + 2 * M >= mem.size())
      return suffix[i];
    if (mem[i][M] > 0)
      return mem[i][M];

    int opponent = suffix[i];

    for (int X = 1; X <= 2 * M; ++X)
      opponent = min(opponent, stoneGameII(suffix, i + X, max(M, X), mem));

    return mem[i][M] = suffix[i] - opponent;
  }
};
