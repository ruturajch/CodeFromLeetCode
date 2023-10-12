class Solution {
public:
    int minSteps(string s, string t)
    {
        vector<int> shelper(26, 0);
        vector<int> thelper(26, 0);
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            shelper[s[i] - 'a']++;
            thelper[t[i] - 'a']++;
        }
        int carry = 0;
        for (int i = 0; i < 26; i++)
        {
            //cout << shelper[i] << " "<< thelper[i] << endl;
            if (thelper[i] < shelper[i]){
                
                carry += (shelper[i] - thelper[i]);
            }
        }
        return carry;
    }
};