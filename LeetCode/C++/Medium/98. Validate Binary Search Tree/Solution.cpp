class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
        
    }
    bool dfs(TreeNode* node, long long minValue, long long maxValue){
        if(node == nullptr){
         return true;
        }
        if(node->val <= minValue || node->val >= maxValue){
            return false;
        }
        bool left = dfs(node->left, minValue, node->val);
        bool right = dfs(node->right, node->val, maxValue);
        
        return left && right;
    }
};