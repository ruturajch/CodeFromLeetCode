class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> umt;
        unordered_map<char, int> ums;

        for (char c : t) {
            umt[c]++;
        }

        int required = umt.size(); // Number of unique characters in t that need to be matched
        int formed = 0; // Number of unique characters in the current window that match the required frequency

        int l = 0, r = 0;
        int min_len = INT_MAX;
        int start = 0;

        while (r < s.size()) {
            char c = s[r];
            ums[c]++;

            if (umt.find(c) != umt.end() && ums[c] == umt[c]) {
                formed++;
            }

            while (l <= r && formed == required) {
                c = s[l];

                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    start = l;
                }

                ums[c]--;
                if (umt.find(c) != umt.end() && ums[c] < umt[c]) {
                    formed--;
                }

                l++;
            }

            r++;
        }

        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};
