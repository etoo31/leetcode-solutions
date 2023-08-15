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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (p->val > q->val)
        {
            TreeNode * temp = p;
            p = q;
            q = temp;
        }
        stack<TreeNode *>st;
        st.push(root);
        //cout << p->val << " " << q->val << endl;
        while (!st.empty())
        {
            auto curr = st.top();
            //cout << "curr : " <<curr->val << endl;
            st.pop();
            if (!curr)continue;
            if (curr->val > q->val)
            {
                //cout << curr->val << " " << q->val << endl;
                st.push(curr->left);
            }
            else if (curr->val < p->val)
            {
                st.push(curr->right);
            }
            else if (curr->val >= p->val && curr->val <= q->val)
            {
                return curr;
            }
        }
        return nullptr;
    }
};