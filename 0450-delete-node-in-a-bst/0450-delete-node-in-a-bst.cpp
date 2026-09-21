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
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == NULL)
            return NULL;

        TreeNode* parent = NULL;
        TreeNode* current = root;

        while (current != NULL && current->val != key) {
            parent = current;

            if (key < current->val)
                current = current->left;
            else
                current = current->right;
        }

        if (current == NULL)
            return root;

        if (current->left != NULL && current->right != NULL) {

            TreeNode* successorParent = current;
            TreeNode* successor = current->right;

            while (successor->left != NULL) {
                successorParent = successor;
                successor = successor->left;
            }

            current->val = successor->val;

            parent = successorParent;
            current = successor;
        }

        TreeNode* child;

        if (current->left != NULL)
            child = current->left;
        else
            child = current->right;

        if (parent == NULL) {
            delete current;
            return child;
        }
        if (parent->left == current)
            parent->left = child;
        else
            parent->right = child;

        delete current;

        return root;
    }
};