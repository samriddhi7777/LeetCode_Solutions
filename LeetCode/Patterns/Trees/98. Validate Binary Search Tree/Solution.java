class Solution {
    public boolean isValidBST(TreeNode root) {
        return validate(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }

    private boolean validate(TreeNode node, long min, long max) {
        if (node == null) return true;

        // Current node must lie strictly between min and max
        if (node.val <= min || node.val >= max) {
            return false;
        }

        // Check left and right subtrees with updated bounds
        return validate(node.left, min, node.val) &&
               validate(node.right, node.val, max);
    }
}