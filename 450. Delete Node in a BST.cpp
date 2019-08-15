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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr = root, *prev = NULL;
        
        while (curr != NULL && curr->val != key)
        {
            prev = curr;
            if (curr->val > key)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if (curr == NULL)
            return root;
        
                
        if (curr->left == NULL && curr->right == NULL)
        {
            if (prev == NULL)
                return NULL;
            prev->left == curr? (prev->left = NULL):(prev->right = NULL);
        }
        else if (curr->left == NULL)
        {
            if (prev == NULL)
                return curr->right;
            prev->left == curr? (prev->left = curr->right): (prev->right = curr->right);
        }
        else if (curr->right == NULL)
        {
            if (prev == NULL)
                return curr->left;
            prev->left == curr? (prev->left = curr->left): (prev->right = curr->left);
        }
        else
        {   
            TreeNode* temp = curr->right;
            while (temp->left!=NULL)
                temp = temp->left;
            temp->left = curr->left;
        
            if (prev == NULL)
                return curr->right;
            prev->left == curr? (prev->left = curr->right): (prev->right = curr->right);
        }
        return root;
    }
};
