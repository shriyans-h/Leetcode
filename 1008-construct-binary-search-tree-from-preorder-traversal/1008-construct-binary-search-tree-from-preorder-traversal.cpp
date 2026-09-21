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

    TreeNode* build(vector<int>& preorder, int& i, long long low, long long high) {

        if (i == preorder.size())
            return NULL;

        if (preorder[i] <= low || preorder[i] >= high)
            return NULL;

        TreeNode* root = new TreeNode(preorder[i]);
        i++;

        root->left = build(preorder, i, low, root->val);
        root->right = build(preorder, i, root->val, high);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int i = 0;

        return build(preorder, i, LLONG_MIN, LLONG_MAX);
    }
};