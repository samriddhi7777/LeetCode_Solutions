class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
        
    }
    int dfs(TreeNode* node, int maxSoFar){
        if(node == nullptr){
            return 0;
        }
        int count = 0;
        if(node->val >= maxSoFar){
            count = 1;

        }
        int newMax = max(maxSoFar, node->val);

        count += dfs(node->left, newMax);
        count += dfs(node->right, newMax);

        return count;
    }
};