class Solution {
    #define l1 long long
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if (n < 2)
            return 0;

        l1 top_sum = accumulate(grid[0].begin(),grid[0].end(), 0LL);
        l1 bottom_sum = 0;
        /*robo-2 can only either to or bottom. since, it too want to maximize
         * it's sum value, so take max(top_sum,bottom_sum);*/

        l1 min_sum = LONG_MAX;
        for (int pp = 0; pp < n; ++pp) {
            top_sum -= grid[0][pp];
            min_sum = min(min_sum, max(top_sum, bottom_sum));
            bottom_sum += grid[1][pp];
        }
        return min_sum;
    }
};
