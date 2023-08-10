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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode *>st;
        if (root)
            st.push(root);
        while (!st.empty())
        {
            TreeNode * curr = st.top();
            st.pop();
            TreeNode * temp = curr->left;
            temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;
            if (curr->left)
                st.push(curr->left);
            if (curr->right)
                st.push(curr->right);
        }
        return root;
    }
};