#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool checkStrings(std::string s1, std::string s2) {
        std::vector<char> odd1, even1, odd2, even2;
        
        for (int i = 0; i < s1.length(); ++i) {
            if (i % 2 == 0) {
                even1.push_back(s1[i]);
                even2.push_back(s2[i]);
            } else {
                odd1.push_back(s1[i]);
                odd2.push_back(s2[i]);
            }
        }
        
        std::sort(even1.begin(), even1.end());
        std::sort(even2.begin(), even2.end());
        std::sort(odd1.begin(), odd1.end());
        std::sort(odd2.begin(), odd2.end());
        
        return (even1 == even2 && odd1 == odd2);
    }
};
