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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr)
            return true;
        stack<TreeNode *>st;
        bool ans = false;
        if (root)
            st.push(root);
        while (!st.empty())
        {
            auto curr = st.top();
            st.pop();
            if (curr->val == subRoot->val)
            {
                ans = dfs(curr , subRoot) | ans;
            }
            if (curr->left)
                st.push(curr->left);
            if (curr->right)
                st.push(curr->right);
                
        }
        return ans;
    
    }
    bool dfs(TreeNode * t1 , TreeNode * t2)
    {
        if (t1 == nullptr && t2 == nullptr)
            return true;
        else if ((t1 == nullptr && t2) || (t1 && t2 == nullptr))
            return false;
        else if (t1->val != t2->val)
            return false;
        return dfs(t1->left , t2->left) & dfs(t1->right , t2->right);
        
    }
};