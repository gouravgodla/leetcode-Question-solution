class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        string res = "";

        int i = 1;
        int start = 0;
        while (i < n) {
            while (i < n and word[i] == word[i - 1] and (i - start) < 10)
                i++;
            if ((i - start) == 10)
                i--;

            res.append(to_string(i - start));
            res.push_back(word[start]);

            start = i;
            i++;
        }
        if (start == n - 1) {
            res.append(to_string(i - start));
            res.push_back(word[start]);
        }
        return res;
    }
};
