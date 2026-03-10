class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || root == p || root == q) return root;
		bool foundP = found(root->left, p);
		bool foundQ = found(root->right, q);
		if (foundP && foundQ || !foundP && !foundQ) return root;
		if (foundP) return lowestCommonAncestor(root->left, p, q);
		return lowestCommonAncestor(root->right, p, q);
	}

	bool found(TreeNode* root, TreeNode* target) {
		if (!root) return false;
		if (root == target) return true;
		return found(root->left, target) || found(root->right, target);
	}
};