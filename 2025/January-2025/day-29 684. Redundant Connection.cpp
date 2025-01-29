class Solution {
    int find(vector<int>& dsuf, int v) {
        if (dsuf[v] == -1)
            return v;
        return dsuf[v] = find(dsuf, dsuf[v]); // path compression
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> dsuf(n + 1, -1);
        for (auto edge : edges) {
            int parent_x = find(dsuf, edge[0]);
            int parent_y = find(dsuf, edge[1]);

            if (parent_x == parent_y) // redundant edge
                return edge;
            else // take union
                dsuf[parent_x] = parent_y;
        }
        return {0, 0};
    }
};
