class TreeNod
{
public:
    TreeNod *children[26];
    bool isWordComplete;
    TreeNod()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isWordComplete = false;
    }
};
class Solution
{
private:
    void dfs(TreeNod *currNode, string &ansWord, vector<string> &ansVector, int& count)
    {
        if(currNode->isWordComplete && count != 0){
            count--;
            ansVector.push_back(ansWord);
        }else if(count == 0){
            return;
        }
        for(int i = 0; i < 26; i++){
            if(currNode->children[i] != NULL){
                ansWord += (char)(i + 'a');
                dfs(currNode->children[i], ansWord, ansVector, count);
                ansWord.pop_back();
            }
        }
        return;
    }

public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        TreeNod *root = new TreeNod();
        for (auto word : products)
        {
            TreeNod *currNode = root;
            for (auto s : word)
            {
                if (currNode->children[s - 'a'] == NULL)
                {
                    currNode->children[s - 'a'] = new TreeNod();
                }
                currNode = currNode->children[s - 'a'];
            }
            currNode->isWordComplete = true;
        }

        vector<vector<string>> ans;
        string cur = "";
        for (int i = 0; i < searchWord.size(); i++)
        {
            cur += searchWord[i];
            vector<string> tempAns;
            TreeNod *currNode = root;
            bool flag = true;
            for(auto s : cur){
                if(currNode->children[s - 'a'] != NULL){
                    currNode = currNode->children[s - 'a'];
                }else{
                    flag = false;
                    break;
                }
            }
            int maxWords = 3;
            if(flag){
                dfs(currNode, cur, tempAns, maxWords);
            }
            ans.push_back(tempAns);
        }
        return ans;
    }
};