class Solution {
private:
    vector<string> possible1(string str) {
        vector<string> ans;
        for (int i = 0; i < 4; i++) {
            int dig = stoi(str.substr(i, 1));
            stringstream ss;
            ss << (dig + 1) % 10;
            if (i == 0) {
                ans.push_back(ss.str() + str.substr(i + 1));
            } else if (i == 3) {
                ans.push_back(str.substr(0, i) + ss.str());
            } else {
                ans.push_back(str.substr(0, i) + ss.str() + str.substr(i + 1));
            }
            stringstream ss1;
            ss1 << ((dig - 1 + 10) % 10);
            if (i == 0) {
                ans.push_back(ss1.str() + str.substr(i + 1));
            } else if (i == 3) {
                ans.push_back(str.substr(0, i) + ss1.str());
            } else {
                ans.push_back(str.substr(0, i) + ss1.str() + str.substr(i + 1));
            }
        }
        return ans;
    }

public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadSet(deadends.begin(), deadends.end());

        if (deadSet.count("0000") || deadSet.count(target)) {
            return -1;
        }

        unordered_set<string> startSet{"0000"};
        unordered_set<string> endSet{target};

        int steps = 0;

        while (!startSet.empty() && !endSet.empty()) {
            unordered_set<string> tempSet;

            for (const string& cur : startSet) {
                if (endSet.count(cur)) {
                    return steps;
                }

                vector<string> nextMoves = possible1(cur);
                for (const string& move : nextMoves) {
                    if (!deadSet.count(move)) {
                        deadSet.insert(move);
                        tempSet.insert(move);
                    }
                }
            }

            steps++;
            startSet.swap(tempSet);
        }

        return -1;
    }
};
