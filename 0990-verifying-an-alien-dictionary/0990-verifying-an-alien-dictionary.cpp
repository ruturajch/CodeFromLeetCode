class Solution {
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        unordered_map<char, int> um;
        for (int i = 0; i < 26; i++)
        {
            um[order[i]] = i;
        }
        vector<string> helperVector;

        for (int i = 0; i < words.size(); i++)
        {
            string tempAns = "";
            for (auto s : words[i])
            {
                tempAns += um[s];
            }
            helperVector.push_back(tempAns);
        }
        vector<string> sortedVector = helperVector;
        sort(sortedVector.begin(), sortedVector.end());

        for (int i = 0; i < sortedVector.size(); i++)
        {
            cout << sortedVector[i] << " " << helperVector[i] << endl;
            if (sortedVector[i] != helperVector[i])
                return false;
        }
        return true;
    }
};