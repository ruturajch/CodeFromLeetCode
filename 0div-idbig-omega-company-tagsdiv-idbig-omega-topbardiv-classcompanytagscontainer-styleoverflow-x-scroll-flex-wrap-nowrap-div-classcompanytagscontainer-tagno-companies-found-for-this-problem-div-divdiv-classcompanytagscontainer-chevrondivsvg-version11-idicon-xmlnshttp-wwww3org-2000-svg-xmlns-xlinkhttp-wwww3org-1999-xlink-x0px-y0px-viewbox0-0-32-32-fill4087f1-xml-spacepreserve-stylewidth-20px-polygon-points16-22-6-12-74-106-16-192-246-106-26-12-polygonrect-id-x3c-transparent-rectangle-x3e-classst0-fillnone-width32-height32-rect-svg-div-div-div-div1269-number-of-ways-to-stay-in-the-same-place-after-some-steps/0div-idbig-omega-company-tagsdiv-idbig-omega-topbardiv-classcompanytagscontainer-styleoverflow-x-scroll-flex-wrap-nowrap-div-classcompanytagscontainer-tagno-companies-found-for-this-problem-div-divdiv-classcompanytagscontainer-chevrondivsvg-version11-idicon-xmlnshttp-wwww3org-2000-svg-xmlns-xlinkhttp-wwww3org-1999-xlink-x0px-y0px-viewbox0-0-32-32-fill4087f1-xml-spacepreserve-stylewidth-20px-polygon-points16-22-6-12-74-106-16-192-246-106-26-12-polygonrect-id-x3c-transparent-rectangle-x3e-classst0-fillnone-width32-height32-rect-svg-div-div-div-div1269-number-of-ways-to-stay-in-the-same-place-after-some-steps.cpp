class Solution {
public:
    public:
    int numWays(int steps, int arrLen) {
        // Create a memoization map
        std::unordered_map<long long, int> memo;
        return back(steps, arrLen, 0, memo);
    }

private:
    int back(int steps, int arrLen, int i, std::unordered_map<long long, int>& memo) {
        // Convert parameters to a unique key for memoization
        long long key = (static_cast<long long>(steps) << 32) | (static_cast<long long>(i) & 0xFFFFFFFF);

        // Check if the result is already memoized
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        // Base cases
        if (steps == 0 && i == 0) return 1;
        if (steps == 0 || i < 0 || i >= arrLen) return 0;

        // Recursive cases
        long long result = (static_cast<long long>(back(steps - 1, arrLen, i - 1, memo)) +
                            back(steps - 1, arrLen, i, memo) +
                            back(steps - 1, arrLen, i + 1, memo)) % 1000000007;

        // Memoize the result
        memo[key] = static_cast<int>(result);

        return static_cast<int>(result);
    }
};