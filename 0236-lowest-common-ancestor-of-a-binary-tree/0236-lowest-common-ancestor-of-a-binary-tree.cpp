/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode * ans;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<int, int>mp;
        findNode(root , p->val , mp);
        findNode(root , q->val , mp);
        dfs(root , mp);
        if (ans != nullptr)
        cout << "answer : " << ans->val << endl;
        return ans;
        
    }
    void dfs(TreeNode *node ,map<int ,int>&mp)
    {
        if (node == nullptr)return;
        if (mp[node->val] == 2)ans = node;
        dfs(node->left , mp);
        dfs(node->right , mp);
    }
    bool findNode(TreeNode * node , int val , map<int ,int>&mp)
    {
        if (node == nullptr)return false;
    
        if (node->val == val)
        {
            mp[node->val]++;
            return true;
        }
        
        bool left = findNode(node->left , val , mp);
        if (left){
         mp[node->val]++;
         return true;   
        }
        bool right = findNode(node->right , val , mp);
        if (right){
         mp[node->val]++;
         return true;   
        }
        return false;
        
    }
};