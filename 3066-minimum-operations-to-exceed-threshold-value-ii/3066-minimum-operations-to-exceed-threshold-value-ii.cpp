class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            pq.push(nums[i]);
        }
        int ans = 0;
        while(pq.size() >= 2 && pq.top() < k){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            cout << a << " " << b << endl;
            ans++;
            long long tempAns = std::min(a, b) * 2LL + std::max(a, b);
            pq.push(tempAns);
        }
        return ans;
    }
};