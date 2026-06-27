class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long long ans=0;
        int original=x;
        while(x!=0){
            int digit=x%10;
            ans=ans*10+digit;
            x=x/10;
        }
        if(original==ans){
            return true;
        }
        else{
            return false;
        }
        
    }
};