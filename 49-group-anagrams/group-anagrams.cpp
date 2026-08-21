class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& A) {
        unordered_map<string, vector<string>> m;
        for (auto &s : A) {
            auto key = s;
            sort(begin(key), end(key));
            m[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto &[key, strs] : m) ans.push_back(strs);
        return ans;
    }
};