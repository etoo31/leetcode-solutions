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
    bool isValidBST(TreeNode* root) {
        return dfs(root , LONG_LONG_MIN , LONG_LONG_MAX);
    }
    bool dfs(TreeNode *curr , long long mini , long long maxi)
    {
        if (!curr)return true;
        if (!((long long)curr->val > mini && (long long)curr->val < maxi))
            return false;
        bool left = dfs(curr->left , mini , curr->val);
        bool right = dfs(curr->right , curr->val , maxi);
        return left & right;
    }
};