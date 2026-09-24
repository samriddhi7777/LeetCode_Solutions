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
    int dfs(TreeNode* root, int currentNumber){
        if(root == nullptr)
          return 0;
        currentNumber = currentNumber * 10 + root->val;
        if(root->left == nullptr && root->right == nullptr){
            return currentNumber;
        }
        return dfs(root->left,currentNumber ) + 
               dfs(root->right, currentNumber);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
        
        
        
    }
};