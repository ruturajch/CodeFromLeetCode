class Solution
{
private:
    tuple<int, int, int> dfs(TreeNode *root)
    {
        
        tuple<int, int, int> left = {0, 0, 0};
        if (root->left != nullptr)
        {
            left = dfs(root->left);
        }
        tuple<int, int, int> right = {0, 0, 0};
        if (root->right != nullptr)
        {
            right = dfs(root->right);
        }
        tuple<int, int, int> ans = {get<0>(left) + get<0>(right),
                                    get<1>(left) + get<1>(right) + root->val,
                                    get<2>(left) + get<2>(right) + 1};
        if (root->val == ((get<1>(left) + get<1>(right) + root->val) / (get<2>(left) + get<2>(right) + 1)))
        {
            //cout << root->val << endl;
            get<0>(ans)++;
        }
        return ans;
    }

public:
    int averageOfSubtree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        else
            return get<0>(dfs(root));
    }
};