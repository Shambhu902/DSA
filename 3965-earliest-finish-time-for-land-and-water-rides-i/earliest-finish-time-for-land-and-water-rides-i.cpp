class Solution {
public:
    int earliestFinishTime(vector<int>& stl, vector<int>& dl, 
                             vector<int>& stw, vector<int>& dw) {
        int minlandend = INT_MAX;
        int n = stl.size();
        for (int i = 0; i < n; ++i) {
            minlandend = min(minlandend, stl[i] + dl[i]);
        }

        int minwaterend = INT_MAX;
        int ans = INT_MAX;
        int m = stw.size();
        for (int i = 0; i < m; ++i) {
            minwaterend = min(minwaterend, stw[i] + dw[i]);
            ans = min(ans, max(minlandend, stw[i]) + dw[i]);
        }

        for (int i = 0; i < n; ++i) {
            ans = min(ans, max(minwaterend, stl[i]) + dl[i]);
        }
        return ans;
    }
};