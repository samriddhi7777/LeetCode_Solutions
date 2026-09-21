class Solution {
public:
    bool fun(TreeNode* root, int sum, int target) {
        
        if (root == NULL)
            return false;

        sum += root->val;

        // If current node is a leaf
        if (root->left == NULL && root->right == NULL) {
            if (sum == target)
                return true;

            return false;
        }

        // Check left and right subtree
        return fun(root->left, sum, target) ||
               fun(root->right, sum, target);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return fun(root, 0, targetSum);
    }
};