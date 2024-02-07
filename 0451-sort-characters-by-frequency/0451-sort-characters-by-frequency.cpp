class Solution {
private:
    static bool check(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first > b.first;
        }
    }

public:
    string frequencySort(string s) {
        unordered_map<char, int> um;
        for (char ch : s) {
            um[ch]++;
        }

        vector<pair<int, char>> vec; // Adjusted the pair type

        for (auto it : um) {
            vec.push_back({it.second, it.first}); // Fix the order of elements here
        }

        sort(vec.begin(), vec.end(), check);

        string result = "";

        for (auto it : vec) { // Iterate over the sorted vector
            cout << string(it.first, it.second) << endl;
            result += string(it.first, it.second);
        }

        return result;
    }
};