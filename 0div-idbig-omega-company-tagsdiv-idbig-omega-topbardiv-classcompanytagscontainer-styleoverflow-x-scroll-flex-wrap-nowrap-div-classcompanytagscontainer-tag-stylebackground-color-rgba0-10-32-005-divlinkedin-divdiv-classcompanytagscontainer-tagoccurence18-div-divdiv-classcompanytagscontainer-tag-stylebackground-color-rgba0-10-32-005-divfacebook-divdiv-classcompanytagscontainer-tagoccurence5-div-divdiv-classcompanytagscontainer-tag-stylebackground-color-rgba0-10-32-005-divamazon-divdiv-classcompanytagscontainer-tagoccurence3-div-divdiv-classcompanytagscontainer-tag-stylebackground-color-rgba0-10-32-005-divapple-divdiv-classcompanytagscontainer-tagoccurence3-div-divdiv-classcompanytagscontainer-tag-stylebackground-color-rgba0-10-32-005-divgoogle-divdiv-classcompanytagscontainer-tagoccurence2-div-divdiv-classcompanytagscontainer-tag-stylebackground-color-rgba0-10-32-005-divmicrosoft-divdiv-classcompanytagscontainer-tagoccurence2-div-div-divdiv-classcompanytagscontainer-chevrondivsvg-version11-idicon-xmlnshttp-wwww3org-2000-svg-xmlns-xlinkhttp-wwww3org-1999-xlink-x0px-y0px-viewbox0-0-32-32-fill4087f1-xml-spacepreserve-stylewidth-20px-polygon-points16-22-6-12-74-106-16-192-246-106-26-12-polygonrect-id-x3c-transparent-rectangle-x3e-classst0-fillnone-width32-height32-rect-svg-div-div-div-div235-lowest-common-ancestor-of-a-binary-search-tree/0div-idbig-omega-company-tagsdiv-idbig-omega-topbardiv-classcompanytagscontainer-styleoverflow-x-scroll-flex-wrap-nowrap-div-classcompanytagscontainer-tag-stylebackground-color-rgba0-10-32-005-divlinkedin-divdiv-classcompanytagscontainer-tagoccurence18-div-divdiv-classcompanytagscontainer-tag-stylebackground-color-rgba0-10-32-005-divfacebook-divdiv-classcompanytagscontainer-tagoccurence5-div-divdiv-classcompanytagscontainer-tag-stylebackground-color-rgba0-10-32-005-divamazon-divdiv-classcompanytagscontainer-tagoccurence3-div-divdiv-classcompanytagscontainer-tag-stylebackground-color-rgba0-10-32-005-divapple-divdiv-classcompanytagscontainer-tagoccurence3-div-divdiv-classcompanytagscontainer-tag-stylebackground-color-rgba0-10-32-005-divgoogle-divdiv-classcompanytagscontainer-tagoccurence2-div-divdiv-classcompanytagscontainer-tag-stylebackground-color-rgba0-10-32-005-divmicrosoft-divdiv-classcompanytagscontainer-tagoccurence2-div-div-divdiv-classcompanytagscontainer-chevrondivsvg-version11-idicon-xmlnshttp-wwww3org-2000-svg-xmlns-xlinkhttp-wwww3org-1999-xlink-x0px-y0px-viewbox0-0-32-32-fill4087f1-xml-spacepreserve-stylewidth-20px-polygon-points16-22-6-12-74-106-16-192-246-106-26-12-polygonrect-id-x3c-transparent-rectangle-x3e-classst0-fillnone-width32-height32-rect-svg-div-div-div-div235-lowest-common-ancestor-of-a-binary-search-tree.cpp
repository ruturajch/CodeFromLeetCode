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
    bool check(TreeNode* root, TreeNode* p){
        if(root == NULL)return false;

        if(root->val == p->val)return true;
        if(check(root->left, p)) return true;
        if(check(root->right, p)) return true;

        return false;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        if (root == NULL)
            return NULL;
        if ((check(root->left, p) || root->val == p->val) && (check(root->right, q) || root->val == q->val))
            return root;
        if ((check(root->left, q) || root->val == q->val) && (check(root->right, p) || root->val == p->val))
            return root;
        TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);

        return leftAns == NULL ? rightAns : leftAns;
    }
};