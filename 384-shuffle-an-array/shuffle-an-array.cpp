class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int> nums) : nums(nums) {}
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> ans(nums);
        for (int i = nums.size(); i > 1; --i) {
            int j = rand() % i;
            swap(ans[i - 1], ans[j]);
        }
        return ans;
    }
};