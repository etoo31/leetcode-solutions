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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size() || !inorder.size())
            return nullptr;
        TreeNode * root = new TreeNode(preorder[0]);
        int index = -1;
        for (int i = 0 ; i < inorder.size(); i++)
            if (inorder[i] == preorder[0])
            {
                index = i;
                break;
            }
        if (index == -1)return nullptr;
        vector<int> p1(preorder.begin()+1, preorder.begin()+index+1);
        
        vector<int> p2(preorder.begin()+index+1, preorder.end());
        
        vector<int>order1(inorder.begin() , inorder.begin()+index);
        vector<int>order2(inorder.begin()+index+1 , inorder.end());
        //for (int i = 0; i  < p1.size(); i++)
          //  cout << p1[i] << " ";
        //return nullptr;
        root->left = buildTree(p1 , order1);
        root->right = buildTree(p2 , order2);
        return root;
    }
};