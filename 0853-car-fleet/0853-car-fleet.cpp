class Solution {
public:
    static bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    if (n == 0) {
        return 0;
    }

    vector<pair<int, int>> dataVector;
    for (int i = 0; i < n; i++) {
        dataVector.push_back(make_pair(position[i], speed[i]));
    }
    sort(dataVector.begin(), dataVector.end(), compare);

    stack<pair<int, int>> ansStack;
    ansStack.push(dataVector[0]);

    for (int i = 1; i < n; i++) {
        double time1 = static_cast<double>(target - ansStack.top().first) / ansStack.top().second;
        double time2 = static_cast<double>(target - dataVector[i].first) / dataVector[i].second;
        
        if (time1 < time2) {
            ansStack.push(dataVector[i]);
        }
    }

    return ansStack.size();
}
};