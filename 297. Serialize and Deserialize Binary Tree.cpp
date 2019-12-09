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
        if (root == NULL)
            return "null,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* helper2(vector<string>& nodes, int& idx)
    {
        if (nodes.size() < idx) // special case
            return NULL;
        
        string curr = nodes[idx];
        ++idx;
        if (curr == "null")
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(curr));
        root->left = helper2(nodes, idx);
        root->right = helper2(nodes, idx);
        return root;
    }
    TreeNode* deserialize(string data) {
        string temp = "";
        vector<string> nodes;
        for (auto i:data)
        {
            if (i == ',')
            {
                nodes.push_back(temp);
                temp = "";
            }
            else
            {
                temp += i;
            }
        }
        
        int idx = 0;
        return helper2(nodes, idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
