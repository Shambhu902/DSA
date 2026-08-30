class Solution {
public:
    string intToRoman(int num) {

        map<int, string, greater<int>> m;

        m.insert({1000, "M"});
        m.insert({900, "CM"});
        m.insert({500, "D"});
        m.insert({400, "CD"});
        m.insert({100, "C"});
        m.insert({90, "XC"});
        m.insert({50, "L"});
        m.insert({40, "XL"});
        m.insert({10, "X"});
        m.insert({9, "IX"});
        m.insert({5, "V"});
        m.insert({4, "IV"});
        m.insert({1, "I"});

        string ans = "";

        for(auto x : m) {

            while(num >= x.first) {
                ans += x.second;
                num -= x.first;
            }
        }

        return ans;
    }
};