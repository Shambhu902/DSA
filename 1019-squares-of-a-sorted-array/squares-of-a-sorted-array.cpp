class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());

        int start = 0;
        int end = nums.size() - 1;
        int ptr = nums.size() - 1;

        while (start <= end) {
            int ss = nums[start] * nums[start];
            int es = nums[end] * nums[end];

            if (ss > es) {
                ans[ptr] = ss;
                start++;
            }
            else {
                ans[ptr] = es;
                end--;
            }

            ptr--;
        }

        return ans;
    }
};