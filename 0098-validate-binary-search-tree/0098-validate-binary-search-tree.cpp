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
        return dfs(root , (long long)INT_MIN- 5 , (long long)INT_MAX + 5);
    }
    bool dfs(TreeNode * node , long long mini , long long maxi)
    {
        if (node == nullptr)return true;
        long long val = node->val;
        //cout << val << " " << maxi << endl;
        if (val >= maxi || val <= mini)return false;
        
        bool left = dfs(node->left ,mini , val);
        bool right = dfs(node->right , val , maxi);
        return (left && right);
    }
    
};