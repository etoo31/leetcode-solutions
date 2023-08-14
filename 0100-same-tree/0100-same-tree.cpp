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
    bool ans;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        ans = true;
        dfs(p , q);
        return ans;
    }
    void dfs(TreeNode * curr1 , TreeNode* curr2)
    {
        if (curr1 == nullptr && curr2 == nullptr){
            cout << "are you here" << endl;
            return;
        }
        else if (curr1 == nullptr && curr2)
        {
            cout << "crr1 is null" << endl;
            ans = false;
            return;
        }
        else if (curr2 == nullptr && curr1)
        {
            cout << "crr2 is null" << endl;
            ans = false;
            return;
        }
        else
        {
            if (curr1->val == 5)
            {
                if (curr1->right == nullptr)
                    cout << "i'm nullptr" << endl;
                if (curr2->right)
                    cout << "I'm not nullptr" << endl;
            }
            cout << curr1->val << " " << curr2->val << endl;
            if (curr1->val != curr2->val)
            {
                ans = false;
                return;
            }
            dfs(curr1->left , curr2->left);
            dfs(curr1->right , curr2->right);
        }
        
    }
};