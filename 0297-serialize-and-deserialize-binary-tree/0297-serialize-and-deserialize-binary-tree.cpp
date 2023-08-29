/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string ret = getPreOrder(root);
        return ret;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string s = "";
        vector<string>v;
        for (int i = 0 ; i < data.size(); i++)
        {
            if (data[i] == ','){
                if (s != "")
                    v.push_back(s);
                s = "";
                continue;
            }
            s += data[i];
        }
        int i = 0;
        return getTree(v , i);
    }
    string getPreOrder(TreeNode * curr)
    {
        if (!curr)return "N,";
        string ret = to_string(curr->val) + ",";
        ret += getPreOrder(curr->left);
        ret += getPreOrder(curr->right);
        return ret;
    }
    TreeNode * getTree(vector<string>&v , int &i)
    {
        if (v[i] == "N")
        {
            i++;
            return nullptr;
        }
        TreeNode * curr = new TreeNode(stoi(v[i]));
        i++;
        curr->left = getTree(v , i);
        curr->right = getTree(v , i);
        return curr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));