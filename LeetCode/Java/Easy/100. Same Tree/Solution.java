class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {

        // Step 1: both are null
        if (p == null && q == null) {
            return true;
        }

        // Step 2: one is null, other is not
        if (p == null || q == null) {
            return false;
        }

        // Step 3: values are different
        if (p.val != q.val) {
            return false;
        }

        // Step 4: check left and right subtrees
        return isSameTree(p.left, q.left) 
                && isSameTree(p.right, q.right);
    }
}
