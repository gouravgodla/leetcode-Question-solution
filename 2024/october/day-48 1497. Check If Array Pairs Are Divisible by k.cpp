class Solution {
public:
    bool canArrange(std::vector<int>& arr, int k) {
        std::unordered_map<int, int> remainderCount;

        // Count the frequency of each remainder
        for (int num : arr) {
            int remainder = num % k;
            if (remainder < 0) {
                remainder += k;  // Handle negative remainders
            }
            remainderCount[remainder]++;
        }

        // Check the pairing conditions
        if (remainderCount[0] % 2 != 0) {
            return false;  // Remainders of 0 must be even
        }

        for (int r = 1; r <= k / 2; ++r) {
            if (r == k - r) {  // Special case where remainders are exactly half of k
                if (remainderCount[r] % 2 != 0) {
                    return false;
                }
            } else {
                if (remainderCount[r] != remainderCount[k - r]) {
                    return false;
                }
            }
        }

        return true;
    }
};
