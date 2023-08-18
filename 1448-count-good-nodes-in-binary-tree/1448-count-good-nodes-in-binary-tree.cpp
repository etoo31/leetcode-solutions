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
    int goodNodes(TreeNode* root) {
        if (root)
            return dfs(root , root->val);
        return 0;
    }
    int dfs(TreeNode * curr , int maxi)
    {
        if (!curr)return 0;
        int good = 0;
        if (curr->val >= maxi){
            good = 1;
            maxi = curr->val;
        }
        int left = dfs(curr->left , maxi);
        int right = dfs(curr->right , maxi);
        return left+right+good;
    }
};