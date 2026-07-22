class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        queue<int> q;

        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;

            if (m[s[i]] == 1) {
                q.push(i);
            }

            while (!q.empty() && m[s[q.front()]] > 1) {
                q.pop();
            }
        }

        return q.empty() ? -1 : q.front();
    }
};