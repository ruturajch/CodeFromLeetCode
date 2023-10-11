class Solution {
public:
   int diff;
int ans;
void solve(int ind, int tot, vector<int> &toppingCosts, int &target)
{
    int curDiff = abs(tot - target);
    if (ind == toppingCosts.size())
    {
        if (curDiff < diff)
        {
            ans = tot;
            diff = curDiff;
        }
        else if (curDiff == diff)
        {
            ans = min(ans, tot);
        }
        return;
    }

    if (tot > ans and abs(tot - target) > diff)
        return;

    solve(ind + 1, tot, toppingCosts, target);
    solve(ind + 1, tot + toppingCosts[ind], toppingCosts, target);
    solve(ind + 1, tot + 2 * toppingCosts[ind], toppingCosts, target);
}

int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target)
{
    ans = 1e9;
    diff = 1e9;

    for (int i = 0; i < baseCosts.size(); i++)
    {
        solve(0, baseCosts[i], toppingCosts, target);
    }
    return ans;
}
};