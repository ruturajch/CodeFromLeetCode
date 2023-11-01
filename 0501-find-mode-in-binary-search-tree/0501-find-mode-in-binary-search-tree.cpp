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
private:
    static bool check(pair<int, int> & a,pair<int, int> & b){
        return a.second > b.second;
    }
public:
    vector<int> findMode(TreeNode* root) {
        if(root == NULL)return {};
        unordered_map<int, int> helperMap;
        TreeNode* cur = root;
        queue<TreeNode*> helperQueue;
        helperQueue.push(root);

        while(!helperQueue.empty()){
            auto cur = helperQueue.front();
            helperQueue.pop();
            helperMap[cur->val]++;
            if(cur-> left != NULL){
                helperQueue.push(cur-> left);
            }
            if(cur-> right != NULL){
                helperQueue.push(cur->right);
            }
        }
        vector<pair<int, int>> helperVector;
        for(auto i : helperMap){
            helperVector.push_back({i.first, i.second});
        }
        sort(helperVector.begin(), helperVector.end(), check);

        vector<int> ansVector;
        ansVector.push_back(helperVector[0].first);
        int curr = helperVector[0].second;
        for(int i = 1; i < helperVector.size(); i++){
            if(curr == helperVector[i].second){
                ansVector.push_back(helperVector[i].first);
            }else{
                break;
            }
        }

        return ansVector;
    }
};