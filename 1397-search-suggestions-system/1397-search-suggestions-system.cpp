class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
{
    sort(products.begin(), products.end());
    vector<vector<string>> res;
    string cur = "";
    for (int i = 0; i < searchWord.size(); i++)
    {
        cur += searchWord[i];
        vector<string> temp;
        for (int j = 0; j < products.size(); j++)
        {
            if (products[j].substr(0, i + 1) == cur)
            {
                temp.push_back(products[j]);
            }
            if (temp.size() == 3)
                break;
        }
        res.push_back(temp);
    }
    return res;
}
};