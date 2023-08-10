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
    int maxDepth(TreeNode* root) {
        
        stack<pair<TreeNode * , int>>st;
        int ans = 0;
        if (root)
            st.push({root , 1});
        while (!st.empty())
        {
            TreeNode * node = st.top().first;
            int c = st.top().second;
            st.pop();
            ans = max(ans , c);
            
            if (node->left)
            {
                st.push({node->left , c+1});
            }
            if (node->right)
            {
                st.push({node->right , c+1});
            }
        }
        return ans;
    }
};