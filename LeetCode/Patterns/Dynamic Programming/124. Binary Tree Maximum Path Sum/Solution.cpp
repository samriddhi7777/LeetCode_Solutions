/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum = INT_MIN;
    int dfs(TreeNode* root){
        if(root == nullptr)
           return 0;
        int leftgain = max(0,dfs(root->left));
        int rightgain = max(0,dfs(root->right));

        int currentPath = leftgain + root->val + rightgain;
        maxSum = max(maxSum, currentPath);

        return root->val + max(leftgain,rightgain);

    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
        
    }
};