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
    int n = 0;
    vector<vector<int>>ret;
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        getNLevels(root , 1);
        //cout << n << endl;
        ret = vector<vector<int>>(n);
        dfs(root , 0);
        return ret;
    }
    void dfs(TreeNode * curr , int i)
    {
        if (!curr)return;
        ret[i].push_back(curr->val);
        dfs(curr->left , i+1);
        dfs(curr->right, i+1);
    }
    void getNLevels(TreeNode * curr , int i)
    {
        if (!curr)return;
        n = max(n , i);
        getNLevels(curr->left , i+1);
        getNLevels(curr->right, i+1);
    }
};