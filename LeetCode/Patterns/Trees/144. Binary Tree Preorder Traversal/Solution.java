class Solution {
    List<Integer> result = new ArrayList<>();

    public List<Integer> preorderTraversal(TreeNode root) {
        preorder(root);
        return result;
    }

    void preorder(TreeNode root) {
        if (root == null) {
            return;
        }

        result.add(root.val);     // Step 1: Root
        preorder(root.left);      // Step 2: Left
        preorder(root.right);     // Step 3: Right
    }
}
