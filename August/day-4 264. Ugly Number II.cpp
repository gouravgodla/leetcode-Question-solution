// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

// Given an integer n, return the nth ugly number.

 

// Example 1:

// Input: n = 10
// Output: 12
// Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
// Example 2:

// Input: n = 1
// Output: 1
// Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

// Constraints:

// 1 <= n <= 1690


class Solution {
 public:
  int nthUglyNumber(int n) {
    vector<int> uglyNums{1};
    int i2 = 0;
    int i3 = 0;
    int i5 = 0;

    while (uglyNums.size() < n) {
      const int next2 = uglyNums[i2] * 2;
      const int next3 = uglyNums[i3] * 3;
      const int next5 = uglyNums[i5] * 5;
      const int next = min({next2, next3, next5});
      if (next == next2)
        ++i2;
      if (next == next3)
        ++i3;
      if (next == next5)
        ++i5;
      uglyNums.push_back(next);
    }

    return uglyNums.back();
  }
};
