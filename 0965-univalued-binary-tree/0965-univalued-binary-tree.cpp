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
    void inorder(TreeNode* root, int k, int &flag)
    {
        if(root == NULL)
        {
            return;
        }

        inorder(root->left, k, flag);
        if(root->val != k) flag++;
        inorder(root->right, k ,flag);
    }
    bool isUnivalTree(TreeNode* root) {
        int k = root->val;
        int f = 0;
        inorder(root, k , f);

        return f == 0;
        
    }
};