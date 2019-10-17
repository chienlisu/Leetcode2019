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
    int findNext(TreeNode* root)
    {
        root = root->right;
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root->val;
    }
    int findPrev(TreeNode* root)
    {
        root = root->left;
        while (root->right != NULL)
        {
            root = root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        
        // go search and delete left subtree
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        // go search and delete right subtree
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        // find the target, delete it and handle tree move
        else 
        {
            // leave
            if (root->left == NULL && root->right == NULL)
            {
                root = NULL;
            }
            // replace current node with the right child node, and go down right
            else if (root->right)
            {
                int val = findNext(root);
                root->val = val;
                root->right = deleteNode(root->right, root->val);
            }
            // replace current node with the left child node, and go down left
            else
            {
                int val = findPrev(root);
                root->val = val;
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }
};
