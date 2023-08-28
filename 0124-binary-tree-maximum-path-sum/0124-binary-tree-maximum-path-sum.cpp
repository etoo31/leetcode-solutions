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
        maxi = max(maxi , curr->val);
        maxi = max(maxi , left + curr->val);
        maxi = max(maxi , right + curr->val);
        maxi = max(left+right+curr->val , maxi);
        return max(max(left,right)+ curr->val , curr->val);
    }
};