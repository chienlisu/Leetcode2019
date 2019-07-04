/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        node = root;
    }
    
    /** @return the next smallest number */
    int next() {
        //if (node || !inorder.empty())
        {
            while (node)
            {
                inorder.push(node);
                node = node->left;
            }
            TreeNode* curr = inorder.top();
            inorder.pop();
            node = curr->right;
            
            return curr->val;
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (node || !inorder.empty());
    }
private:
    stack<TreeNode*> inorder;
    TreeNode* node;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
