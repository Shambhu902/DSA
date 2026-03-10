class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool res = true;
        dfs(root, res);
        return res;
    }
    
    int dfs(TreeNode* root, bool& res){
        if(!root) return 0;
        int l = dfs(root->left, res);
        int r = dfs(root->right, res);
        if(abs(l - r) > 1) res = false;
        return max(l, r) + 1;
    }
};