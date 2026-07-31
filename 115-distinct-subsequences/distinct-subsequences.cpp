class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.length();
        int n = s.length();

        vector<unsigned long long> cur(m + 1, 0);
        cur[0] = 1;

        for (int j = 1; j <= n; j++) {
            unsigned long long pre = 1;

            for (int i = 1; i <= m; i++) {
                unsigned long long temp = cur[i];

                if (t[i - 1] == s[j - 1]) {
                    cur[i] += pre;
                }

                pre = temp;
            }
        }

        return cur[m];
    }
};