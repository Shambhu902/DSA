class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        int count = 0;

        unordered_map<int, int> mp;

        // Prefix sum 0 occurs once initially
        mp[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            // We need previous prefix sum = sum - goal
            if (mp.find(sum - goal) != mp.end()) {
                count += mp[sum - goal];
            }

            // Store current prefix sum
            mp[sum]++;
        }

        return count;
    }
}; 