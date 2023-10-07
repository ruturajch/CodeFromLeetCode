class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>>> pq;
        int n = points.size();
        for (int i = 0; i < n; i++)
        {
            double value = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            cout << value << endl;
            pq.push({value, points[i]});
        }
        vector<vector<int>> ansVector;
        while( k != 0){
            ansVector.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ansVector;
    }
};