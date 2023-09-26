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
class Trie
{
public:
    TreeNod *root;
    Trie()
    {
        root = new TreeNod();
    }
    void dfs(TreeNod *curNode, int i, string word)
    {
        if (curNode->children[word[i] - 'a'] == NULL)
        {
            curNode->children[word[i] - 'a'] = new TreeNod();
        }
        if (word.size() - 1 == i)
        {
            curNode->children[word[i] - 'a']->isWordComplete = true;
            return;
        }
        else
        {
            dfs(curNode->children[word[i] - 'a'], i + 1, word);
        }
        return;
    }
    void insert(string word)
    {
        TreeNod *currNode = root;
        dfs(currNode, 0, word);
    }

    bool search(string word)
    {
        TreeNod *currNode = root;
        for (char s : word)
        {
            if (currNode->children[s - 'a'] == NULL)
            {
                return false;
            }
            else
                currNode = currNode->children[s - 'a'];
        }
        return currNode->isWordComplete;
    }

    bool startsWith(string prefix)
    {
        TreeNod *currNode = root;
        for (char s : prefix)
        {
            if (currNode->children[s - 'a'] == NULL)
            {
                return false;
            }
            else
                currNode = currNode->children[s - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */