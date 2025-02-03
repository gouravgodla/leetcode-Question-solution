class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int longestSubarray = 1;

        //  increasing subarrays
        for (int i = 1, currentLength = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                longestSubarray = max(longestSubarray, ++currentLength);
            } else {
                currentLength = 1;
            }
        }
        // decreasing subarrays
        for (int i = 1, currentLength = 1; i < nums.size(); ++i) {
            if (nums[i - 1] > nums[i]) {
                longestSubarray = max(longestSubarray, ++currentLength);
            } else {
                currentLength = 1;
            }
        }
        return longestSubarray;
    }
};
