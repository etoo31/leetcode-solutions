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
    bool ans= true;
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode * curr)
    {
        if (curr == nullptr)return -1;
        
        int left = dfs(curr->left) + 1;
        int right = dfs(curr->right) +1;
        //cout << curr->val << endl;
        //cout << left << " " <<  right << endl;
        if (abs(left - right) > 1)
        {
            ans = false;
        }
        return max(left , right) ;
        
    }
};