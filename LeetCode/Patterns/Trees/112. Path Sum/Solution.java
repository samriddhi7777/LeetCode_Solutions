class Solution {
    public boolean hasPathSum(TreeNode root, int targetSum) {

        // Base case: empty tree
        if (root == null) {
            return false;
        }

        // If leaf node, check sum
        if (root.left == null && root.right == null) {
            return targetSum == root.val;
        }

        // Subtract current node value from targetSum
        int remainingSum = targetSum - root.val;

        // Check left or right subtree
        return hasPathSum(root.left, remainingSum) ||
               hasPathSum(root.right, remainingSum);
    }
}
