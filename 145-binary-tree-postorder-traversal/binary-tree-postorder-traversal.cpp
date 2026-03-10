class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*>s;
        while(!s.empty() || root){
            if(root){
                s.push(root->left);
                res.push_back(root->val);
                root = root->right;
            }
            else{
                root = s.top();
                s.pop();
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};