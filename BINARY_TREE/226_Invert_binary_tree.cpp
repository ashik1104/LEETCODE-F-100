class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    if(root == NULL)
    {
        return root;
    }

    // tree_node * temp = root->left_child;
    // root->left_child = root->right_child;
    // root->right_child = temp;

    swap(root->left, root->right);

    invertTree(root->left);
    invertTree(root->right);

    return root;
    }
};