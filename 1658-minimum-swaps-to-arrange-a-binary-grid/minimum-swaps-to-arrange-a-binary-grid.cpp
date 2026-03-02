

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeroAtEnd(n, 0);
        for(int i=0;i<n;++i) {
            int cur_zero = 0;
            for(int j=n-1;j>=0;--j) {
                if(grid[i][j] != 0) break;
                ++cur_zero;
            }
            zeroAtEnd[i] = cur_zero;
        }
        
        int res = 0; 
        
        for(int i=0;i<n;++i) {
            if(zeroAtEnd[i] < (n-1-i)) { 
                int j = i+1;
                while(j<n && zeroAtEnd[j] < (n-1-i)) ++j; 
                if(j == n) return -1; 
                while(j > i) {
                    swap(zeroAtEnd[j], zeroAtEnd[j-1]);
                    --j;
                    ++res;
                }
            }
        }
        return res;
    }
};