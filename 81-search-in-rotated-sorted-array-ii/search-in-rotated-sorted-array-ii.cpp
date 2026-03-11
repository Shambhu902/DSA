class Solution {
public:
    bool search(vector<int>& A, int target) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return true;
            if (A[M] == A[R]) --R;
            else if (A[M] < A[R]) {
                if (A[M] < target && target <= A[R]) L = M + 1;
                else R = M - 1;
            } else {
                if (A[L] <= target && target < A[M]) R = M - 1;
                else L = M + 1;
            }
        }
        return false;
    }
};