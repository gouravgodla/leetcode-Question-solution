class Solution {
public:
    bool isSubsequence(const string& target, const string& s) {
        int i = 0, j = 0;
        while (i < target.size() && j < s.size()) {
            if (target[i] == s[j]) i++;
            j++;
        }
        return i == target.size();
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        vector<char> candidates;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (freq[c] >= k) candidates.push_back(c);
        }

        string result = "";
        queue<string> q;
        q.push("");

        while (!q.empty()) {
            int size = q.size();
            vector<string> level;

            while (size--) {
                string cur = q.front(); q.pop();
                for (char c : candidates) {
                    string next = cur + c;
                    string repeated;
                    for (int i = 0; i < k; ++i) repeated += next;

                    if (isSubsequence(repeated, s)) {
                        level.push_back(next);
                        if (next.size() > result.size() ||
                            (next.size() == result.size() && next > result)) {
                            result = next;
                        }
                    }
                }
            }

            // Push valid next-level nodes into queue
            for (string& nxt : level) {
                q.push(nxt);
            }
        }

        return result;
    }
};
