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
    int maxi = -1e9;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxi;
    }
    int dfs(TreeNode * curr)
    {
        if (!curr)return 0;
        
        int left = dfs(curr->left);
        int right = dfs(curr->right);
        left = max(left , 0);
        right = max(right , 0);
        maxi = max(left+right+curr->val , maxi);
        return max(left,right)+ curr->val;
    }
};