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
    unordered_map<int,int> inMap;
    int postIndex = 0;
    TreeNode* build(vector<int> &postorder, int inStart, int inEnd){
        if(inStart > inEnd)
           return nullptr;
        
        int rootValue = postorder[postIndex--];

        TreeNode* root = new TreeNode(rootValue);

        int rootIndex = inMap[rootValue];
        root->right = build(postorder, rootIndex+ 1, inEnd);
        root->left = build(postorder, inStart, rootIndex - 1);
         
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }
        postIndex = postorder.size() - 1;
        return build(postorder, 0, inorder.size() - 1); 
        
    }
};