class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string s = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        while(i >= 0 || j >= 0 || carry){
            int num1 = i < 0 ? 0 : a[i] - '0';
            int num2 = j < 0 ? 0 : b[j] - '0';
            int sum = num1 + num2 + carry;
            s.push_back(sum % 2 + '0');
            carry = sum / 2;
            i--;
            j--;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};