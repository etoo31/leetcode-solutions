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
    
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        dfs(root , ans);
        return ans;
    }
    
    int dfs(TreeNode * node , bool &ans){
        if (node == nullptr) return -1;
        int left = dfs(node->left , ans) + 1;
        int right = dfs(node->right , ans)+1;
        if (abs(left-right) > 1)
        {
            ans = false;
        }
        return max(left , right);
    }
};