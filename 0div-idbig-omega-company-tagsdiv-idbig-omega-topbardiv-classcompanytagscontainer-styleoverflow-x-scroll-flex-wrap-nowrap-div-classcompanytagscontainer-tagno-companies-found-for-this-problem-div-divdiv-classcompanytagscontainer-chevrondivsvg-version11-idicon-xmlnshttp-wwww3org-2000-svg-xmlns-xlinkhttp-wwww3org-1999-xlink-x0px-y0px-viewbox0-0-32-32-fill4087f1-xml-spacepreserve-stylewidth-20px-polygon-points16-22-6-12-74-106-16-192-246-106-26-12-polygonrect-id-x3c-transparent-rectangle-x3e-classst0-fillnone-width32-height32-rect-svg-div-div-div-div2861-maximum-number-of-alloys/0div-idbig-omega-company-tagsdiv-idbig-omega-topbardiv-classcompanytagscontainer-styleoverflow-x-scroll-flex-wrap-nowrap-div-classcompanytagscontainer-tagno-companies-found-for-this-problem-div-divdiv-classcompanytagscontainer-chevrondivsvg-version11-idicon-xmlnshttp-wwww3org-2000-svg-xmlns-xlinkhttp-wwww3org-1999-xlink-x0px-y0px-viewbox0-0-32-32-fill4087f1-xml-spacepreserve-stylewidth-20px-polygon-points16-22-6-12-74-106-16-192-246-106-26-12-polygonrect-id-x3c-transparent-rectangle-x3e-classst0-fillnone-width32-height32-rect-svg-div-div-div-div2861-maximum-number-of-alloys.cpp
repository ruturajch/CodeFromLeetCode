class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        mN = n;
        mK = k;
        int left = 0;
        int right = 1e9;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (accept(mid, composition, stock, cost, budget)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left-1;
    }
    bool accept(int alloyCnt, vector<vector<int>> composition, vector<int> stock, vector<int> cost, int budget) {
        // Given some amount of alloys, can we produce these alloys within the budget?
        int res = 0;
        for (int i=0; i<mK; i++) {
            long long currBudget = 0;
            for (int j=0; j<mN; j++) {
                long long amt = 1ll * alloyCnt * composition[i][j];
                if (amt > stock[j]) {
                    currBudget += (amt - stock[j]) * cost[j];
                }
            }
            if (currBudget <= budget) {
                return true;
            }
        }
        return false;
    }
private:
    int mN;
    int mK;
};