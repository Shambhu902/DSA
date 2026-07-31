class Solution {
public:
    int minimumPushes(string word) {
        int freq[26] = {0};
        for(int i = 0; i < word.size(); i++) {
            freq[word[i] - 'a']++;
        }
        sort(freq, freq + 26, greater<int>());
        int count = 0;
        for(int i = 0; i < 26; i++) {
            count += freq[i] * (i / 8 + 1);
        }
        return count;
    }
};